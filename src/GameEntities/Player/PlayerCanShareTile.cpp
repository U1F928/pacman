#include "PlayerCanShareTile.h"
PlayerCanShareTile::PlayerCanShareTile()
:
	canShare(false)
{
}
void PlayerCanShareTile::interact(const Coin& coin)
{
	this->canShare = true;
}
void PlayerCanShareTile::interact(const Player& player)
{
	this->canShare = true;
}
