#include "PlayerShareTile.h"
#include "../Teleport/Teleport.h"
#include "Player.h"

PlayerShareTile::PlayerShareTile(Player& player)
    : player(player)
{
}

void PlayerShareTile::interact(const Coin& coin)
{
    const int coinScore = 1;
    this->player.setScore(this->player.getScore() + coinScore);
}

void PlayerShareTile::interact(const PowerPellet& powerPellet)
{
    const int ghostEatingTimeGain = 30;
    this->player.setGhostEatingTime(this->player.getGhostEatingTime() + ghostEatingTimeGain);
}

void PlayerShareTile::interact(const Wall& wall)
{
    // do nothing
}

void PlayerShareTile::interact(const RespawnPoint& respawnPoint)
{
    // do nothing
}

void PlayerShareTile::interact(const Teleport& teleport)
{
    this->player.teleportToPosition(teleport.getPositionOfNearestTeleport());
}

void PlayerShareTile::interact(const Player& player)
{
    // do nothing
}

void PlayerShareTile::interact(const Imitator& imitator)
{
    // do nothing
}

void PlayerShareTile::interact(const Wanderer& wanderer)
{
    // do nothing
}

void PlayerShareTile::interact(const Mimic& mimic)
{
    // do nothing
}
