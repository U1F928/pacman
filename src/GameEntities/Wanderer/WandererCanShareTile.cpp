#include "WandererCanShareTile.h"
#include "../../Logger.h"
WandererCanShareTile::WandererCanShareTile()
:
	canShare(false)
{
}
void WandererCanShareTile::interact(const Coin&)
{
	this->canShare = true;
}
void WandererCanShareTile::interact(const PowerPellet&)
{
	this->canShare = true;
}
void WandererCanShareTile::interact(const Wall&)
{
	this->canShare = false;
}
void WandererCanShareTile::interact(const RespawnPoint&)
{
	this->canShare = false;
}
void WandererCanShareTile::interact(const Teleport&)
{
	this->canShare = true;
}
void WandererCanShareTile::interact(const Player&)
{
	this->canShare = true;
}
void WandererCanShareTile::interact(const Imitator&)
{
	this->canShare = true;
}
void WandererCanShareTile::interact(const Wanderer&)
{
	this->canShare = true;
}
