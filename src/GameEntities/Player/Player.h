#pragma once
#include "../../GameEntity.h"
class GameEntity;
class Interaction;
class Player : public GameEntity
{
public:
	Player
	(
		char symbol, 
		std::pair<int, int> position, 
		int speedLevel, 
		std::pair<int, int> direction = {1, 0}, 
		int lifeCount = 1, 
		int score = 0,
		int ghostEatingTime = 0,
		char ghostEatingSymbol = 'P',
		bool teleportFlag = false
	);

	Player& operator = (const Player& player);

	Player(const Player& player);

	~Player();

	char getSymbol() const override; 

	std::pair<int, int> getPosition() const override;

	int getScore() const;
	
	void setScore(int score);

	int getGhostEatingTime() const;

	void setGhostEatingTime(int time); 

	int getLifeCount() const;

	void teleportToPosition(std::pair<int, int> position);

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
	int ghostEatingTime;
	char ghostEatingSymbol;
	bool teleportFlag;

	bool canShareTileWith(const GameEntity& gameEntity) const;

	void shareTileWith(const GameEntity& gameEntity);

	bool updateDirectionByUserInput(char userInput);

	void updatePosition(const GameState& gameState);

	void updateTeleportFlag(const GameState& gameState);

	void interactWithEntities(const GameState& gameState);

	void updateLifeCount(const GameState& gameState);

	void updateGhostEatingTime(const GameState& gameState);

	bool wasEaten(const GameState& gameState);

	bool canAccessPosition(const GameState& gameState, std::pair<int, int> position) const;

};
