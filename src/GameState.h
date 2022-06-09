#pragma once
#include <memory>
#include <vector>
class Player;
class GameEntity;
class GameState
{
public:
	GameState();
	GameState(const GameState& gameState);
	~GameState();

	void setSpeedLevel(int speedLevel);
	int getSpeedLevel() const;
	void insertUserInput(char userInput);
	void insertPlayer(std::shared_ptr<Player> playerEntity);
	void insertEntity(std::shared_ptr<GameEntity> gameEntity);
	void insertRequiredScoreToWin(int score);

	char getUserInput() const;
	int getPlayerScore() const;
	int getPlayerLifeCount() const;
	bool playerLost();
	bool playerWon();

	std::vector<std::shared_ptr<GameEntity>> getEntitiesByPosition(std::pair<int, int> position) const;
	std::vector<std::shared_ptr<GameEntity>> getAllEntities() const;
	GameState update() const;
private:
	int speedLevel;
	int requiredScore;
	char userInput;
	std::shared_ptr<Player> playerEntity; 
	std::vector<std::shared_ptr<GameEntity>> entities; // playerEntity included
};
