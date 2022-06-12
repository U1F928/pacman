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
class Interaction
{
public:
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
