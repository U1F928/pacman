#include  <string>
#include <chrono>
#include "GameState.h"
// hello
class Game
{
public:
	void start();
private:
	bool quitGame;
	const int microsecondsPerFrame = 200000;
	std::chrono::steady_clock::time_point time; 
	GameState currentGameState;

	bool loadLevel();
	void setUpNcurses();
	void endNcurses();
	void mainLoop();
	int getElapsedMicroseconds();
	void handleUserInput();
	void drawGameState(const GameState& gameState);
	void drawEntities(const GameState& gameState);
	void drawGameInfo(const GameState& gameState);
};
