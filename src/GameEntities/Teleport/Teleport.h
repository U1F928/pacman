#pragma once
#include "../../GameEntity.h"
class Interaction;
class GameEntity;
class Teleport : public GameEntity
{
public:
	Teleport(char symbol, std::pair<int, int> position);

	Teleport& operator = (const Teleport& teleport);

	Teleport(const Teleport& teleport);

	~Teleport();

	virtual char getSymbol() const override;

	virtual std::pair<int, int> getPosition() const override;

	void acceptInteraction(Interaction& interaction) const override;

	std::shared_ptr<GameEntity> clone() const override;

	std::shared_ptr<GameEntity> update(const GameState& gameState) const override;

	std::pair<int, int> getPositionOfNearestTeleport(const GameState& gameState) const;
private:
	char symbol;
	std::pair<int, int> position;

	bool connectibleEntityOnPosition(const GameState& gameState, std::pair<int, int> position) const;
	bool canConnectTo(const GameEntity& gameEntity) const;
};
