#include <map>
#include "../../GameEntity.h"
#include "Wanderer.h"
#include "WandererShareTile.h"
#include "WandererCanShareTile.h"
#include "WandererCanBeEaten.h"
#include "../../Logger.h"
class Interaction;
Wanderer::Wanderer
(
	char symbol, 
	std::pair<int, int> position, 
	int speedLevel, 
	std::pair<int, int> direction,
	bool teleportFlag
)
:
Imitator
(
	symbol,
	position,
	speedLevel,
	direction,
	teleportFlag
)
{
}

Wanderer::Wanderer(const Wanderer& wanderer) : Imitator(wanderer)
{
}
Wanderer::~Wanderer() = default;
//
//char Wanderer::getSymbol() const
//{
//	return this->symbol;
//}
//std::pair<int, int> Wanderer::getPosition() const
//{
//	return this->position;
//}
//void Wanderer::teleportToPosition(std::pair<int, int> position)
//{
//	startLog();
//	if(!this->teleportFlag)
//	{
//		this->position = position;
//		this->teleportFlag = true;
//	}
//}
//void Wanderer::acceptInteraction(Interaction& interaction) const 
//{
//	interaction.interact(*this);	
//}
//
//bool Wanderer::canShareTileWith(const GameEntity& gameEntity)  const
//{
//	WandererCanShareTile wandererCanShareTile;
//	gameEntity.acceptInteraction(wandererCanShareTile);
//	return wandererCanShareTile.canShare;
//}
//void Wanderer::shareTileWith(const GameEntity& gameEntity) 
//{
//	WandererShareTile wandererShareTile(*this);	
//	gameEntity.acceptInteraction(wandererShareTile);
//}
std::shared_ptr<GameEntity> Wanderer::clone() const
{
	std::shared_ptr<Wanderer> clonedWanderer = std::make_shared<Wanderer>(*this);
	return clonedWanderer;
}
std::shared_ptr<GameEntity> Wanderer::update(const GameState& gameState) const
{
	startLog();
	log("using overrided method\n");
	std::shared_ptr<Wanderer> updatedWanderer = std::make_shared<Wanderer>(*this);
	return updatedWanderer;
	if(updatedWanderer->wasEaten(gameState))
	{
		return nullptr;
	}
	updatedWanderer->interactWithEntities(gameState);
	updatedWanderer->updateTeleportFlag(gameState);
	updatedWanderer->updatePosition(gameState);
	updatedWanderer->updateDirectionByUserInput(gameState.getUserInput());
	return updatedWanderer;
}
//bool Wanderer::updateDirectionByUserInput(char userInput)
//{
//	std::map<char, std::pair<int, int>> directionByUserInput =
//	{
//		{'k', {-1,  0}},
//		{'h', { 0, -1}},
//		{'l', { 0, +1}},
//		{'j', {+1,  0}}
//	};
//	if(directionByUserInput.find(userInput) == directionByUserInput.end())
//	{
//		return false;
//	}
//	this->direction = directionByUserInput[userInput];
//	return true;
//}
//
void Wanderer::updatePosition(const GameState& gameState)
{
	if(this->speedLevel < gameState.getSpeedLevel())
	{
		return;
	}
	int updatedPositionFirst = this->position.first + this->direction.first;
	int updatedPositionSecond= this->position.second + this->direction.second;
	std::pair<int, int> updatedPosition = {updatedPositionFirst, updatedPositionSecond};
	if(this->canAccessPosition(gameState, updatedPosition))
	{
		startLog();
		this->position = updatedPosition;
	}
}
//void Wanderer::updateTeleportFlag(const GameState& gameState)
//{
//	if(this->speedLevel < gameState.getSpeedLevel())
//	{
//		return;
//	}
//	this->teleportFlag = false;
//}
//void Wanderer::interactWithEntities(const GameState& gameState)
//{
//	std::vector<std::shared_ptr<GameEntity>> entitiesOnSameTile = gameState.getEntitiesByPosition(this->position);
//	for(std::shared_ptr<GameEntity> entity : entitiesOnSameTile)
//	{
//		this->shareTileWith(*entity);
//	}
//}
//bool Wanderer::wasEaten(const GameState& gameState)
//{
//	std::vector<std::shared_ptr<GameEntity>> entitiesOnSameTile = gameState.getEntitiesByPosition(this->position);
//	for(std::shared_ptr<GameEntity> entity : entitiesOnSameTile)
//	{
//		WandererCanBeEaten wandererCanBeEaten;
//		entity->acceptInteraction(wandererCanBeEaten);
//		if(wandererCanBeEaten.canBeEaten)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//bool Wanderer::canAccessPosition(const GameState& gameState, std::pair<int, int> position) const
//{
//	std::vector<std::shared_ptr<GameEntity>> entitiesOnSameTile = gameState.getEntitiesByPosition(position);
//	if(!gameState.validPosition(position))
//	{
//		return false;
//	}
//	for(std::shared_ptr<GameEntity> entity : entitiesOnSameTile)
//	{
//		if(!this->canShareTileWith(*entity))
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
