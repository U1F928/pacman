#pragma once
#include "../../Interaction.h"
class PowerPelletCanBeEaten : public Interaction
{
public:
	bool canBeEaten;
	PowerPelletCanBeEaten();
	void interact(const Coin& coin) override;
	void interact(const PowerPellet& coin) override;
	void interact(const Wall& wall) override;
	void interact(const Player& player) override;
};
