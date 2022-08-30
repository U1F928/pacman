#ifdef LOGGING_ON
#include "Logger.h"
#endif

#include "Game.h"
#include "GameEntities/Coin/Coin.h"
#include "GameEntities/Player/Player.h"
#include "GameState.h"
#include "LevelLoader.h"
#include "Renderer.h"
#include "ncurses.h"
#include <chrono>
#include <fstream>
#include <memory>
#include <set>
#include <string>

bool Game::loadLevel()
{
    LevelLoader levelLoader;
    if (!levelLoader.loadFromFile())
    {
        return false;
    }
    levelLoader.loadIntoGameState(this->currentGameState);
    return true;
}

void Game::start()
{
    if (!this->loadLevel())
    {
        return;
    }
    this->time = std::chrono::steady_clock::now();
    this->renderer.setUpNcurses();
    this->quitGame = false;
    this->mainLoop();
}

void Game::mainLoop()
{
    int deltaTime = 0;
    while (true)
    {
        this->handleUserInput();
        if (this->quitGame)
        {
            this->renderer.endNcurses();
            return;
        }
        if (this->currentGameState.playerLost() || this->currentGameState.playerWon())
        {
            // waiting for user to quit game
            continue;
        }
        this->updateGameStateByDeltaTime(deltaTime);
        this->renderer.renderGameState(this->currentGameState);
    }
}

int Game::getElapsedMicroseconds()
{
    std::chrono::steady_clock::time_point newTime = std::chrono::steady_clock::now();
    int elapsedMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(newTime - this->time).count();
    this->time = newTime;
    return elapsedMicroseconds;
}

void Game::handleUserInput()
{
    char userInput = getch();
    const char escapeKey = 27;
    if (userInput == escapeKey)
    {
        this->quitGame = true;
        return;
    }
    std::set<char> validGameStateInput = {'h', 'j', 'k', 'l'};
    if (validGameStateInput.find(userInput) != validGameStateInput.end())
    {
        this->currentGameState.insertUserInput(userInput);
    }
}

void Game::updateGameStateByDeltaTime(int& deltaTime)
{
    deltaTime += this->getElapsedMicroseconds();
    while (deltaTime > this->microsecondsPerFrame)
    {
        this->currentGameState.setSpeedLevel(currentGameState.getSpeedLevel() - 1);
        this->currentGameState = this->currentGameState.update();
        deltaTime -= this->microsecondsPerFrame;
    }
}
