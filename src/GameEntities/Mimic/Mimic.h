	#pragma once
#include "../../GameEntity.h"
#include "../Imitator/Imitator.h"
class GameEntity;
class Interaction;
class Mimic : public Imitator 
{
public:
	Mimic
	(
		char symbol, 
		std::pair<int, int> position, 
		int speedLevel, 
		std::pair<int, int> direction = {1, 0}, 
		bool teleportFlag = false
	);

	using Imitator::operator =;
	Mimic& operator=(const Mimic& mimic) 
	{
	    Imitator::operator=(mimic);
	    return *this;
	}
	Mimic(const Mimic& mimic);

	~Mimic();
protected:
	std::shared_ptr<GameEntity> clone() const override;
	std::shared_ptr<GameEntity> update(const GameState& gameState) const override;
	void updatePosition(const GameState& gameState) override;
	bool updateDirectionByUserInput(char userInput) override;
};
