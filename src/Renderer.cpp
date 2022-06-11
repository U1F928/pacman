#include "Renderer.h"
#include "GameEntity.h"
#include "ncurses.h"
#include <string>
#include <algorithm>

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

bool Renderer::compare(const std::shared_ptr<GameEntity> a, const std::shared_ptr<GameEntity> b) const
{
	return this->getSymbolPriority(a->getSymbol()) > this->getSymbolPriority(b->getSymbol());
}
void Renderer::renderEntities(const GameState& gameState)
{
	std::vector<std::shared_ptr<GameEntity>> entities = gameState.getAllEntities();
	std::sort
	(
		entities.begin(), 
		entities.end(), 
		[this](auto a, auto b){return this->compare(a, b);}
	);
	int offsetX = 1;
	for(std::shared_ptr<GameEntity> entity : entities)
	{
		std::pair<int, int> position = entity->getPosition();
		position.first += this->gameInfoHeight;
		if(!this->validateEntityPosition(position))
		{
			continue;
		}
		move(position.first, position.second + offsetX);
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

int Renderer::getSymbolPriority(char symbol) const
{
	std::vector<char> symbolsOrderedByPriority = {'P', 'p', '.'};
	for(size_t i = 0; i < symbolsOrderedByPriority.size(); i++)
	{
		if(symbol == symbolsOrderedByPriority[i])
		{
			return i;
		}
	}
	return -1;
}

bool Renderer::validateEntityPosition(std::pair<int, int> position)
{
	int maxY;
	int maxX;
	getmaxyx(stdscr, maxY, maxX);
	if(position.first < this->gameInfoHeight || position.first >= maxY - 1)
	{
		return false;
	}
	if(position.second < -1 || position.second >= maxX - 3 )
	{
		return false;
	}
	return true;
}
