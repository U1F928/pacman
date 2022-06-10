#include  <string>
#include <chrono>
#include "GameState.h"
#include "Renderer.h"
// hello
class Game
{
public:
	void start();
private:
	bool quitGame;
	const int microsecondsPerFrame = 200000;
	std::chrono::steady_clock::time_point time; 
	Renderer renderer;
	GameState currentGameState;

	bool loadLevel();
	void setUpNcurses();
	void endNcurses();
	void mainLoop();
	int getElapsedMicroseconds();
	void handleUserInput();
};
