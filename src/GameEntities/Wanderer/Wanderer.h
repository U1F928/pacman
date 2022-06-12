	#pragma once
#include "../../GameEntity.h"
#include "../Imitator/Imitator.h"
class GameEntity;
class Interaction;
class Wanderer : public Imitator //public GameEntity
{
public:
	Wanderer
	(
		char symbol, 
		std::pair<int, int> position, 
		int speedLevel, 
		std::pair<int, int> direction = {1, 0}, 
		bool teleportFlag = false
	);

	using Imitator::operator =;
	Wanderer& operator=(const Wanderer& wanderer) 
	{
	    // wanderer stuff here
	
	    // A stuff
	    Imitator::operator=(wanderer);
	
	    return *this;
	}
	Wanderer(const Wanderer& wanderer);

	~Wanderer();
protected:
//
//	char getSymbol() const override; 
//
//	std::pair<int, int> getPosition() const override;
//
//	void teleportToPosition(std::pair<int, int> position);
//
//	void acceptInteraction(Interaction& interaction) const override;
//
	std::shared_ptr<GameEntity> clone() const override;
//
	std::shared_ptr<GameEntity> update(const GameState& gameState) const override;
//	char symbol;
//	std::pair<int, int> position;
//	int speedLevel;
//	std::pair<int, int> direction;
//	bool teleportFlag;
//
//	bool canShareTileWith(const GameEntity& gameEntity) const;
//
//	void shareTileWith(const GameEntity& gameEntity);
//
//	bool updateDirectionByUserInput(char userInput);
//
	void updatePosition(const GameState& gameState) override;
//
//	void updateTeleportFlag(const GameState& gameState);
//
//	void interactWithEntities(const GameState& gameState);
//
//	bool wasEaten(const GameState& gameState);
//
//	bool canAccessPosition(const GameState& gameState, std::pair<int, int> position) const;
//
};
