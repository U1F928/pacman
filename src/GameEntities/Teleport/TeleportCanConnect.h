#pragma once
#include "../../Interaction.h"
class TeleportCanConnect : public Interaction
{
public:
	bool canConnect;
	TeleportCanConnect();
	void interact(const Coin& coin) override;
	void interact(const PowerPellet& powerPellet) override;
	void interact(const Wall& wall) override;
	void interact(const RespawnPoint& respawnPoint) override;
	void interact(const Teleport& teleport) override;
	void interact(const Player& player) override;
};
