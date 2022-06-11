#include "PowerPelletCanBeEaten.h"
PowerPelletCanBeEaten::PowerPelletCanBeEaten()
:
	canBeEaten(false)
{
}
void PowerPelletCanBeEaten::interact(const Wall&) 
{
	this->canBeEaten = false;
}
void PowerPelletCanBeEaten::interact(const RespawnPoint&)
{
	this->canBeEaten = false;
}
void PowerPelletCanBeEaten::interact(const Teleport&) 
{
	this->canBeEaten = false;
}
void PowerPelletCanBeEaten::interact(const Coin&) 
{
	this->canBeEaten = false;
}
void PowerPelletCanBeEaten::interact(const PowerPellet&) 
{
	this->canBeEaten = false;
}
void PowerPelletCanBeEaten::interact(const Player&) 
{
	this->canBeEaten = true;
}
void PowerPelletCanBeEaten::interact(const Imitator&) 
{
	this->canBeEaten = false;
}
