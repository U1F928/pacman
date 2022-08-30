#pragma once
#include "../../GameEntity.h"
#include "../Imitator/Imitator.h"
class GameEntity;
class Interaction;

class Wanderer : public Imitator
{
  public:
    Wanderer(char symbol, std::pair<int, int> position, int speedLevel, std::pair<int, int> direction = {1, 0}, bool teleportFlag = false);

    using Imitator::operator=;

    Wanderer& operator=(const Wanderer& wanderer)
    {
        Imitator::operator=(wanderer);
        return *this;
    }

    Wanderer(const Wanderer& wanderer);

    ~Wanderer();

  protected:
    std::shared_ptr<GameEntity> clone() const override;
    std::shared_ptr<GameEntity> update(const GameState& gameState) const override;
    void updatePosition(const GameState& gameState) override;

  private:
    /**
     * @brief Update's Wanderer's direction to randomly chosen direction
     */
    void updateToRandomDirection();
};
