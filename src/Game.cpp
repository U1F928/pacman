#ifdef LOGGING_ON
	#include "Logger.h"
#endif

#include <chrono>
#include <memory>
#include <set>
#include <fstream>
#include <string>
#include "Game.h"
#include "LevelLoader.h"
#include "Renderer.h"
#include "GameState.h"
#include "GameEntities/Player/Player.h"
#include "GameEntities/Coin/Coin.h"
#include "ncurses.h"

bool Game::loadLevel()
{
	LevelLoader levelLoader;
	if(!levelLoader.loadFromFile())
	{
		return false;
	}
	levelLoader.loadIntoGameState(this->currentGameState);
	return true;
}
void Game::start()
{
	if(!this->loadLevel())
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
	// TODO: refactor the two while loops
	int deltaTime = 0;
	while(true)
	{
		this->handleUserInput();
		if(this->quitGame)
		{
			this->renderer.endNcurses();
			return;
		}
		deltaTime += this->getElapsedMicroseconds();
		while(deltaTime > this->microsecondsPerFrame)
		{
			if(this->currentGameState.playerLost() || this->currentGameState.playerWon())
			{
				break;
			}
			this->currentGameState.setSpeedLevel(currentGameState.getSpeedLevel() - 1);
			startLog();
			this->currentGameState = this->currentGameState.update();
			deltaTime -= this->microsecondsPerFrame ;
		}
		this->renderer.renderGameState(this->currentGameState);
		//this->drawGameState(this->currentGameState);
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
	if(userInput == escapeKey)
	{
		this->quitGame = true;
		return;
	}
	std::set<char> validGameStateInput = {'h', 'j', 'k', 'l'};
	if(validGameStateInput.find(userInput) != validGameStateInput.end())
	{
		this->currentGameState.insertUserInput(userInput);
	}
}
