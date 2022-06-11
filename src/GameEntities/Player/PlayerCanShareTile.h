#pragma once
#include "../../Interaction.h"
class PlayerCanShareTile : public Interaction
{
public:
	bool canShare;
	PlayerCanShareTile();
	virtual void interact(const Coin& coin) override;
	virtual void interact(const PowerPellet& powerPellet) override;
	virtual void interact(const Wall& wall) override;
	virtual void interact(const RespawnPoint& respawnPoint) override;
	virtual void interact(const Teleport& teleport) override;
	virtual void interact(const Player& player) override;
};
