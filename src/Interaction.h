#pragma once
class Coin;
class PowerPellet;
class Wall;
class Teleport;
class Player;
class RespawnPoint;
class Imitator;
class Wanderer;
class Mimic;

/**
 * @brief Abstract visitor class that's passed into GameEntity.acceptInteraction(*)
 *
 */
class Interaction
{
  public:
    /**
     * @brief Interact with a Coin entity via double dispatch
     * @param coin the given coin entity
     */
    virtual void interact(const Coin& coin) = 0;
    /**
     * @brief Interact with a PowerPellet entity via double dispatch
     * @param powerPellet the given power pellet entity
     */
    virtual void interact(const PowerPellet& powerPellet) = 0;
    /**
     * @brief Interact with a Coin entity via double dispatch
     * @param wall the given wall entity
     */
    virtual void interact(const Wall& wall) = 0;
    /**
     * @brief Interact with a RespawnPoint entity via double dispatch
     * @param respawnPoint the given respawn point entity
     */
    virtual void interact(const RespawnPoint& respawnPoint) = 0;
    /**
     * @brief Interact with a Teleport entity via double dispatch
     * @param teleport the given teleport entity
     */
    virtual void interact(const Teleport& teleport) = 0;
    /**
     * @brief Interact with a Player entity via double dispatch
     * @param player the given player entity
     */
    virtual void interact(const Player& player) = 0;
    /**
     * @brief Interact with a Imitator entity via double dispatch
     * @param imitator the given imitator entity
     */
    virtual void interact(const Imitator& imitator) = 0;
    /**
     * @brief Interact with a Wanderer entity via double dispatch
     * @param wanderer the given wanderer entity
     */
    virtual void interact(const Wanderer& wanderer) = 0;
    /**
     * @brief Interact with a Mimic entity via double dispatch
     * @param mimic the given mimic entity
     */
    virtual void interact(const Mimic& mimic) = 0;
};
