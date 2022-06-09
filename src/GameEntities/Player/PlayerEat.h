#pragma once
#include "../../Interaction.h"
class PlayerEat : public Interaction
{
public:
	PlayerEat(Player& player);
	virtual void interact(const Coin& coin) override;
	virtual void interact(const Player& player) override;
private:
	Player& player;

};
