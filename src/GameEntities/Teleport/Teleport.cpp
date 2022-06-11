#include <queue>
#include <set>
#include <utility>
#include "Teleport.h"
#include "TeleportCanConnect.h"
#include "../../GameEntity.h"
#include "../../Logger.h"
#include "../../Interaction.h"
class Interaction;
Teleport::Teleport(char symbol, std::pair<int, int> position, std::pair<int, int> nearestTeleportPosition)
:
	symbol(symbol),
	position(position),
	nearestTeleportPosition(nearestTeleportPosition)
{
}

Teleport& Teleport::operator = (const Teleport& teleport)
{
	this->symbol = teleport.symbol;
	this->position= teleport.position;
	this->nearestTeleportPosition = teleport.nearestTeleportPosition;
	return (*this);
}

Teleport::Teleport(const Teleport& teleport)
{
	(*this) = teleport;
}

Teleport::~Teleport() = default;

char Teleport::getSymbol() const 
{
	return this->symbol;
}

std::pair<int, int> Teleport::getPosition() const 
{
	return this->position;
}

void Teleport::acceptInteraction(Interaction& interaction) const 
{
	interaction.interact(*this);	
}

std::shared_ptr<GameEntity> Teleport::clone() const 
{
	std::shared_ptr<Teleport> clonedTeleport = std::make_shared<Teleport>(*this);
	return clonedTeleport;
}

std::shared_ptr<GameEntity> Teleport::update(const GameState& gameState) const 
{
	std::shared_ptr<Teleport> updatedTeleport = std::make_shared<Teleport>(*this);
	if(updatedTeleport->nearestTeleportPosition == std::make_pair(-1, -1))
	{
		updatedTeleport->updatePositionOfNearestTeleport(gameState);
		startLog();
		log("updated nearest teleport position\n");
		log("nearest teleport pos: "); log(updatedTeleport->nearestTeleportPosition.first); log(" "); 
		log(updatedTeleport->nearestTeleportPosition.second); log("\n");
		log("this teleport pos: "); log(updatedTeleport->position.first); log(" "); log(updatedTeleport->position.second); log("\n");
	}
	return updatedTeleport;
}
bool Teleport::canConnectTo(const GameEntity& gameEntity) const
{
	TeleportCanConnect teleportCanConnect;
	gameEntity.acceptInteraction(teleportCanConnect);
	return teleportCanConnect.canConnect;
}
bool Teleport::connectibleEntityOnPosition(const GameState& gameState, std::pair<int, int> position) const
{
	std::vector<std::shared_ptr<GameEntity>> entities = gameState.getEntitiesByPosition(position);
	for(std::shared_ptr<GameEntity> entity : entities)
	{
		if(this->canConnectTo(*entity))
		{
			return true;
		}
	}
	return false;
}
void Teleport::updatePositionOfNearestTeleport(const GameState& gameState)
{
	std::queue<std::pair<int, int>> positions;
	std::set<std::pair<int, int>> visitedPositions;
	positions.push(this->position);
	while(!positions.empty())
	{
		std::pair<int, int> currentPosition = positions.front();	
		positions.pop();
		if(this->connectibleEntityOnPosition(gameState, currentPosition) && currentPosition != this->position)
		{
			this->nearestTeleportPosition = currentPosition;
			return;
		}
		std::vector<std::pair<int, int>> neighborPositions = gameState.getNeighborPositions(currentPosition);
		for(std::pair<int, int> neighborPosition : neighborPositions)
		{
			if(visitedPositions.find(neighborPosition) == visitedPositions.end())
			{
				positions.push(neighborPosition);
				visitedPositions.insert(neighborPosition);
			}
		}
	}
	// if no other teleport entity found, return it's own position
	this->nearestTeleportPosition = this->position;
}

std::pair<int, int> Teleport::getPositionOfNearestTeleport() const
{
	return this->nearestTeleportPosition;
}
