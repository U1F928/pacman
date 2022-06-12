#pragma once
#include <utility>
#include <memory>
#include "GameState.h"
class GameState;
class Interaction;

/**
 * @brief Abstract class representing all game entities
 * 
 */
class GameEntity
{
public:
    /**
     * @brief Get the symbol that this entity will be represented as on screen
     * @return the symbol 
     */
	virtual char getSymbol() const = 0;
    /**
     * @brief Get position of this entity
     * @return the position
     */
	virtual std::pair<int, int> getPosition() const = 0;
    /**
     * @brief Accept visitor/double dispatch
     */
	virtual void acceptInteraction(Interaction& interaction) const = 0;
    /**
     * @brief Get deep copy of this entity
     * @return the clone
     */
	virtual std::shared_ptr<GameEntity> clone() const = 0;
    /**
     * @brief Get updated deep copy of this entity
     * @return the updated version of this entity
     */
	virtual std::shared_ptr<GameEntity> update(const GameState& gameState) const = 0;

};
