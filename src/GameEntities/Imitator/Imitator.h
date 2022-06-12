#pragma once
#include "../../GameEntity.h"
class GameEntity;
class Interaction;
class Imitator : public GameEntity
{
public:
	Imitator
	(
		char symbol, 
		std::pair<int, int> position, 
		int speedLevel, 
		std::pair<int, int> direction = {1, 0}, 
		bool teleportFlag = false
	);

	Imitator& operator = (const Imitator& imitator);

	Imitator(const Imitator& imitator);

	virtual ~Imitator();

	char getSymbol() const override; 

	std::pair<int, int> getPosition() const override;

	void teleportToPosition(std::pair<int, int> position);

	void acceptInteraction(Interaction& interaction) const override;

	virtual std::shared_ptr<GameEntity> clone() const override;

	virtual std::shared_ptr<GameEntity> update(const GameState& gameState) const override;
protected:
	char symbol;
	std::pair<int, int> position;
	int speedLevel;
	std::pair<int, int> direction;
	bool teleportFlag;

	bool canShareTileWith(const GameEntity& gameEntity) const;

	void shareTileWith(const GameEntity& gameEntity);

	bool updateDirectionByUserInput(char userInput);

	virtual void updatePosition(const GameState& gameState);

	void updateTeleportFlag(const GameState& gameState);

	void interactWithEntities(const GameState& gameState);

	bool wasEaten(const GameState& gameState);

	bool canAccessPosition(const GameState& gameState, std::pair<int, int> position) const;

};
