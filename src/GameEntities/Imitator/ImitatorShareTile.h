#pragma once
#include "../../Interaction.h"
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
private:
	Imitator& imitator;

};
