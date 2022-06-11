#pragma once
#include "../../Interaction.h"
class PlayerEat : public Interaction
{
public:
	PlayerEat(Player& player);
	virtual void interact(const Coin& coin) override;
	virtual void interact(const PowerPellet& powerPellet) override;
	virtual void interact(const Wall& wall) override;
	virtual void interact(const Player& player) override;
private:
	Player& player;

};
