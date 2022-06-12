#include "CoinCanBeEaten.h"
CoinCanBeEaten::CoinCanBeEaten()
:
	canBeEaten(false)
{
}
void CoinCanBeEaten::interact(const Wall&) 
{
	this->canBeEaten = false;
}
void CoinCanBeEaten::interact(const RespawnPoint&) 
{
	this->canBeEaten = false;
}
void CoinCanBeEaten::interact(const Teleport&) 
{
	this->canBeEaten = false;
}
void CoinCanBeEaten::interact(const PowerPellet&) 
{
	this->canBeEaten = false;
}
void CoinCanBeEaten::interact(const Coin&) 
{
	this->canBeEaten = false;
}
void CoinCanBeEaten::interact(const Player&) 
{
	this->canBeEaten = true;
}
void CoinCanBeEaten::interact(const Imitator&) 
{
	this->canBeEaten = false;
}
void CoinCanBeEaten::interact(const Wanderer&) 
{
	this->canBeEaten = false;
}
void CoinCanBeEaten::interact(const Mimic&) 
{
	this->canBeEaten = false;
}
