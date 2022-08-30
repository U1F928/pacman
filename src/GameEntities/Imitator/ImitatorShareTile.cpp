#include "ImitatorShareTile.h"
#include "../Teleport/Teleport.h"
#include "Imitator.h"

ImitatorShareTile::ImitatorShareTile(Imitator& imitator)
    : imitator(imitator)
{
}

void ImitatorShareTile::interact(const Coin& coin)
{
    // do nothing
}

void ImitatorShareTile::interact(const PowerPellet& powerPellet)
{
    // do nothing
}

void ImitatorShareTile::interact(const Wall& wall)
{
    // do nothing
}

void ImitatorShareTile::interact(const RespawnPoint& respawnPoint)
{
    // do nothing
}

void ImitatorShareTile::interact(const Teleport& teleport)
{
    this->imitator.teleportToPosition(teleport.getPositionOfNearestTeleport());
}

void ImitatorShareTile::interact(const Player& player)
{
    // do nothing
}

void ImitatorShareTile::interact(const Imitator& imitator)
{
    // do nothing
}

void ImitatorShareTile::interact(const Wanderer& wanderer)
{
    // do nothing
}

void ImitatorShareTile::interact(const Mimic& mimic)
{
    // do nothing
}
