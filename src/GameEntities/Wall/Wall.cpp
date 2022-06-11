#include "Wall.h"
#include "../../GameEntity.h"
#include "../../Logger.h"
#include "../../Interaction.h"
class Interaction;
Wall::Wall(char symbol, std::pair<int, int> position)
:
	symbol(symbol),
	position(position)
{
}

Wall& Wall::operator = (const Wall& wall)
{
	this->symbol = wall.symbol;
	this->position= wall.position;
	return (*this);
}

Wall::Wall(const Wall& wall)
{
	(*this) = wall;
}

Wall::~Wall() = default;

char Wall::getSymbol() const 
{
	return this->symbol;
}

std::pair<int, int> Wall::getPosition() const 
{
	return this->position;
}

void Wall::acceptInteraction(Interaction& interaction) const 
{
	interaction.interact(*this);	
}

std::shared_ptr<GameEntity> Wall::clone() const 
{
	std::shared_ptr<Wall> clonedWall = std::make_shared<Wall>(*this);
	return clonedWall;
}

std::shared_ptr<GameEntity> Wall::update(const GameState& gameState) const 
{
	std::shared_ptr<Wall> updatedWall = std::make_shared<Wall>(*this);
	return updatedWall;
}

