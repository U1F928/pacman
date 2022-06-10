#include "Renderer.h"
#include "GameEntity.h"
#include "ncurses.h"
#include <string>
void Renderer::setUpNcurses()
{
    initscr();                 
    nodelay(stdscr, true);
    curs_set(0);
    noecho();
}
void Renderer::endNcurses()
{
	endwin();
}
void Renderer::renderGameState(const GameState& gameState)
{
 	erase();
	this->renderBorders();
	this->renderGameInfo(gameState);
	this->renderEntities(gameState);
    refresh();

}
void Renderer::renderEntities(const GameState& gameState)
{
	// TODO: add priority for overlapping entities
	// TODO: don't draw entities out of bounds
	const int offset = 2;
	std::vector<std::shared_ptr<GameEntity>> entities = gameState.getAllEntities();
	for(std::shared_ptr<GameEntity> entity : entities)
	{
		std::pair<int, int> position = entity->getPosition();
		if(!this->validateEntityPosition(position))
		{
			continue;
		}
		move(position.first, position.second + offset);
    	addch(entity->getSymbol()); 
	}
}
void Renderer::renderBorders()
{
	int horizontalBorderPosY = 2;
	move(horizontalBorderPosY, 0);
	hline('-', getmaxx(stdscr));
	box(stdscr, '|', '-');
}
void Renderer::renderGameInfo(const GameState& gameState)
{
	int gameInfoPosY = 1;
	move(gameInfoPosY, 0);
	printw("| ");
	this->renderScore(gameState);
	printw(" | ");
	this->renderLifeCount(gameState);
	printw(" | ");
	this->renderGameStateSummary(gameState);
	printw(" |");
}
void Renderer::renderScore(const GameState& gameState)
{
	std::string currentScore = std::to_string(gameState.getPlayerScore());
	std::string requiredScore = std::to_string(gameState.getRequiredScore());
	printw("SCORE: ");
	printw(currentScore.c_str());
	printw("/");
	printw(requiredScore.c_str());
}
void Renderer::renderLifeCount(const GameState& gameState)
{
	printw("LIFE COUNT: ");
	std::string lifeCount = std::to_string(gameState.getPlayerLifeCount());
	printw(lifeCount.c_str());
}
void Renderer::renderGameStateSummary(const GameState& gameState)
{
	printw("GAME STATE: ");
	if(gameState.playerLost())
	{
		printw("LOSS");
	}
	else if(gameState.playerWon())
	{
		printw("WIN");
	}
	else
	{
		printw("ONGOING");
	}
}

int Renderer::getSymbolPriority(char symbol)
{
	return 1;
}

bool Renderer::validateEntityPosition(std::pair<int, int> position)
{
	int maxY;
	int maxX;
	getmaxyx(stdscr, maxY, maxX);
	if(position.first < this->entityOffsetY || position.first >= maxY - 1)
	{
		return false;
	}
	if(position.second < -1 || position.second >= maxX - 3 )
	{
		return false;
	}
	return true;
}
