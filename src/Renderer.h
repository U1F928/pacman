#pragma once
#include "GameState.h"
class Renderer
{
public:
	void setUpNcurses();
	void endNcurses();
	void renderGameState(const GameState& gameState);
private:
	void renderEntities(const GameState& gameState);
	void renderGameInfo(const GameState& gameState);
	void renderScore(const GameState& gameState);
	void renderLifeCount(const GameState& gameState);
	void renderGameStateSummary(const GameState& gameState);
	int getSymbolPriority(char symbol);

};
