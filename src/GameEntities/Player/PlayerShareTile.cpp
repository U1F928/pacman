#include "PlayerShareTile.h"
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
	// TELEPORT PLAYER
}

void PlayerShareTile::interact(const Player& player)
{
	// do nothing
}
