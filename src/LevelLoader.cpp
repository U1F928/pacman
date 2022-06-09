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
	std::ifstream fileStream(pathToFile);
	while(true)
	{
		if(!fileStream.good())
		{
			return false;
		}
		std::string line;
		std::getline(fileStream, line);
	#ifdef LOGGING_ON
		startLog();
		log("read line: "); log(line);
	#endif
	}

	return true;

}
void LevelLoader::loadIntoGameState(GameState& gameState)
{
	// TODO
}

