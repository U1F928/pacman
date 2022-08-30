#pragma once
#include "../../GameEntity.h"
class Interaction;
class GameEntity;

class Teleport : public GameEntity
{
  public:
    Teleport(char symbol, std::pair<int, int> position, std::pair<int, int> nearestTeleportPosition = {-1, -1});

    Teleport& operator=(const Teleport& teleport);

    Teleport(const Teleport& teleport);

    ~Teleport();

    virtual char getSymbol() const override;

    virtual std::pair<int, int> getPosition() const override;

    virtual std::pair<int, int> getDirection() const override;

    void acceptInteraction(Interaction& interaction) const override;

    std::shared_ptr<GameEntity> clone() const override;

    std::shared_ptr<GameEntity> update(const GameState& gameState) const override;

    std::pair<int, int> getPositionOfNearestTeleport() const;

  private:
    char symbol;
    std::pair<int, int> position;
    std::pair<int, int> nearestTeleportPosition; // position of the nearest teleport (without accounting for itself)
                                                 /**
                                                  * @brief Update position of the nearest teleport
                                                  * @param gameState
                                                  */
    void updatePositionOfNearestTeleport(const GameState& gameState);
    /**
     * @brief Check whether there is a connectible entity on the given position
     * @param gameState
     * @param position, the given position
     * @return true if the there is a connectible entity on the given position, false otherwise
     */
    bool connectibleEntityOnPosition(const GameState& gameState, std::pair<int, int> position) const;
    /**
     * @brief Check if the given entity can connect to Teleport
     * @param gameEntity, the given entity
     * @return true if the the given entity can connect to Teleport, false otherwise
     */
    bool canConnectTo(const GameEntity& gameEntity) const;
};
