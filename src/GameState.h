#pragma once
#include <memory>
#include <utility>
#include <vector>
class Player;
class GameEntity;

/**
 * @brief Class that stores/updates important game information
 *
 */
class GameState
{
  public:
    /**
     * @brief Constructor
     */
    GameState();
    /**
     * @brief Deep copy assignment operator
     * @param gameState, another gameState instance
     * @return itself
     */
    GameState& operator=(const GameState& gameState);
    /**
     * @brief Deep copy copy constructor, implemented by assignment operator
     * @param gameState, another gameState instance
     */
    GameState(const GameState& gameState);
    /**
     * @brief Default destructor
     */
    ~GameState();
    /**
     * @brief Set max height of the level
     * @param height, max height
     */
    void setHeight(int height);
    /**
     * @brief Set max width of the level
     * @param width, max width
     */
    void setWidth(int width);
    /**
     * @brief Get max height of the level
     * @return max height
     */
    int getHeight() const;
    /**
     * @brief Get max width of the level
     * @return max width
     */
    int getWidth() const;
    /**
     * @brief Set max speed level of the game
     * @param speedLevel, max speed level
     */
    void setMaxSpeedLevel(int speedLevel);
    /**
     * @brief Set speed level of the game
     * @param speedLevel, speed level
     */
    void setSpeedLevel(int speedLevel);
    /**
     * @brief Get speed level of the game
     * @return speed level
     */
    int getSpeedLevel() const;
    /**
     * @brief Insert user input into the game state, so other entities (mostly player entity) can react to it
     * @param userInput, user input
     */
    void insertUserInput(char userInput);
    /**
     * @brief Insert player entity into the game state
     * @param playerEntity, player entity
     */
    void insertPlayer(std::shared_ptr<Player> playerEntity);
    /**
     * @brief Insert game entity other than player into the game state
     * @param gameEntity, game entity
     */
    void insertEntity(std::shared_ptr<GameEntity> gameEntity);
    /**
     * @brief Insert minimum score player will have to achieve to be able to win
     * @param score
     */
    void insertRequiredScoreToWin(int score);
    /**
     * @brief Get input that was inserted into this game state
     * @return user input
     */
    char getUserInput() const;
    /**
     * @brief Get current score of the player
     * @return current score
     */
    int getPlayerScore() const;
    /**
     * @brief Get current number of lifes of the player
     * @return current number of lifes
     */
    int getPlayerLifeCount() const;
    /**
     * @brief Get minimum score needed for player to be able to win
     * @return minimum score needed
     */
    int getRequiredScore() const;
    /**
     * @brief Check if player has lost
     * @return return true if player has lost, false otherwise
     */
    bool playerLost() const;
    /**
     * @brief Check if player has won
     * @return return true if player has won, false otherwise
     */
    bool playerWon() const;
    /**
     * @brief Check if the given position isn't out of bounds (0, maxHeight/maxWidth)
     * @param position, position to check
     * @return return true if position isn't out of bounds, false otherwise
     */
    bool validPosition(std::pair<int, int> position) const;
    /**
     * @brief Get all positions that neighbor, with the given position
     * @param position, given position
     * @return return array of neighboring positions
     */
    std::vector<std::pair<int, int>> getNeighborPositions(std::pair<int, int> position) const;
    /**
     * @brief Get all entities on the given position
     * @param position, given position
     * @return return array of entities on the given position
     */
    std::vector<std::shared_ptr<GameEntity>> getEntitiesByPosition(std::pair<int, int> position) const;
    /**
     * @brief Get all entities
     * @return return array of all entities
     */
    std::vector<std::shared_ptr<GameEntity>> getAllEntities() const;
    /**
     * @brief Get updated version of this game state
     * @return return updated deep copy of this game state
     */
    GameState update() const;

  private:
    int speedLevel;                                    // speed level of the game
    int maxSpeedLevel;                                 // maximum speed level of the game
    int requiredScore;                                 // minimum score player will have to achieve to be able to win
    char userInput;                                    // user input
    int height;                                        // max height
    int width;                                         // max width
    std::shared_ptr<Player> playerEntity;              // singled out player entity to avoid RTTI (dynamic_cast, type_id, etc.)
    std::vector<std::shared_ptr<GameEntity>> entities; // all entities, playerEntity included
};
