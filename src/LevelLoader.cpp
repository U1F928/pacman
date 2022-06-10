#include <memory>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <optional>
#include "LevelLoader.h"
#include "GameState.h"
#include "GameEntity.h"
#include "GameEntities/Player/Player.h"
#include "GameEntities/Coin/Coin.h"

#ifdef LOGGING_ON
	#include "Logger.h"
#endif

bool LevelLoader::loadFromFile(std::string pathToFile)
{
	startLog();
	if(!this->loadFile(pathToFile))
	{
		return false;
	}
	if(!this->loadParameters())
	{
		return false;
	}
	if(!this->loadEntities())
	{
		return false;
	}
	return true;
}
void LevelLoader::loadIntoGameState(GameState& gameState)
{
	gameState.insertRequiredScoreToWin(this->requiredScore);
	gameState.setMaxSpeedLevel(this->maxSpeedLevel);
	gameState.insertUserInput(0);
	startLog();
	gameState.insertPlayer(this->playerEntity);
	for(std::shared_ptr<GameEntity> entity : this->entities)
	{
		gameState.insertEntity(entity);
	}
}

bool LevelLoader::loadFile(std::string pathToFile)
{
	std::ifstream fileStream(pathToFile);
	while(true)
	{
		if(fileStream.eof())
		{
			return true;
		}
		if(!fileStream.good())
		{
			return false;
		}
		std::string line;
		std::getline(fileStream, line);
		this->fileLines.push_back(line);
	}
}
bool LevelLoader::loadParameters()
{
	if(this->fileLines.size() < this->parameterCount)
	{
		return false;
	}
	std::vector<int> parameterValues(this->parameterCount, -1);
	for(size_t i = 0; i < this->parameterCount; i++)
	{
		std::stringstream lineStream;
		lineStream << this->fileLines[i];
		lineStream >> parameterValues[i];
		if(!lineStream.good() && !lineStream.eof())
		{
			return false;
		}
	}
	this->requiredScore = parameterValues[0];
	this->playerSpeedLevel = parameterValues[1];
	this->ghostSpeedLevel = parameterValues[2];
	this->maxSpeedLevel = parameterValues[3];
	return true;
}

bool LevelLoader::createEntityFromSymbol(char symbol, int x, int y)
{
	switch(symbol)
	{
		case 'p':
		{
			//Player player('p', {x, y}, this->playerSpeedLevel);
			startLog();
			Player player('p', {10, 0}, this->playerSpeedLevel);
			this->playerEntity = std::make_shared<Player> (player); 
			break;
		}
		case '.':
		{
			std::shared_ptr<Coin> coin = std::make_shared<Coin> (Coin('.', {x, y})); 
			this->entities.push_back(coin);
			break;
		}
		case ' ':
		{
			break;
		}
		default:
		{
			startLog();
			return false;
		}
	}
	return true;
}
bool LevelLoader::loadEntities()
{
	for(size_t x = this->parameterCount; x < this->fileLines.size(); x++)
	{
		for(size_t y = 0; y < this->fileLines[x].size(); y++)
		{
			startLog();
			char symbol = this->fileLines[x][y];
			if(!this->createEntityFromSymbol(symbol, x, y))
			{
				return false;
			}
		}
	}
	if(this->playerEntity == nullptr)
	{
		return false;
	}
	return true;
}
