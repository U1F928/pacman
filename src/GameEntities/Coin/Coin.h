#pragma once
#include "../../GameEntity.h"
class Interaction;
class GameEntity;
class Coin : public GameEntity
{
public:
	Coin(char symbol, std::pair<int, int> position);

	Coin& operator = (const Coin& coin);

	Coin(const Coin& coin);

	~Coin();

	virtual char getSymbol() const override;

	virtual std::pair<int, int> getPosition() const override;

	virtual std::pair<int, int> getDirection() const override;

	void acceptInteraction(Interaction& interaction) const override;

	std::shared_ptr<GameEntity> clone() const override;

	std::shared_ptr<GameEntity> update(const GameState& gameState) const override;
private:
	char symbol;
	std::pair<int, int> position;

	bool wasEaten(const GameState& gameState);
};
