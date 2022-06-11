#include "PowerPellet.h"
#include "../../GameEntity.h"
#include "PowerPelletCanBeEaten.h"
#include "../../Logger.h"
class Interaction;
PowerPellet::PowerPellet(char symbol, std::pair<int, int> position)
:
	symbol(symbol),
	position(position)
{
}

PowerPellet& PowerPellet::operator = (const PowerPellet& powerPellet)
{
	this->symbol = powerPellet.symbol;
	this->position= powerPellet.position;
	return (*this);
}

PowerPellet::PowerPellet(const PowerPellet& powerPellet)
{
	(*this) = powerPellet;
}

PowerPellet::~PowerPellet() = default;

char PowerPellet::getSymbol() const 
{
	return this->symbol;
}

std::pair<int, int> PowerPellet::getPosition() const 
{
	return this->position;
}

void PowerPellet::acceptInteraction(Interaction& interaction) const 
{
	interaction.interact(*this);	
}

std::shared_ptr<GameEntity> PowerPellet::clone() const 
{
	std::shared_ptr<PowerPellet> clonedPowerPellet = std::make_shared<PowerPellet>(*this);
	return clonedPowerPellet;
}

std::shared_ptr<GameEntity> PowerPellet::update(const GameState& gameState) const 
{
	std::shared_ptr<PowerPellet> updatedPowerPellet = std::make_shared<PowerPellet>(*this);
	if(updatedPowerPellet->wasEaten(gameState))
	{
		return nullptr;
	}
	return updatedPowerPellet;
}
bool PowerPellet::wasEaten(const GameState& gameState)
{
	std::vector<std::shared_ptr<GameEntity>> entitiesOnSameTile = gameState.getEntitiesByPosition(this->position);
	for(std::shared_ptr<GameEntity> entity : entitiesOnSameTile)
	{
		PowerPelletCanBeEaten powerPelletCanBeEaten;
		entity->acceptInteraction(powerPelletCanBeEaten);
		if(powerPelletCanBeEaten.canBeEaten)
		{
			return true;
		}
	}
	return false;
}
