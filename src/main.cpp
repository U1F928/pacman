#include "Game.h"
int main()
{
	Game newGame;
	newGame.loadMapFromFile("examples/gameLevel1");
	newGame.start();
}
