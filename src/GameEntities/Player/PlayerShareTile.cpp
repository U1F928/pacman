#include "PlayerShareTile.h"
#include "Player.h"
#include "../Teleport/Teleport.h"
PlayerShareTile::PlayerShareTile(Player& player)
:
	player(player)
{
}
void PlayerShareTile::interact(const Coin& coin)
{
	// do nothing
}
void PlayerShareTile::interact(const PowerPellet& powerPellet)
{
	// do nothing
}

void PlayerShareTile::interact(const Wall& wall)
{
	// do nothing
}
void PlayerShareTile::interact(const Teleport& teleport)
{
	// TODO
	this->player.teleportToPosition(teleport.getPositionOfNearestTeleport());
}

void PlayerShareTile::interact(const Player& player)
{
	// do nothing
}
