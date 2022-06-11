#include "Teleport.h"
#include "../../GameEntity.h"
#include "../../Logger.h"
#include "../../Interaction.h"
class Interaction;
Teleport::Teleport(char symbol, std::pair<int, int> position)
:
	symbol(symbol),
	position(position)
{
}

Teleport& Teleport::operator = (const Teleport& teleport)
{
	this->symbol = teleport.symbol;
	this->position= teleport.position;
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
	return updatedTeleport;
}


std::vector<std::pair<int, int>> Teleport::getPositionOfNearestTeleport(const GameState& gameState) const;
