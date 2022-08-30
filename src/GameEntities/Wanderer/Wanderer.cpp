#include "Wanderer.h"
#include "../../GameEntity.h"
#include "../../Logger.h"
#include <cstdlib>
class Interaction;

Wanderer::Wanderer(char symbol, std::pair<int, int> position, int speedLevel, std::pair<int, int> direction, bool teleportFlag)
    : Imitator(symbol, position, speedLevel, direction, teleportFlag)
{
}

Wanderer::Wanderer(const Wanderer& wanderer)
    : Imitator(wanderer)
{
}

Wanderer::~Wanderer() = default;

std::shared_ptr<GameEntity> Wanderer::clone() const
{
    std::shared_ptr<Wanderer> clonedWanderer = std::make_shared<Wanderer>(*this);
    return clonedWanderer;
}

std::shared_ptr<GameEntity> Wanderer::update(const GameState& gameState) const
{
    std::shared_ptr<Wanderer> updatedWanderer = std::make_shared<Wanderer>(*this);
    if (updatedWanderer->wasEaten(gameState))
    {
        updatedWanderer->respawn(gameState);
    }
    updatedWanderer->interactWithEntities(gameState);
    updatedWanderer->updateTeleportFlag(gameState);
    updatedWanderer->updatePosition(gameState);
    return updatedWanderer;
}

void Wanderer::updatePosition(const GameState& gameState)
{
    startLog();
    log("updating wanderer position\n");
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
    else
    {
        this->updateToRandomDirection();
    }
}

void Wanderer::updateToRandomDirection()
{
    std::vector<std::pair<int, int>> directions = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
    this->direction = directions[rand() % directions.size()];
}
