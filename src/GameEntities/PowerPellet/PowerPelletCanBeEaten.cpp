#include "PowerPelletCanBeEaten.h"
PowerPelletCanBeEaten::PowerPelletCanBeEaten()
:
	canBeEaten(false)
{
}
void PowerPelletCanBeEaten::interact(const Wall& wall) 
{
	this->canBeEaten = false;
}
void PowerPelletCanBeEaten::interact(const Coin& coin) 
{
	this->canBeEaten = false;
}
void PowerPelletCanBeEaten::interact(const PowerPellet& powerPellet) 
{
	this->canBeEaten = false;
}
void PowerPelletCanBeEaten::interact(const Player& player) 
{
	this->canBeEaten = true;
}
