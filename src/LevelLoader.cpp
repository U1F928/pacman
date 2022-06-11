#include <memory>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <optional>
#include "LevelLoader.h"
#include "GameState.h"
#include "GameEntity.h"
#include "GameEntities/Player/Player.h"
#include "GameEntities/Coin/Coin.h"
#include "GameEntities/Wall/Wall.h"
#include "GameEntities/PowerPellet/PowerPellet.h"

#ifdef LOGGING_ON
	#include "Logger.h"
#endif

bool LevelLoader::getPathToFileFromUser()
{
	std::cout << "Input path to file containing the desired game level:" << std::endl;
	while(true)
	{
		std::string pathToFile;
		std::cin >> pathToFile;
		if(!std::cin.good())
		{
			return false;
		}
		std::ifstream fileStream(pathToFile);
		if(fileStream.good())
		{
			this->pathToFile = pathToFile;
			return true;
		}
		else
		{
			std::cout << "Given path does not lead to readable file, try again:" << std::endl; 
		}
	}
}
bool LevelLoader::loadFromFile()
{
	if(!this->getPathToFileFromUser())
	{
		return false;
	}
	if(!this->loadFile(this->pathToFile))
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

	startLog();
	gameState.setMaxSpeedLevel(this->maxSpeedLevel);
	gameState.insertUserInput(0);
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
			if(this->playerEntity != nullptr)
			{
				std::cerr << "ERR: More than one player entity" << std::endl;
				return false;
			}
			Player player('p', {x, y}, this->playerSpeedLevel);
			this->playerEntity = std::make_shared<Player> (player); 
			break;
		}
		case '#':
		{
			std::shared_ptr<Wall> wall = std::make_shared<Wall> (Wall('#', {x, y})); 
			this->entities.push_back(wall);
			break;
		}
		case '~':
		{
			std::shared_ptr<PowerPellet> powerPellet = std::make_shared<PowerPellet> (PowerPellet('~', {x, y})); 
			this->entities.push_back(powerPellet);
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
			std::cerr << "ERR: Unknow symbol: '" << symbol << std::endl;
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
			char symbol = this->fileLines[x][y];
			if(!this->createEntityFromSymbol(symbol, x, y))
			{
				return false;
			}
		}
	}
	if(this->playerEntity == nullptr)
	{

		std::cerr << "ERR: Missing player entity" << std::endl;
		return false;
	}
	return true;
}
