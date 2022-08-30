#pragma once
#include "GameEntity.h"
#include "GameState.h"
#include <memory>
#include <vector>

/**
 * @brief Class responsible for safe loading of game level data from a file
 *
 */
class LevelLoader
{
  public:
    /**
     * @brief Start's the whole process of getting the file name and then loading it
     */
    bool loadFromFile();
    /**
     * @brief Load's the data back into the given game state
     * @param gameState, game state instance
     */
    void loadIntoGameState(GameState& gameState);

  private:
    std::string pathToFile;                            // path to the game level file
    int requiredScore;                                 // required score, loaded from the file
    int playerSpeedLevel;                              // player speed level, loaded from the file
    int ghostSpeedLevel;                               // ghost speed level, loaded from the file
    int maxSpeedLevel;                                 // max speed level, loaded from the file
    const unsigned int parameterCount = 4;             // how many parameters is this class made to handle
    std::shared_ptr<Player> playerEntity = nullptr;    // playerEntity, to be created from file data
    bool addedRespawnPoint = false;                    // flag that says whether respawn point was loaded
    std::vector<std::string> fileLines;                // file loaded line by line
    std::vector<std::shared_ptr<GameEntity>> entities; // all created entities, not including playerEntity
                                                       /**
                                                        * @brief Get path to the file from user, via command line
                                                        * @return true if got valid path from user, false otherwise
                                                        */
    bool getPathToFileFromUser();
    /**
     * @brief Load file line by line
     * @param pathToFile, path to the file
     * @return true if file was successfully loaded, false otherwise
     */
    bool loadFile(std::string pathToFile);
    /**
     * @brief Load the 4 parameters from the loaded file
     * @return true if the parameters were successfully loaded, false otherwise
     */
    bool loadParameters();
    /**
     * @brief Create entity instance from the given symbol and coordinates
     * @param symbol, symbol that represents the entity
     * @param x, x coordinate
     * @param y, y coordinate
     * @return true if the entity was successfully created, false otherwise
     */
    bool createEntityFromSymbol(char symbol, int x, int y);
    /**
     * @brief Load symbols representing entities from the loaded file and convert them to entities
     * @return true if all entities were successfully created, false otherwise
     */
    bool loadEntities();
    /**
     * @brief Calculate max width, based on the loaded lines from the file
     * @return return max width
     */
    int getMaxWidth() const;
};
