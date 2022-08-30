#pragma once
#include "../../GameEntity.h"
class GameEntity;
class Interaction;

class Player : public GameEntity
{
  public:
    /**
     * @brief Constructor
     * @param symbol, symbol that represents Player
     * @param positon, Player's position
     * @param speedLevel, Player's speed level
     * @param direction, Player's direction
     * @param lifeCount, Player's number of lifes
     * @param score, Player's score
     * @param ghostEatingTime, how much time Player has left in his ghost eating form
     * @param ghostEatingSymbol, symbol representing Player's ghost eating form
     * @param teleportFlag, whether Player has recently teleported
     */
    Player(char symbol,
           std::pair<int, int> position,
           int speedLevel,
           std::pair<int, int> direction = {1, 0},
           int lifeCount = 1,
           int score = 0,
           int ghostEatingTime = 0,
           char ghostEatingSymbol = 'P',
           bool teleportFlag = false);

    /**
     * @brief Deep copy assignment operator
     * @param player, another Player instance
     * @return itself
     */
    Player& operator=(const Player& player);
    /**
     * @brief Copy constructor, implemented by assignment operator
     * @param player, another instance of Player
     */
    Player(const Player& player);
    /**
     * @brief Destructor, default
     */
    ~Player();

    char getSymbol() const override;

    std::pair<int, int> getPosition() const override;

    std::pair<int, int> getDirection() const override;
    /**
     * @brief Get Player's current score
     * @return current score
     */
    int getScore() const;
    /**
     * @brief Set Player's score
     * @param score, new value of Player's score
     */
    void setScore(int score);
    /**
     * @brief Get Player's time left in the ghost eating form
     * @return time left in the ghost eating form
     */
    int getGhostEatingTime() const;
    /**
     * @brief Set Player's time left in the ghost eating form
     * @param time, time left in the ghost eating form
     */
    void setGhostEatingTime(int time);
    /**
     * @brief Get Player's number of reamining life's
     * @return number of reamining life's
     */
    int getLifeCount() const;
    /**
     * @brief Try (teleport flag) to teleport player to the given position
     * @param position, the given position
     */
    void teleportToPosition(std::pair<int, int> position);

    void acceptInteraction(Interaction& interaction) const override;
    /**
     * @brief Get deep copy of the Player as a shared pointer WITHOUT being saved as abstract class
     * @return deep copy of Player
     */
    std::shared_ptr<Player> clonePlayer() const;

    std::shared_ptr<GameEntity> clone() const override;
    /**
     * @brief Get updated deep copy of the Player as a shared pointer WITHOUT being saved as abstract class
     * @return updated deep copy of Player
     */
    std::shared_ptr<Player> updatePlayer(const GameState& gameState) const;

    std::shared_ptr<GameEntity> update(const GameState& gameState) const override;

  private:
    char symbol;
    std::pair<int, int> position;
    int speedLevel;
    std::pair<int, int> direction;
    int lifeCount;
    int score;
    int ghostEatingTime;
    char ghostEatingSymbol;
    bool teleportFlag;

    /**
     * @brief Check whether Player can share tile with the given entity
     * @param gameEntity, the given entity
     * @return true if a tile can be shared, false otherwise
     */
    bool canShareTileWith(const GameEntity& gameEntity) const;
    /**
     * @brief Share tile with the given entity
     * @param gameEntity, the given entity
     */
    void shareTileWith(const GameEntity& gameEntity);
    /**
     * @brief Update Player's direction by the given user's input
     * @param userInput, user's input
     * @return true if the input was valid, false otherwise
     */
    bool updateDirectionByUserInput(char userInput);
    /**
     * @brief Update Player's position
     * @param gameState
     */
    void updatePosition(const GameState& gameState);
    /**
     * @brief Update Player's teleport flag
     * @param gameState
     */
    void updateTeleportFlag(const GameState& gameState);
    /**
     * @brief Interact with entities on the Player's position
     * @param gameState
     */
    void interactWithEntities(const GameState& gameState);
    /**
     * @brief Update Player's number of lifes
     * @param gameState
     */
    void updateLifeCount(const GameState& gameState);
    /**
     * @brief Update Player's ghost eating time
     * @param gameState
     */
    void updateGhostEatingTime(const GameState& gameState);
    /**
     * @brief Check whether Player was eaten
     * @param gameState
     * @return true if Player was eaten, false otherwise
     */
    bool wasEaten(const GameState& gameState);
    /**
     * @brief Check whether Player can access the given position (other entities aren't blocking it)
     * @param position, the given position
     * @param gameState, game state
     * @return true if Player can access the given position, false otherwise
     */
    bool canAccessPosition(const GameState& gameState, std::pair<int, int> position) const;
};
