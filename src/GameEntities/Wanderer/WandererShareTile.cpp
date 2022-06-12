#include "WandererShareTile.h"
#include "Wanderer.h"
#include "../Teleport/Teleport.h"
WandererShareTile::WandererShareTile(Wanderer& wanderer)
:
	wanderer(wanderer)
{
}
void WandererShareTile::interact(const Coin& coin)
{
	// do nothing
}
void WandererShareTile::interact(const PowerPellet& powerPellet)
{
	// do nothing
}
void WandererShareTile::interact(const Wall& wall)
{
	// do nothing
}
void WandererShareTile::interact(const RespawnPoint& respawnPoint)
{
	// do nothing
}
void WandererShareTile::interact(const Teleport& teleport)
{
	this->wanderer.teleportToPosition(teleport.getPositionOfNearestTeleport());
}
void WandererShareTile::interact(const Player& player)
{
	// do nothing
}
void WandererShareTile::interact(const Imitator& imitator)
{
	// do nothing
}
void WandererShareTile::interact(const Wanderer& wanderer)
{
	// do nothing
}
