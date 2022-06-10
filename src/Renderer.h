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

};
