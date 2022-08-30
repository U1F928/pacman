#include "PlayerCanBeEaten.h"
#include "Player.h"

PlayerCanBeEaten::PlayerCanBeEaten(Player& player)
    : player(player),
      canBeEaten(false)
{
}

void PlayerCanBeEaten::interact(const Coin&)
{
    this->canBeEaten = false;
}

void PlayerCanBeEaten::interact(const PowerPellet&)
{
    this->canBeEaten = false;
}

void PlayerCanBeEaten::interact(const Wall&)
{
    this->canBeEaten = false;
}

void PlayerCanBeEaten::interact(const RespawnPoint&)
{
    this->canBeEaten = false;
}

void PlayerCanBeEaten::interact(const Teleport&)
{
    this->canBeEaten = false;
}

void PlayerCanBeEaten::interact(const Player&)
{
    this->canBeEaten = false;
}

void PlayerCanBeEaten::interact(const Imitator&)
{
    this->canBeEaten = this->player.getGhostEatingTime() == 0;
}

void PlayerCanBeEaten::interact(const Wanderer&)
{
    this->canBeEaten = this->player.getGhostEatingTime() == 0;
}

void PlayerCanBeEaten::interact(const Mimic&)
{
    this->canBeEaten = this->player.getGhostEatingTime() == 0;
}
