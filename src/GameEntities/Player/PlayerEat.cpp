#include "PlayerEat.h"
#include "Player.h"
PlayerEat::PlayerEat(Player& player)
:
	player(player)
{
}
void PlayerEat::interact(const Coin& coin)
{
	const int coinScore = 1;
	this->player.setScore(this->player.getScore() + coinScore);
}
void PlayerEat::interact(const Player& player)
{
	// do nothing
}
