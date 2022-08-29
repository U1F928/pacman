#pragma once
class Coin;
class PowerPellet;
class Wall;
class Teleport;
class Player;
class RespawnPoint;
class Imitator;
class Wanderer;
class Mimic;
/**
 * @brief Abstract visitor class that's passed into GameEntity.acceptInteraction(*)
 * 
 */
class Interaction
{
public:
    /**
     * @brief Interact with a Coin entity via double dispatch
	 * @param Coin, coin entity
     */
	virtual void interact(const Coin&) = 0;
	virtual void interact(const PowerPellet&) = 0;
	virtual void interact(const Wall&) = 0;
	virtual void interact(const RespawnPoint&) = 0;
	virtual void interact(const Teleport&) = 0;
	virtual void interact(const Player&) = 0;
	virtual void interact(const Imitator&) = 0;
	virtual void interact(const Wanderer&) = 0;
	virtual void interact(const Mimic&) = 0;
};
