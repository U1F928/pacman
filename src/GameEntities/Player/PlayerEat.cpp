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
void PlayerEat::interact(const PowerPellet& powerPellet)
{
	const int ghostEatingTimeGain= 30;
	this->player.setGhostEatingTime(this->player.getGhostEatingTime() + ghostEatingTimeGain);
}
void PlayerEat::interact(const Wall& wall)
{
	// do nothing
}
void PlayerEat::interact(const Teleport& teleport)
{
	// TODO
	// change players position 
}
void PlayerEat::interact(const Player& player)
{
	// do nothing
}
