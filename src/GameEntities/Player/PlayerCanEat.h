#pragma once
#include "../../Interaction.h"
class PlayerCanEat : public Interaction
{
public:
	bool canEat;
	PlayerCanEat();
	virtual void interact(const Coin& coin) override;
	virtual void interact(const PowerPellet& powerPellet) override;
	virtual void interact(const Wall& wall) override;
	virtual void interact(const Player& player) override;
};
