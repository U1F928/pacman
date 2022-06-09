#pragma once
#include <utility>
#include <memory>
#include "GameState.h"
class GameState;
class Interaction;
class GameEntity
{
public:
	
	virtual char getSymbol() const = 0;

	virtual std::pair<int, int> getPosition() const = 0;

	virtual void acceptInteraction(Interaction& interaction) const = 0;

	//virtual bool canEat(const GameEntity& gameEntity) const = 0;

	//virtual void eat(const GameEntity& gameEntity) = 0;

	//virtual bool canShareTileWith(const GameEntity& gameEntity) const = 0;

	//virtual void shareTileWith(const GameEntity& gameEntity) = 0;

	virtual std::shared_ptr<GameEntity> clone() const = 0;

	virtual std::shared_ptr<GameEntity> update(const GameState& gameState) const = 0;

};
