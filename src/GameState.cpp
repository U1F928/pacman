#include <vector>
#include <utility>
#include "GameState.h"
#include "GameEntity.h"
#include "GameEntities/Player/Player.h"
#include "Logger.h"

GameState::GameState()
{

}

GameState& GameState::operator = (const GameState& gameState)
{
	this->speedLevel = gameState.speedLevel;
	this->maxSpeedLevel= gameState.maxSpeedLevel;
	this->requiredScore = gameState.requiredScore;
	this->userInput = gameState.userInput;
	this->playerEntity = gameState.playerEntity->clonePlayer();
	this->entities.clear();
	this->entities.push_back(this->playerEntity);
	for(std::shared_ptr<GameEntity> entity : gameState.entities)
	{
		if(entity != gameState.playerEntity)
		{
			this->entities.push_back(entity->clone());
		}
	}
	return (*this);
}

GameState::GameState(const GameState& gameState)
{
	*this = gameState;
}

GameState::~GameState() = default;

void GameState::setMaxSpeedLevel(int speedLevel)
{
	this->maxSpeedLevel = speedLevel;
	this->speedLevel = this->maxSpeedLevel;
}

void GameState::setSpeedLevel(int speedLevel)
{

	startLog();
	log("given speed level:"); log(speedLevel); log("\n");
	log("max speed level:"); log(this->maxSpeedLevel); log("\n");
	if(speedLevel > maxSpeedLevel || speedLevel < 0)
	{
		this->speedLevel = this->maxSpeedLevel;
	}
	else
	{
		this->speedLevel = speedLevel;
	}
	log("new speed level:"); log(this->speedLevel); log("\n");
}

int GameState::getSpeedLevel() const
{
	return this->speedLevel;
}
void GameState::insertUserInput(char userInput)
{
	this->userInput = userInput;
}

void GameState::insertPlayer(std::shared_ptr<Player> playerEntity)
{
	this->playerEntity = playerEntity;
	this->entities.push_back(this->playerEntity);
}

void GameState::insertEntity(std::shared_ptr<GameEntity> entity)
{
	this->entities.push_back(entity);
}

void GameState::insertRequiredScoreToWin(int score)
{
	this->requiredScore = score;
}

char GameState::getUserInput() const
{
	return this->userInput;
}

int GameState::getPlayerScore() const
{
	return this->playerEntity->getScore();
}

int GameState::getPlayerLifeCount() const
{
	return this->playerEntity->getLifeCount();
}

bool GameState::playerLost()
{
	return this->getPlayerLifeCount() < 0;
}

bool GameState::playerWon()
{
	return this->getPlayerScore() >= this->requiredScore;
}

std::vector<std::shared_ptr<GameEntity>> GameState::getEntitiesByPosition(std::pair<int, int> position) const
{
	std::vector<std::shared_ptr<GameEntity>> clonedEntitiesOnPosition;
	for(std::shared_ptr<GameEntity> entity : this->entities)
	{
		if(entity->getPosition() == position)
		{
			clonedEntitiesOnPosition.push_back(entity->clone());
		}
	}
	return clonedEntitiesOnPosition;
}

std::vector<std::shared_ptr<GameEntity>> GameState::getAllEntities() const
{
	std::vector<std::shared_ptr<GameEntity>> clonedEntities;
	for(std::shared_ptr<GameEntity> entity : this->entities)
	{
		clonedEntities.push_back(entity->clone());
	}
	return clonedEntities;
}

GameState GameState::update() const
{

	GameState updatedGameState = (*this);	
	updatedGameState.entities.clear();
	//updatedGameState.requiredScore = this->requiredScore;
	//updatedGameState.speedLevel = this->speedLevel;
	//updatedGameState.userInput = this->userInput;
	updatedGameState.playerEntity = this->playerEntity->updatePlayer(*this);
	updatedGameState.insertEntity(updatedGameState.playerEntity);
	for(std::shared_ptr<GameEntity> entity : this->entities)
	{
		if(entity != this->playerEntity)
		{
			std::shared_ptr<GameEntity> updatedEntity = entity->update(*this);
			if(updatedEntity != nullptr)
			{
				updatedGameState.insertEntity(entity->update(*this));
			}
		}
	}
	return updatedGameState;
}	

