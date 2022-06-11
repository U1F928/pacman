#pragma once
#include <memory>
#include <utility>
#include <vector>
class Player;
class GameEntity;
class GameState
{
public:
	GameState();
	GameState& operator = (const GameState& gameState);
	GameState(const GameState& gameState);
	~GameState();
	void setHeight(int height);
	void setWidth(int width);
	int getHeight() const;
	int getWidth() const;
	void setMaxSpeedLevel(int speedLevel);
	void setSpeedLevel(int speedLevel);
	int getSpeedLevel() const;
	void insertUserInput(char userInput);
	void insertPlayer(std::shared_ptr<Player> playerEntity);
	void insertEntity(std::shared_ptr<GameEntity> gameEntity);
	void insertRequiredScoreToWin(int score);

	char getUserInput() const;
	int getPlayerScore() const;
	int getPlayerLifeCount() const;
	int getRequiredScore() const;
	bool playerLost() const;
	bool playerWon() const;
	bool validPosition(std::pair<int, int> position) const;
	std::vector<std::pair<int, int>> getNeighborPositions(std::pair<int, int> position) const;
	std::vector<std::shared_ptr<GameEntity>> getEntitiesByPosition(std::pair<int, int> position) const;
	std::vector<std::shared_ptr<GameEntity>> getAllEntities() const;
	GameState update() const;
private:
	int speedLevel;
	int maxSpeedLevel;
	int requiredScore;
	char userInput;
	int height;
	int width;
	std::shared_ptr<Player> playerEntity; 
	std::vector<std::shared_ptr<GameEntity>> entities; // playerEntity included
};
