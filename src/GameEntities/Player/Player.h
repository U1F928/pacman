#pragma once
#include "../../GameEntity.h"
class GameEntity;
class Interaction;
class Player : public GameEntity
{
public:
	Player(char symbol, std::pair<int, int> position, int speedLevel, std::pair<int, int> direction, int lifeCount, int Score);

	Player& operator = (const Player& player);

	Player(const Player& player);

	~Player();

	char getSymbol() const override; 

	std::pair<int, int> getPosition() const override;

	int getScore() const;

	int getLifeCount() const;

	void acceptInteraction(Interaction& interaction) const override;

	std::shared_ptr<Player> clonePlayer() const;

	std::shared_ptr<GameEntity> clone() const override;

	std::shared_ptr<Player> updatePlayer(const GameState& gameState) const;

	std::shared_ptr<GameEntity> update(const GameState& gameState) const override;
private:
	char symbol;
	std::pair<int, int> position;
	int speedLevel;
	std::pair<int, int> direction;
	int lifeCount;

	int score;

	bool canEat(const GameEntity& gameEntity) const;

	void eat(const GameEntity& gameEntity);

	bool canShareTileWith(const GameEntity& gameEntity) const;

	void shareTileWith(const GameEntity& gameEntity);

	bool updateDirectionByUserInput(char userInput);

	void updatePosition(const GameState& gameState);

	void updateScore(const GameState& gameState);

	void updateLifeCount(const GameState& gameState);

	bool wasEaten(const GameState& gameState);

	bool canAccessPosition(const GameState& gameState, std::pair<int, int> position) const;


};
