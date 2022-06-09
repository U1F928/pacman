#include "PlayerCanEat.h"

PlayerCanEat::PlayerCanEat()
:
	canEat(false)
{
}
void PlayerCanEat::interact(const Coin& coin)
{
	this->canEat = true;
}
void PlayerCanEat::interact(const Player& player)
{
	this->canEat = false;
}
