#include "ImitatorCanShareTile.h"
#include "../../Logger.h"
ImitatorCanShareTile::ImitatorCanShareTile()
:
	canShare(false)
{
}
void ImitatorCanShareTile::interact(const Coin&)
{
	this->canShare = true;
}
void ImitatorCanShareTile::interact(const PowerPellet&)
{
	this->canShare = true;
}
void ImitatorCanShareTile::interact(const Wall&)
{
	this->canShare = false;
}
void ImitatorCanShareTile::interact(const RespawnPoint&)
{
	this->canShare = false;
}
void ImitatorCanShareTile::interact(const Teleport&)
{
	this->canShare = true;
}
void ImitatorCanShareTile::interact(const Player&)
{
	this->canShare = true;
}
void ImitatorCanShareTile::interact(const Imitator&)
{
	this->canShare = true;
}
