#include <memory>
#include <vector>
#include <fstream>
#include "LevelLoader.h"
#include "GameState.h"
#include "GameEntity.h"

#ifdef LOGGING_ON
	#include "Logger.h"
#endif

bool LevelLoader::loadFromFile(std::string pathToFile)
{
	// TODO
	this->loadFile(pathToFile);
	return false;
}
void LevelLoader::loadIntoGameState(GameState& gameState)
{
	// TODO
}

bool LevelLoader::loadFile(std::string pathToFile)
{
	std::ifstream fileStream(pathToFile);
	while(true)
	{
		if(!fileStream.good())
		{
			log("failed to open file");
			return false;
		}
		std::string line;
		std::getline(fileStream, line);
		this->fileLines.push_back(line);
	}
	return true;
}

bool LevelLoader::loadRequiredScore()
{
	return false;
}

bool LevelLoader::loadPlayerSpeedLevel()
{
	return false;
}

bool LevelLoader::loadGhostSpeedLevel()
{
	return false;
}
bool LevelLoader::loadEntities()
{
	return false;
}
