#pragma once
#include "../../Interaction.h"
/**
  * @brief  Visitor class, that tells Teleport whether it can connect to another entity
  */
class TeleportCanConnect : public Interaction
{
public:
	bool canConnect;
	TeleportCanConnect();
	void interact(const Coin&) override;
	void interact(const PowerPellet&) override;
	void interact(const Wall&) override;
	void interact(const RespawnPoint&) override;
	void interact(const Teleport&) override;
	void interact(const Player&) override;
	void interact(const Imitator&) override;
	void interact(const Wanderer&) override;
	void interact(const Mimic&) override;
};
