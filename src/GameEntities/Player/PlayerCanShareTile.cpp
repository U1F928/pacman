#include "PlayerCanShareTile.h"
#include "../../Logger.h"
PlayerCanShareTile::PlayerCanShareTile()
:
	canShare(false)
{
}
void PlayerCanShareTile::interact(const Coin& coin)
{
	this->canShare = true;
}
void PlayerCanShareTile::interact(const PowerPellet& powerPellet)
{
	this->canShare = true;
}
void PlayerCanShareTile::interact(const Wall& wall)
{
	this->canShare = false;
}
void PlayerCanShareTile::interact(const RespawnPoint& respawnPoint)
{
	this->canShare = false;
}
void PlayerCanShareTile::interact(const Teleport& teleport)
{
	this->canShare = true;
}
void PlayerCanShareTile::interact(const Player& player)
{
	this->canShare = true;
}
