#include  <string>
#include <chrono>
#include "GameState.h"
// hello
class Game
{
public:
	void start();
private:
	bool loadLevel();
	void setUpNcurses();
	void mainLoop();
	int getElapsedMicroseconds();
	void handleUserInput();
	void drawGameState(const GameState& gameState);
	std::chrono::steady_clock::time_point time; 
	const int microsecondsPerFrame = 200000;
	GameState currentGameState;
};
