#pragma once
#include "../../Interaction.h"
class CoinCanBeEaten : public Interaction
{
public:
	bool canBeEaten;
	CoinCanBeEaten();
	void interact(const Coin& coin) ;
	void interact(const Player& player) ;
};
