#include "GameState.h"
#include "Renderer.h"
#include <chrono>
#include <string>

/**
 * @brief Class that glues all the components together
 *
 */
class Game
{
  public:
    /**
     * @brief Initialize all the components and start the game
     */
    void start();

  private:
    bool quitGame;                              // flag that breaks the main loop and ends the game
    const int microsecondsPerFrame = 200000;    // how much time will have to elapse to update GameState
    std::chrono::steady_clock::time_point time; // stores the time of last measurement
    Renderer renderer;                          // rendering component
    GameState currentGameState;                 // component that's responsible for holding game state
                                                /**
                                                 * @brief Load level that will be played, get's all the info it needs from the user via command line
                                                 * @return true if a level was successfully loaded, return false otherwise
                                                 */
    bool loadLevel();
    /**
     * @brief main loop/game loop
     */
    void mainLoop();
    /**
     * @brief main loop/game loop
     * @return return how many microseconds have elapsed since last measurement
     */
    int getElapsedMicroseconds();
    /**
     * @brief Handle user input, validate, react and send it further if needed
     */
    void handleUserInput();
    /**
     * @brief Updates game state X times, where X is related to the time elapsed since last game state update
     */
    void updateGameStateByDeltaTime(int& deltaTime);
};
