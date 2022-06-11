#include "TeleportCanConnect.h"
TeleportCanConnect::TeleportCanConnect()
:
	canConnect(false)
{
}
void TeleportCanConnect::interact(const Wall&) 
{
	this->canConnect = false;
}
void TeleportCanConnect::interact(const Teleport&) 
{
	this->canConnect = true;
}
void TeleportCanConnect::interact(const PowerPellet&) 
{
	this->canConnect = false;
}
void TeleportCanConnect::interact(const RespawnPoint&) 
{
	this->canConnect = false;
}
void TeleportCanConnect::interact(const Coin&) 
{
	this->canConnect = false;
}
void TeleportCanConnect::interact(const Player&) 
{
	this->canConnect = false;
}
void TeleportCanConnect::interact(const Imitator&) 
{
	this->canConnect = false;
}
