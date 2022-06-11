#pragma once
#include "GameState.h"
#include "GameEntity.h"
class Renderer
{
public:
	void setUpNcurses();
	void endNcurses();
	void renderGameState(const GameState& gameState);
private:
	int entityOffsetY = 3;
	void renderBorders();
	void renderEntities(const GameState& gameState);
	void renderGameInfo(const GameState& gameState);
	void renderScore(const GameState& gameState);
	void renderLifeCount(const GameState& gameState);
	void renderGameStateSummary(const GameState& gameState);
	int getSymbolPriority(char symbol) const;
	bool validateEntityPosition(std::pair<int, int> position);
	bool compare(const std::shared_ptr<GameEntity> a, const std::shared_ptr<GameEntity> b) const;


};
