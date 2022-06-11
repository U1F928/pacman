#pragma once
class Coin;
class PowerPellet;
class Wall;
class Teleport;
class Player;
class RespawnPoint;
class Interaction
{
public:
	virtual void interact(const Coin& coin) = 0;
	virtual void interact(const PowerPellet& powerPellet) = 0;
	virtual void interact(const Wall& wall) = 0;
	virtual void interact(const RespawnPoint& respawnPoint) = 0;
	virtual void interact(const Teleport& teleport) = 0;
	virtual void interact(const Player& player) = 0;
};
