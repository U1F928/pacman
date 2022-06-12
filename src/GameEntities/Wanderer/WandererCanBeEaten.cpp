#include "WandererCanBeEaten.h"
#include "../Player/Player.h"

WandererCanBeEaten::WandererCanBeEaten()
:
	canBeEaten(false)
{
}
void WandererCanBeEaten::interact(const Coin&)
{
	this->canBeEaten = false;
}
void WandererCanBeEaten::interact(const PowerPellet&)
{
	this->canBeEaten = false;
}
void WandererCanBeEaten::interact(const Wall&)
{
	this->canBeEaten = false;
}
void WandererCanBeEaten::interact(const RespawnPoint&)
{
	this->canBeEaten = false;
}
void WandererCanBeEaten::interact(const Teleport&)
{
	this->canBeEaten = false;
}
void WandererCanBeEaten::interact(const Player& player)
{
	this->canBeEaten = player.getGhostEatingTime() > 0;
}
void WandererCanBeEaten::interact(const Imitator&)
{
	this->canBeEaten = false;
}
void WandererCanBeEaten::interact(const Wanderer&)
{
	this->canBeEaten = false;
}
