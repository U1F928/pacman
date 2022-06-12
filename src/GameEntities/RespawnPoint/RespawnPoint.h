#pragma once
#include "../../GameEntity.h"
class Interaction;
class GameEntity;
class RespawnPoint : public GameEntity
{
public:
	RespawnPoint(char symbol, std::pair<int, int> position);

	RespawnPoint& operator = (const RespawnPoint& wall);

	RespawnPoint(const RespawnPoint& wall);

	~RespawnPoint();

	virtual char getSymbol() const override;

	virtual std::pair<int, int> getPosition() const override;

	virtual std::pair<int, int> getDirection() const override;

	void acceptInteraction(Interaction& interaction) const override;

	std::shared_ptr<GameEntity> clone() const override;

	std::shared_ptr<GameEntity> update(const GameState& gameState) const override;
private:
	char symbol;
	std::pair<int, int> position;
};
