#include "PlayerCanShareTile.h"
#include "../../Logger.h"
PlayerCanShareTile::PlayerCanShareTile()
:
	canShare(false)
{
}
void PlayerCanShareTile::interact(const Coin&)
{
	this->canShare = true;
}
void PlayerCanShareTile::interact(const PowerPellet&)
{
	this->canShare = true;
}
void PlayerCanShareTile::interact(const Wall&)
{
	this->canShare = false;
}
void PlayerCanShareTile::interact(const RespawnPoint&)
{
	this->canShare = false;
}
void PlayerCanShareTile::interact(const Teleport&)
{
	this->canShare = true;
}
void PlayerCanShareTile::interact(const Player&)
{
	this->canShare = true;
}
void PlayerCanShareTile::interact(const Imitator&)
{
	this->canShare = true;
}
