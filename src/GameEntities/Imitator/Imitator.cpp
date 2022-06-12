#include <map>
#include <set>
#include <queue>
#include "../../GameEntity.h"
#include "Imitator.h"
#include "ImitatorShareTile.h"
#include "ImitatorCanShareTile.h"
#include "ImitatorCanBeEaten.h"
#include "ImitatorCanBeRespawned.h"
#include "../../Logger.h"
class Interaction;
Imitator::Imitator
(
	char symbol, 
	std::pair<int, int> position, 
	int speedLevel, 
	std::pair<int, int> direction,
	bool teleportFlag
)
:
	symbol(symbol),
	position(position),
	speedLevel(speedLevel),
	direction(direction), 
	teleportFlag(teleportFlag)
{
}

Imitator& Imitator::operator = (const Imitator& imitator)
{
	this->symbol = imitator.symbol;
	this->speedLevel= imitator.speedLevel;
	this->position = imitator.position;
	this->direction = imitator.direction;
	this->teleportFlag = imitator.teleportFlag;
	return (*this);
}

Imitator::Imitator(const Imitator& imitator)
{
	(*this) = imitator;
}
Imitator::~Imitator() = default;

char Imitator::getSymbol() const
{
	return this->symbol;
}
std::pair<int, int> Imitator::getPosition() const
{
	return this->position;
}
void Imitator::teleportToPosition(std::pair<int, int> position)
{
	startLog();
	if(!this->teleportFlag)
	{
		this->position = position;
		this->teleportFlag = true;
	}
}
void Imitator::acceptInteraction(Interaction& interaction) const 
{
	interaction.interact(*this);	
}

bool Imitator::canShareTileWith(const GameEntity& gameEntity)  const
{
	ImitatorCanShareTile imitatorCanShareTile;
	gameEntity.acceptInteraction(imitatorCanShareTile);
	return imitatorCanShareTile.canShare;
}
void Imitator::shareTileWith(const GameEntity& gameEntity) 
{
	ImitatorShareTile imitatorShareTile(*this);	
	gameEntity.acceptInteraction(imitatorShareTile);
}
std::shared_ptr<GameEntity> Imitator::clone() const
{
	std::shared_ptr<Imitator> clonedImitator = std::make_shared<Imitator>(*this);
	return clonedImitator;
}
std::shared_ptr<GameEntity> Imitator::update(const GameState& gameState) const
{
	std::shared_ptr<Imitator> updatedImitator = std::make_shared<Imitator>(*this);
	if(updatedImitator->wasEaten(gameState))
	{
		updatedImitator->respawn(gameState);
	}
	updatedImitator->interactWithEntities(gameState);
	updatedImitator->updateTeleportFlag(gameState);
	updatedImitator->updatePosition(gameState);
	updatedImitator->updateDirectionByUserInput(gameState.getUserInput());
	return updatedImitator;
}
bool Imitator::updateDirectionByUserInput(char userInput)
{
	std::map<char, std::pair<int, int>> directionByUserInput =
	{
		{'k', {-1,  0}},
		{'h', { 0, -1}},
		{'l', { 0, +1}},
		{'j', {+1,  0}}
	};
	if(directionByUserInput.find(userInput) == directionByUserInput.end())
	{
		return false;
	}
	this->direction = directionByUserInput[userInput];
	return true;
}

void Imitator::updatePosition(const GameState& gameState)
{
	if(this->speedLevel < gameState.getSpeedLevel())
	{
		return;
	}
	int updatedPositionFirst = this->position.first + this->direction.first;
	int updatedPositionSecond= this->position.second + this->direction.second;
	std::pair<int, int> updatedPosition = {updatedPositionFirst, updatedPositionSecond};
	if(this->canAccessPosition(gameState, updatedPosition))
	{
		startLog();
		this->position = updatedPosition;
	}
}
void Imitator::updateTeleportFlag(const GameState& gameState)
{
	if(this->speedLevel < gameState.getSpeedLevel())
	{
		return;
	}
	this->teleportFlag = false;
}
void Imitator::interactWithEntities(const GameState& gameState)
{
	std::vector<std::shared_ptr<GameEntity>> entitiesOnSameTile = gameState.getEntitiesByPosition(this->position);
	for(std::shared_ptr<GameEntity> entity : entitiesOnSameTile)
	{
		this->shareTileWith(*entity);
	}
}
bool Imitator::wasEaten(const GameState& gameState)
{
	std::vector<std::shared_ptr<GameEntity>> entitiesOnSameTile = gameState.getEntitiesByPosition(this->position);
	for(std::shared_ptr<GameEntity> entity : entitiesOnSameTile)
	{
		ImitatorCanBeEaten imitatorCanBeEaten;
		entity->acceptInteraction(imitatorCanBeEaten);
		if(imitatorCanBeEaten.canBeEaten)
		{
			return true;
		}
	}
	return false;
}
bool Imitator::canAccessPosition(const GameState& gameState, std::pair<int, int> position) const
{
	std::vector<std::shared_ptr<GameEntity>> entitiesOnSameTile = gameState.getEntitiesByPosition(position);
	if(!gameState.validPosition(position))
	{
		return false;
	}
	for(std::shared_ptr<GameEntity> entity : entitiesOnSameTile)
	{
		if(!this->canShareTileWith(*entity))
		{
			return false;
		}
	}
	return true;
}

bool Imitator::canBeRespawnedBy(const GameEntity& gameEntity)
{
	ImitatorCanBeRespawned imitatorCanBeRespawned;
	gameEntity.acceptInteraction(imitatorCanBeRespawned);
	return imitatorCanBeRespawned.canBeRespawned;
}

bool Imitator::canBeRespawnedOnPosition(const GameState& gameState, std::pair<int, int> position)
{
	std::vector<std::shared_ptr<GameEntity>> entities = gameState.getEntitiesByPosition(position);
	for(std::shared_ptr<GameEntity> entity : entities)
	{
		if(this->canBeRespawnedBy(*entity))
		{
			return true;
		}
	}
	return false;
}

void Imitator::respawn(const GameState& gameState)
{
	std::queue<std::pair<int, int>> positions;
	std::set<std::pair<int, int>> visitedPositions;
	positions.push(this->position);
	while(!positions.empty())
	{
		std::pair<int, int> currentPosition = positions.front();	
		positions.pop();
		if(this->canBeRespawnedOnPosition(gameState, currentPosition)) 
		{
			this->position= currentPosition;
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
}
