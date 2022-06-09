#pragma once
class Coin;
class Player;
class Interaction
{
public:
	virtual void interact(const Coin& coin) = 0;
	virtual void interact(const Player& player) = 0;
};
