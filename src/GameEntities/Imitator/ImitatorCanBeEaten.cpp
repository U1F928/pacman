#include "ImitatorCanBeEaten.h"
#include "../Player/Player.h"

ImitatorCanBeEaten::ImitatorCanBeEaten()
:
	canBeEaten(false)
{
}
void ImitatorCanBeEaten::interact(const Coin&)
{
	this->canBeEaten = false;
}
void ImitatorCanBeEaten::interact(const PowerPellet&)
{
	this->canBeEaten = false;
}
void ImitatorCanBeEaten::interact(const Wall&)
{
	this->canBeEaten = false;
}
void ImitatorCanBeEaten::interact(const RespawnPoint&)
{
	this->canBeEaten = false;
}
void ImitatorCanBeEaten::interact(const Teleport&)
{
	this->canBeEaten = false;
}
void ImitatorCanBeEaten::interact(const Player& player)
{
	this->canBeEaten = player.getGhostEatingTime() > 0;
}
void ImitatorCanBeEaten::interact(const Imitator&)
{
	this->canBeEaten = false;
}
void ImitatorCanBeEaten::interact(const Wanderer&)
{
	this->canBeEaten = false;
}
