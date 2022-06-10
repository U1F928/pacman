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
	bool loadParameters();
	bool createEntityFromSymbol(char symbol, int x, int y);
	bool loadEntities();
	std::vector<std::string> fileLines;
	const unsigned int parameterCount = 4;
	int requiredScore;
	int playerSpeedLevel;
	int ghostSpeedLevel;
	int maxSpeedLevel;
	std::shared_ptr<Player> playerEntity = nullptr;
	std::vector<std::shared_ptr<GameEntity>> entities; // not including playerEntity
};

