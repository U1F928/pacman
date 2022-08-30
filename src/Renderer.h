#pragma once
#include "GameEntity.h"
#include "GameState.h"

/**
 * @brief Class that handles drawing game state to screen
 *
 */
class Renderer
{
  public:
    /**
     * @brief Call all the needed ncurses initialization functions
     */
    void setUpNcurses();
    /**
     * @brief Call all the ncurses function needed to safely quit ncurses
     */
    void endNcurses();
    /**
     * @brief Render all the relevant information from the game state to the screen
     * @param gameState, game state to be rendered
     */
    void renderGameState(const GameState& gameState);

  private:
    int gameInfoHeight = 3; // height of the game info box that hold's the game state summary
                            /**
                             * @brief Render all the borders
                             */
    void renderBorders();
    /**
     * @brief Render all the entities from the given game state
     * @param gameState, the given gamestate
     */
    void renderEntities(const GameState& gameState);
    /**
     * @brief Render all the game info (score, life count, etc.) from the given game state
     * @param gameState, the given gamestate
     */
    void renderGameInfo(const GameState& gameState);
    /**
     * @brief Render player score from the given game state
     * @param gameState, the given gamestate
     */
    void renderScore(const GameState& gameState);
    /**
     * @brief Render player life count from the given game state
     * @param gameState, the given gamestate
     */
    void renderLifeCount(const GameState& gameState);
    /**
     * @brief Render game state summary (WIN, LOSS, ONGOING) from the given game state
     * @param gameState, the given gamestate
     */
    void renderGameStateSummary(const GameState& gameState);
    /**
     * @brief Assign the given symbol a rendering priority
     * @param symbol, the given symbol
     * @return rendering priority
     */
    int getSymbolPriority(char symbol) const;
    /**
     * @brief Check whether entity can be rendered on the given position with current screen size
     * @param position, the given position
     * @return true if the entity was successfully created, false otherwise
     */
    bool validateEntityPosition(std::pair<int, int> position);
    /**
     * @brief Compare functions that compares entities by their symbol's render priority
     * @param a, first entity
     * @param b, second entity
     * @return true if the first entity has smaller render priority, than the second, false otherwise
     */
    bool compare(const std::shared_ptr<GameEntity> a, const std::shared_ptr<GameEntity> b) const;
};
