#include "Coin.h"
#include "../../GameEntity.h"
#include "CoinCanBeEaten.h"
#include "../../Logger.h"
class Interaction;
Coin::Coin(char symbol, std::pair<int, int> position)
:
	symbol(symbol),
	position(position)
{
}

Coin& Coin::operator = (const Coin& coin)
{
	this->symbol = coin.symbol;
	this->position= coin.position;
	return (*this);
}

Coin::Coin(const Coin& coin)
{
	(*this) = coin;
}

Coin::~Coin() = default;

char Coin::getSymbol() const 
{
	return this->symbol;
}

std::pair<int, int> Coin::getPosition() const 
{
	return this->position;
}

void Coin::acceptInteraction(Interaction& interaction) const 
{
	interaction.interact(*this);	
}

std::shared_ptr<GameEntity> Coin::clone() const 
{
	std::shared_ptr<Coin> clonedCoin = std::make_shared<Coin>(*this);
	return clonedCoin;
}

std::shared_ptr<GameEntity> Coin::update(const GameState& gameState) const 
{
	std::shared_ptr<Coin> updatedCoin = std::make_shared<Coin>(*this);
	if(updatedCoin->wasEaten(gameState))
	{
		return nullptr;
	}
	return updatedCoin;
}
bool Coin::wasEaten(const GameState& gameState)
{
	std::vector<std::shared_ptr<GameEntity>> entitiesOnSameTile = gameState.getEntitiesByPosition(this->position);
	for(std::shared_ptr<GameEntity> entity : entitiesOnSameTile)
	{
		CoinCanBeEaten coinCanBeEaten;
		entity->acceptInteraction(coinCanBeEaten);
		if(coinCanBeEaten.canBeEaten)
		{
			return true;
		}
	}
	return false;
}
