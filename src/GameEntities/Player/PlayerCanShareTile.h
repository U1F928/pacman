#pragma once
#include "../../Interaction.h"
class PlayerCanShareTile : public Interaction
{
public:
	bool canShare;
	PlayerCanShareTile();
	virtual void interact(const Coin& coin) override;
	virtual void interact(const Player& player) override;
};
