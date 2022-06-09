#include "PlayerCanBeEaten.h"

PlayerCanBeEaten::PlayerCanBeEaten()
:
	canBeEaten(false)
{
}
void PlayerCanBeEaten::interact(const Coin& coin)
{
	this->canBeEaten = false;
}
void PlayerCanBeEaten::interact(const Player& player)
{
	this->canBeEaten = false;
}
