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
void PlayerCanEat::interact(const PowerPellet& powerPellet)
{
	this->canEat = true;
}
void PlayerCanEat::interact(const Wall& wall)
{
	this->canEat = false;
}
void PlayerCanEat::interact(const Teleport& teleport)
{
	this->canEat = false;
}
void PlayerCanEat::interact(const Player& player)
{
	this->canEat = false;
}
