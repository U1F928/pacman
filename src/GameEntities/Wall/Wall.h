#pragma once
#include "../../GameEntity.h"
class Interaction;
class GameEntity;
class Wall : public GameEntity
{
public:
	Wall(char symbol, std::pair<int, int> position);

	Wall& operator = (const Wall& coin);

	Wall(const Wall& coin);

	~Wall();

	virtual char getSymbol() const override;

	virtual std::pair<int, int> getPosition() const override;

	void acceptInteraction(Interaction& interaction) const override;

	std::shared_ptr<GameEntity> clone() const override;

	std::shared_ptr<GameEntity> update(const GameState& gameState) const override;
private:
	char symbol;
	std::pair<int, int> position;
};
