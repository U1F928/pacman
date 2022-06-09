#include  <string>
#include <chrono>
#include "GameState.h"
// hello
class Game
{
public:
	bool loadMapFromFile(std::string pathToFile);
	void start();
private:
	void mainLoop();
	void setUpNcurses();
	int getElapsedMicroseconds();
	void handleUserInput();
	void drawGameState(const GameState& gameState);
	std::chrono::steady_clock::time_point time; 
	const int microsecondsPerFrame = 200000;
	const int maxSpeedLevel = 10;
	GameState currentGameState;
};
