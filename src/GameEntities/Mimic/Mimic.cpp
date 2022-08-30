#include "Mimic.h"
#include "../../GameEntity.h"
#include "../../Logger.h"
#include <cstdlib>
#include <map>
class Interaction;

Mimic::Mimic(char symbol, std::pair<int, int> position, int speedLevel, std::pair<int, int> direction, bool teleportFlag)
    : Imitator(symbol, position, speedLevel, direction, teleportFlag)
{
}

Mimic::Mimic(const Mimic& mimic)
    : Imitator(mimic)
{
}

Mimic::~Mimic() = default;

std::shared_ptr<GameEntity> Mimic::clone() const
{
    std::shared_ptr<Mimic> clonedMimic = std::make_shared<Mimic>(*this);
    return clonedMimic;
}

std::shared_ptr<GameEntity> Mimic::update(const GameState& gameState) const
{
    std::shared_ptr<Mimic> updatedMimic = std::make_shared<Mimic>(*this);
    if (updatedMimic->wasEaten(gameState))
    {
        updatedMimic->respawn(gameState);
    }
    updatedMimic->interactWithEntities(gameState);
    updatedMimic->updateTeleportFlag(gameState);
    updatedMimic->updatePosition(gameState);
    updatedMimic->updateDirectionByUserInput(gameState.getUserInput());
    return updatedMimic;
}

void Mimic::updatePosition(const GameState& gameState)
{
    if (this->speedLevel < gameState.getSpeedLevel())
    {
        return;
    }
    int updatedPositionFirst = this->position.first + this->direction.first;
    int updatedPositionSecond = this->position.second + this->direction.second;
    std::pair<int, int> updatedPosition = {updatedPositionFirst, updatedPositionSecond};
    if (this->canAccessPosition(gameState, updatedPosition))
    {
        this->position = updatedPosition;
    }
}

bool Mimic::updateDirectionByUserInput(char userInput)
{
    std::map<char, std::pair<int, int>> directionByUserInput = {{'k', {+1, 0}}, {'h', {0, +1}}, {'l', {0, -1}}, {'j', {-1, 0}}};
    if (directionByUserInput.find(userInput) == directionByUserInput.end())
    {
        return false;
    }
    this->direction = directionByUserInput[userInput];
    return true;
}
