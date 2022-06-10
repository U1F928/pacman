#ifdef LOGGING_ON
	#include "Logger.h"
#endif

#include <chrono>
#include <memory>
#include <set>
#include <fstream>
#include <string>
#include <ncurses.h>
#include "Game.h"
#include "LevelLoader.h"
#include "GameState.h"
#include "GameEntities/Player/Player.h"
#include "GameEntities/Coin/Coin.h"

#include <iostream>
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
	startLog();
	this->time = std::chrono::steady_clock::now();
	this->setUpNcurses();
	this->quitGame = false;
	this->mainLoop();
}
void Game::mainLoop()
{
	int deltaTime = 0;
	while(true)
	{
		this->handleUserInput();
		if(this->quitGame)
		{
			this->endNcurses();
			return;
		}
		deltaTime += this->getElapsedMicroseconds();
		while(deltaTime > this->microsecondsPerFrame)
		{
			this->currentGameState.setSpeedLevel(currentGameState.getSpeedLevel() - 1);
			startLog();
			this->currentGameState = this->currentGameState.update();
			deltaTime -= this->microsecondsPerFrame ;
		}
		this->drawGameState(this->currentGameState);
	}
}
void Game::setUpNcurses()
{
    initscr();                 
    nodelay(stdscr, true);
    curs_set(0);
    noecho();
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
void Game::endNcurses()
{
	endwin();
}

void Game::drawGameState(const GameState& gameState)
{
    erase();
	this->drawGameInfo(gameState);
	this->drawEntities(gameState);
    refresh();
}
void Game::drawEntities(const GameState& gameState)
{
	// TODO: add priority for overlapping entities
	// TODO: don't draw entities out of bounds
	const int offset = 2;
	std::vector<std::shared_ptr<GameEntity>> entities = gameState.getAllEntities();
	for(std::shared_ptr<GameEntity> entity : entities)
	{
		std::pair<int, int> position = entity->getPosition();
		move(position.first, position.second + offset);
    	addch(entity->getSymbol()); 
	}

}
void Game::drawGameInfo(const GameState& gameState)
{
	move(0, 0);
	std::string currentScore = std::to_string(gameState.getPlayerScore());
	std::string requiredScore = std::to_string(gameState.getRequiredScore ());
	printw("SCORE: ");
	printw(currentScore.c_str());
	printw("/");
	printw(requiredScore.c_str());
}

