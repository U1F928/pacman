#include "PlayerEat.h"
PlayerEat::PlayerEat(Player& player)
:
	player(player)
{
}
void PlayerEat::interact(const Coin& coin)
{
	// do nothing
}
void PlayerEat::interact(const Player& player)
{
	// do nothing
}
