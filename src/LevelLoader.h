#pragma once
#include <memory>
#include <vector>
#include "GameState.h"
#include "GameEntity.h"
class LevelLoader
{
public:
	bool loadFromFile(std::string pathToFile);
	void loadIntoGameState(GameState& gameState);
private:
	bool loadFile(std::string pathToFile);
	bool loadRequiredScore();
	bool loadPlayerSpeedLevel();
	bool loadGhostSpeedLevel();
	bool loadEntities();
	std::vector<std::string> fileLines;
	int requiredScore;
	int playerSpeedLevel;
	int ghostSpeedLevel;
	std::shared_ptr<Player> playerEntity;
	std::vector<std::shared_ptr<GameEntity>> entities; // not including playerEntity
};

