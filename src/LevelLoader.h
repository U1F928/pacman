#pragma once
#include <memory>
#include <vector>
#include "GameState.h"
#include "GameEntity.h"
class LevelLoader
{
public:
	bool loadFromFile(std::string pathToFile);
	void loadIntoGameState(GameState& gameState);
private:
	std::shared_ptr<Player> playerEntity;
	std::vector<std::shared_ptr<GameEntity>> entities; // not including playerEntity
};

