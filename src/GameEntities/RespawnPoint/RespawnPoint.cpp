#include "RespawnPoint.h"
#include "../../GameEntity.h"
#include "../../Logger.h"
#include "../../Interaction.h"
class Interaction;
RespawnPoint::RespawnPoint(char symbol, std::pair<int, int> position)
:
	symbol(symbol),
	position(position)
{
}

RespawnPoint& RespawnPoint::operator = (const RespawnPoint& wall)
{
	this->symbol = wall.symbol;
	this->position= wall.position;
	return (*this);
}

RespawnPoint::RespawnPoint(const RespawnPoint& wall)
{
	(*this) = wall;
}

RespawnPoint::~RespawnPoint() = default;

char RespawnPoint::getSymbol() const 
{
	return this->symbol;
}

std::pair<int, int> RespawnPoint::getPosition() const 
{
	return this->position;
}

void RespawnPoint::acceptInteraction(Interaction& interaction) const 
{
	interaction.interact(*this);	
}

std::shared_ptr<GameEntity> RespawnPoint::clone() const 
{
	std::shared_ptr<RespawnPoint> clonedRespawnPoint = std::make_shared<RespawnPoint>(*this);
	return clonedRespawnPoint;
}

std::shared_ptr<GameEntity> RespawnPoint::update(const GameState& gameState) const 
{
	std::shared_ptr<RespawnPoint> updatedRespawnPoint = std::make_shared<RespawnPoint>(*this);
	return updatedRespawnPoint;
}

