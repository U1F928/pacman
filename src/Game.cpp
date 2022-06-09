#ifdef LOGGING_ON
	#include "Logger.h"
#endif

#include <chrono>
#include <memory>
#include <set>
#include <fstream>
#include <ncurses.h>
#include "Game.h"
#include "GameState.h"
#include "GameEntities/Player/Player.h"
#include "GameEntities/Coin/Coin.h"

#include <iostream>
bool Game::loadMapFromFile(std::string pathToFile)
{
	// TODO load from file
	this->currentGameState.insertRequiredScoreToWin(3);
	this->currentGameState.insertEntity(std::make_shared<Coin>(Coin('O', {5, 5})));
	this->currentGameState.insertEntity(std::make_shared<Coin>(Coin('O', {15, 15})));
	this->currentGameState.insertEntity(std::make_shared<Coin>(Coin('O', {20, 20})));
	Player player('P', {10, 0}, 9, {1, 0}, 3, 0);
	this->currentGameState.insertPlayer(std::make_shared<Player>(player));
	this->currentGameState.setSpeedLevel(10);
	return true;
}
void Game::start()
{
	this->setUpNcurses();
	this->time = std::chrono::steady_clock::now();
	this->mainLoop();
}
void Game::mainLoop()
{

	int deltaTime = 0;
	while(true)
	{
		this->handleUserInput();
		deltaTime += this->getElapsedMicroseconds();
		while(deltaTime > this->microsecondsPerFrame)
		{
			this->currentGameState.setSpeedLevel(currentGameState.getSpeedLevel() - 1);
			if(this->currentGameState.getSpeedLevel() < 0)
			{
				this->currentGameState.setSpeedLevel(this->maxSpeedLevel); 
			}
			GameState nextGameState = this->currentGameState.update();
			this->currentGameState = nextGameState;
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
	std::set<char> validInputs = {'h', 'j', 'k', 'l'};
	if(validInputs.find(userInput) != validInputs.end())
	{
		this->currentGameState.insertUserInput(userInput);
	}
}
void Game::drawGameState(const GameState& gameState)
{
	// TODO: add priority for overlapping entities
    erase();
	std::vector<std::shared_ptr<GameEntity>> entities = gameState.getAllEntities();
	for(std::shared_ptr<GameEntity> entity : entities)
	{
		std::pair<int, int> position = entity->getPosition();
		move(position.first, position.second);
    	addch(entity->getSymbol()); 
	}
    refresh();
}

