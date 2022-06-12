#pragma once
#include <memory>
#include <vector>
#include "GameState.h"
#include "GameEntity.h"
class LevelLoader
{
public:
	bool loadFromFile();
	void loadIntoGameState(GameState& gameState);
private:
	std::string pathToFile;
	int requiredScore;
	int playerSpeedLevel;
	int ghostSpeedLevel;
	int maxSpeedLevel;
	const unsigned int parameterCount = 4;
	std::shared_ptr<Player> playerEntity = nullptr;
	bool addedRespawnPoint = false;
	std::vector<std::string> fileLines;
	std::vector<std::shared_ptr<GameEntity>> entities; // not including playerEntity

	bool getPathToFileFromUser();
	bool loadFile(std::string pathToFile);
	bool loadParameters();
	bool createEntityFromSymbol(char symbol, int x, int y);
	bool loadEntities();
	int getMaxWidth() const;

};

