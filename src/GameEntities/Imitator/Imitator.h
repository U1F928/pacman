#pragma once
#include "../../GameEntity.h"
class GameEntity;
class Interaction;
/**
  * @brief Class representing the imitator ghost
  */
class Imitator : public GameEntity
{
public:
   /**
     * @brief Constructor
     * @param symbol, symbol that represents the entity
     * @param position, position of the imitator
     * @param speedLevel, speedLevel of the imitator
     * @param direction, direction of the imitator
     * @param teleportFlag, flag which tells whether the imitator was teleported during last update
     */
	Imitator
	(
		char symbol, 
		std::pair<int, int> position, 
		int speedLevel, 
		std::pair<int, int> direction = {1, 0}, 
		bool teleportFlag = false
	);

   /**
     * @brief Assignment operator
     * @param imitator, another instance of imitator
     * @return returns itself
     */
	Imitator& operator = (const Imitator& imitator);
   /**
     * @brief Copy constructor, implemented by assignment operator
     * @param imitator, another instance of imitator
     */
	Imitator(const Imitator& imitator);

   /**
     * @brief Destructor, default
     */
	virtual ~Imitator();

	char getSymbol() const override; 

	std::pair<int, int> getPosition() const override;

	std::pair<int, int> getDirection() const override;

   /**
     * @brief Try (teleportFlag) to teleport this imitator to the given position
     * @param position, the given position
     */
	void teleportToPosition(std::pair<int, int> position);

	void acceptInteraction(Interaction& interaction) const override;

	virtual std::shared_ptr<GameEntity> clone() const override;

	virtual std::shared_ptr<GameEntity> update(const GameState& gameState) const override;
protected:
	char symbol; // symbol representing this imitator
	std::pair<int, int> position; // position of this imitator
	int speedLevel; // speed level of this imitator
	std::pair<int, int> direction; // direction of this imitator
	bool teleportFlag; // teleport flag, true if this imitator has been teleported in it's latest update

   /**
     * @brief Checks whether imitator can share tile (position) with the given entity
     * @param gameEntity, the given entity
     * @return true if a tile can be shared, false otherwise
     */
	bool canShareTileWith(const GameEntity& gameEntity) const;
   /**
     * @brief Share file with the given entity
     * @param gameEntity, the given entity 
     */
	void shareTileWith(const GameEntity& gameEntity);
   /**
     * @brief Update imitator's direction according to the user's input
     * @param userInput, the user's input
     */
	virtual bool updateDirectionByUserInput(char userInput);

   /**
     * @brief Update imitator's position according to the given game state
     * @param gameState, the given game state
     */
	virtual void updatePosition(const GameState& gameState);
   /**
     * @brief Update imitator's teleport flag according to the given game state
     * @param gameState, the given game state
     */
	void updateTeleportFlag(const GameState& gameState);
   /**
     * @brief Respawn this imitator at nearest entity that can respawn him
     * @param gameState 
     */
	void respawn(const GameState& gameState);
   /**
     * @brief Check whether imitator can be respawned by the given entity
     * @param gameEntity, the given entity
     * @return true if imitator can be respawned, false otherwise
     */
	bool canBeRespawnedBy(const GameEntity& gameEntity);
	/**
     * @brief Check whether imitator can be respawned by accessing the given position (that has the needed entity on it)
     * @param gameEntity, the given entity
     * @return true if imitator can be respawned, false otherwise
     */
	bool canBeRespawnedOnPosition(const GameState& gameState, std::pair<int, int> position);
   /**
     * @brief Interact with entities on the current position
     * @param gameState
     */
	void interactWithEntities(const GameState& gameState);
   /**
     * @brief Check whether this imitator has been eaten by another entity
     * @param gameState
     * @return true if this imitator has been eaten, false otherwise
     */
	bool wasEaten(const GameState& gameState);
   /**
     * @brief Check whether this imitator can access the given position (some other entity isn't blocking it)
     * @param gameState
     * @return true if this imitator can access the given position, false otherwise
     */
	bool canAccessPosition(const GameState& gameState, std::pair<int, int> position) const;
};
