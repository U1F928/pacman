#pragma once
#include "../../Interaction.h"
class PlayerShareTile : public Interaction
{
public:
	PlayerShareTile(Player& player);
	virtual void interact(const Coin& coin) override;
	virtual void interact(const PowerPellet& powerPellet) override;
	virtual void interact(const Wall& wall) override;
	virtual void interact(const Player& player) override;
private:
	Player& player;

};

