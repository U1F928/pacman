#include "CoinCanBeEaten.h"
CoinCanBeEaten::CoinCanBeEaten()
:
	canBeEaten(false)
{
}
void CoinCanBeEaten::interact(const Coin& coin) 
{
	this->canBeEaten = false;
}
void CoinCanBeEaten::interact(const Player& player) 
{
	this->canBeEaten = true;
}
