#pragma once
#include <utility>
#include <memory>
#include "GameState.h"
class GameState;
class Interaction;
/**
 * @brief Class representing all game entities
 * 
 */

class GameEntity
{
public:
	
	virtual char getSymbol() const = 0;

	virtual std::pair<int, int> getPosition() const = 0;

	virtual void acceptInteraction(Interaction& interaction) const = 0;

	virtual std::shared_ptr<GameEntity> clone() const = 0;

	virtual std::shared_ptr<GameEntity> update(const GameState& gameState) const = 0;

};
