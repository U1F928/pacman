#pragma once
class Coin;
class Wall;
class Player;
class PowerPellet;
class Interaction
{
public:
	virtual void interact(const Coin& coin) = 0;
	virtual void interact(const PowerPellet& powerPellet) = 0;
	virtual void interact(const Wall& wall) = 0;
	virtual void interact(const Player& player) = 0;
};
