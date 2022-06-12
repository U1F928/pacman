#pragma once
#include "../../Interaction.h"
/**
  * @brief  Visitor class, that tells Imitator whether it can share tile with another entity
  */
class ImitatorShareTile : public Interaction
{
public:
	ImitatorShareTile(Imitator&);
	virtual void interact(const Coin&) override;
	virtual void interact(const PowerPellet&) override;
	virtual void interact(const Wall&) override;
	virtual void interact(const RespawnPoint&) override;
	virtual void interact(const Teleport&) override;
	virtual void interact(const Player&) override;
	virtual void interact(const Imitator&) override;
	virtual void interact(const Wanderer&) override;
	virtual void interact(const Mimic&) override;
private:
	Imitator& imitator;

};

