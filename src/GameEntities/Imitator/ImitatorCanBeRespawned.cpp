#include "ImitatorCanBeRespawned.h"
ImitatorCanBeRespawned::ImitatorCanBeRespawned()
:
	canBeRespawned(false)
{
}
void ImitatorCanBeRespawned::interact(const Wall&) 
{
	this->canBeRespawned = false;
}
void ImitatorCanBeRespawned::interact(const Teleport&) 
{
	this->canBeRespawned = false;
}
void ImitatorCanBeRespawned::interact(const PowerPellet&) 
{
	this->canBeRespawned = false;
}
void ImitatorCanBeRespawned::interact(const RespawnPoint&) 
{
	this->canBeRespawned = true;
}
void ImitatorCanBeRespawned::interact(const Coin&) 
{
	this->canBeRespawned = false;
}
void ImitatorCanBeRespawned::interact(const Player&) 
{
	this->canBeRespawned = false;
}
void ImitatorCanBeRespawned::interact(const Imitator&) 
{
	this->canBeRespawned = false;
}
void ImitatorCanBeRespawned::interact(const Wanderer&) 
{
	this->canBeRespawned = false;
}
void ImitatorCanBeRespawned::interact(const Mimic&) 
{
	this->canBeRespawned = false;
}
