#include <map>
#include "../../GameEntity.h"
#include "Player.h"
#include "PlayerShareTile.h"
#include "PlayerCanShareTile.h"
#include "PlayerEat.h"
#include "PlayerCanEat.h"
#include "PlayerCanBeEaten.h"

#include "../../Logger.h"
class Interaction;
Player::Player(char symbol, std::pair<int, int> position, int speedLevel, std::pair<int, int> direction, int lifeCount, int score)
:
	symbol(symbol),
	position(position),
	speedLevel(speedLevel),
	direction(direction),
	lifeCount(lifeCount),
	score(score)
{
}

Player::Player(const Player& player)
{
	this->symbol = player.symbol;
	this->speedLevel= player.speedLevel;
	this->position = player.position;
	this->direction = player.direction;
	this->lifeCount = player.lifeCount;
	this->score = player.score;
}
// TODO: assignment operator
Player::~Player() = default;

char Player::getSymbol() const
{
	// FIX
	return this->symbol;
}

std::pair<int, int> Player::getPosition() const
{
	return this->position;
}

int Player::getScore() const
{
	return this->score;
}

int Player::getLifeCount() const
{
	return this->lifeCount;
}

void Player::acceptInteraction(Interaction& interaction) const 
{
	interaction.interact(*this);	
}

bool Player::canEat(const GameEntity& gameEntity) const
{
	PlayerCanEat playerCanEat;
	gameEntity.acceptInteraction(playerCanEat);
	return playerCanEat.canEat;
}

void Player::eat(const GameEntity& gameEntity) 
{
	PlayerEat playerEat(*this);	
	gameEntity.acceptInteraction(playerEat);
}

bool Player::canShareTileWith(const GameEntity& gameEntity)  const
{
	PlayerCanShareTile playerCanShareTile;
	gameEntity.acceptInteraction(playerCanShareTile);
	return playerCanShareTile.canShare;
}

void Player::shareTileWith(const GameEntity& gameEntity) 
{
	PlayerShareTile playerShareTile(*this);	
	gameEntity.acceptInteraction(playerShareTile);
}

std::shared_ptr<Player> Player::clonePlayer() const
{
	std::shared_ptr<Player> clonedPlayer = std::make_shared<Player>(*this);
	return clonedPlayer;
}

std::shared_ptr<GameEntity> Player::clone() const
{
	return this->clonePlayer();
}

std::shared_ptr<Player> Player::updatePlayer(const GameState& gameState) const
{
	std::shared_ptr<Player> updatedPlayer = std::make_shared<Player>(*this);
	updatedPlayer->updateLifeCount(gameState);
	if(updatedPlayer->lifeCount <= 0)
	{
		return nullptr;
	}
	updatedPlayer->updateScore(gameState);
	updatedPlayer->updatePosition(gameState);
	updatedPlayer->updateDirectionByUserInput(gameState.getUserInput());
	return updatedPlayer;
}
std::shared_ptr<GameEntity> Player::update(const GameState& gameState) const 
{
	return this->updatePlayer(gameState);
}
bool Player::updateDirectionByUserInput(char userInput)
{
	std::map<char, std::pair<int, int>> directionByUserInput =
	{
		{'k', {-1,  0}},
		{'h', { 0, -1}},
		{'l', { 0, +1}},
		{'j', {+1,  0}}
	};
	if(directionByUserInput.find(userInput) == directionByUserInput.end())
	{
		return false;
	}
	this->direction = directionByUserInput[userInput];
	return true;
}
void Player::updatePosition(const GameState& gameState)
{
	if(this->speedLevel < gameState.getSpeedLevel())
	{
		return;
	}
	int updatedPositionFirst = this->position.first + this->direction.first;
	int updatedPositionSecond= this->position.second+ this->direction.second;
	std::pair<int, int> updatedPosition = {updatedPositionFirst, updatedPositionSecond};
	if(this->canAccessPosition(gameState, updatedPosition))
	{
		this->position = updatedPosition;
	}
}
void Player::updateScore(const GameState& gameState)
{
	std::vector<std::shared_ptr<GameEntity>> entitiesOnSameTile = gameState.getEntitiesByPosition(this->position);
	for(std::shared_ptr<GameEntity> entity : entitiesOnSameTile)
	{
		// try to eat all entities on the same tile as player
		this->eat(*entity);
	}
}
void Player::updateLifeCount(const GameState& gameState)
{
	this->lifeCount -= this->wasEaten(gameState);
}
bool Player::wasEaten(const GameState& gameState)
{
	std::vector<std::shared_ptr<GameEntity>> entitiesOnSameTile = gameState.getEntitiesByPosition(this->position);
	for(std::shared_ptr<GameEntity> entity : entitiesOnSameTile)
	{
		PlayerCanBeEaten playerCanBeEaten;
		entity->acceptInteraction(playerCanBeEaten);
		if(playerCanBeEaten.canBeEaten)
		{
			return true;
		}
	}
	return false;
}

bool Player::canAccessPosition(const GameState& gameState, std::pair<int, int> position) const
{
	std::vector<std::shared_ptr<GameEntity>> entitiesOnSameTile = gameState.getEntitiesByPosition(this->position);
	for(std::shared_ptr<GameEntity> entity : entitiesOnSameTile)
	{
		if(!this->canShareTileWith(*entity))
		{
			return false;
		}
	}
	return true;
}

