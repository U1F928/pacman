#pragma once
#include "../../Interaction.h"
class PlayerCanBeEaten : public Interaction
{
public:
	bool canBeEaten;
	PlayerCanBeEaten();
	virtual void interact(const Coin& coin) override;
	virtual void interact(const Player& player) override;
};
