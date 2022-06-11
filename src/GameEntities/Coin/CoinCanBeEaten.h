#pragma once
#include "../../Interaction.h"
class CoinCanBeEaten : public Interaction
{
public:
	bool canBeEaten;
	CoinCanBeEaten();
	void interact(const Coin& coin) override;
	void interact(const PowerPellet& powerPellet) override;
	void interact(const Wall& wall) override;
	void interact(const Teleport& teleport) override;
	void interact(const Player& player) override;
};
