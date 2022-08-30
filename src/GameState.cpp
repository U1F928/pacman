#include "GameState.h"
#include "GameEntities/Player/Player.h"
#include "GameEntity.h"
#include "Logger.h"
#include <utility>
#include <vector>

GameState::GameState() {}

GameState& GameState::operator=(const GameState& gameState)
{
    this->speedLevel = gameState.speedLevel;
    this->maxSpeedLevel = gameState.maxSpeedLevel;
    this->requiredScore = gameState.requiredScore;
    this->userInput = gameState.userInput;
    this->playerEntity = gameState.playerEntity->clonePlayer();
    this->width = gameState.width;
    this->height = gameState.height;
    this->entities.clear();
    this->entities.push_back(this->playerEntity);
    for (std::shared_ptr<GameEntity> entity : gameState.entities)
    {
        if (entity != gameState.playerEntity)
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
    if (speedLevel > maxSpeedLevel || speedLevel < 0)
    {
        this->speedLevel = this->maxSpeedLevel;
    }
    else
    {
        this->speedLevel = speedLevel;
    }
}

int GameState::getSpeedLevel() const
{
    return this->speedLevel;
}

void GameState::setHeight(int height)
{
    this->height = height;
}

void GameState::setWidth(int width)
{
    this->width = width;
}

int GameState::getHeight() const
{
    return this->height;
}

int GameState::getWidth() const
{
    return this->width;
}

void GameState::insertUserInput(char userInput)
{
    this->userInput = userInput;
}

int GameState::getRequiredScore() const
{
    return this->requiredScore;
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

bool GameState::playerLost() const
{
    return this->getPlayerLifeCount() <= 0;
}

bool GameState::playerWon() const
{
    return this->getPlayerScore() >= this->requiredScore;
}

bool GameState::validPosition(std::pair<int, int> position) const
{
    if (position.first < 0 || position.first > this->height)
    {
        return false;
    }
    if (position.second < 0 || position.second > this->width)
    {
        return false;
    }
    return true;
}

std::vector<std::pair<int, int>> GameState::getNeighborPositions(std::pair<int, int> position) const
{
    std::vector<std::pair<int, int>> neighborPositions;
    std::vector<std::pair<int, int>> directions = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};
    for (std::pair<int, int> direction : directions)
    {
        std::pair<int, int> neighborPosition = {position.first + direction.first, position.second + direction.second};
        if (this->validPosition(neighborPosition))
        {
            neighborPositions.push_back(neighborPosition);
        }
    }
    return neighborPositions;
}

std::vector<std::shared_ptr<GameEntity>> GameState::getEntitiesByPosition(std::pair<int, int> position) const
{
    std::vector<std::shared_ptr<GameEntity>> clonedEntitiesOnPosition;
    for (std::shared_ptr<GameEntity> entity : this->entities)
    {
        if (entity->getPosition() == position)
        {
            clonedEntitiesOnPosition.push_back(entity->clone());
        }
    }
    return clonedEntitiesOnPosition;
}

std::vector<std::shared_ptr<GameEntity>> GameState::getAllEntities() const
{
    std::vector<std::shared_ptr<GameEntity>> clonedEntities;
    for (std::shared_ptr<GameEntity> entity : this->entities)
    {
        clonedEntities.push_back(entity->clone());
    }
    return clonedEntities;
}

GameState GameState::update() const
{

    GameState updatedGameState = (*this);
    if (updatedGameState.playerWon() || updatedGameState.playerLost())
    {
        return updatedGameState;
    }
    updatedGameState.entities.clear();
    updatedGameState.playerEntity = this->playerEntity->updatePlayer(*this);
    updatedGameState.insertEntity(updatedGameState.playerEntity);
    for (std::shared_ptr<GameEntity> entity : this->entities)
    {
        if (entity != this->playerEntity)
        {
            std::shared_ptr<GameEntity> updatedEntity = entity->update(*this);
            if (updatedEntity != nullptr)
            {
                updatedGameState.insertEntity(updatedEntity);
            }
        }
    }
    return updatedGameState;
}
