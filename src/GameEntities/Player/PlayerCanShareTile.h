#pragma once
#include "../../Interaction.h"
/**
  * @brief  Visitor class, that tells Player whether it can share tile with another entity
  */
class PlayerCanShareTile : public Interaction
{
public:
	bool canShare;
	PlayerCanShareTile();
	virtual void interact(const Coin&) override;
	virtual void interact(const PowerPellet&) override;
	virtual void interact(const Wall&) override;
	virtual void interact(const RespawnPoint&) override;
	virtual void interact(const Teleport&) override;
	virtual void interact(const Player&) override;
	virtual void interact(const Imitator&) override;
	virtual void interact(const Wanderer&) override;
	virtual void interact(const Mimic&) override;
};
