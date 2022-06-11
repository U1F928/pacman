#include "TeleportCanConnect.h"
TeleportCanConnect::TeleportCanConnect()
:
	canConnect(false)
{
}
void TeleportCanConnect::interact(const Wall& wall) 
{
	this->canConnect = false;
}
void TeleportCanConnect::interact(const Teleport& teleport) 
{
	this->canConnect = true;
}
void TeleportCanConnect::interact(const PowerPellet& powerPellet) 
{
	this->canConnect = false;
}
void TeleportCanConnect::interact(const Coin& coin) 
{
	this->canConnect = false;
}
void TeleportCanConnect::interact(const Player& player) 
{
	this->canConnect = false;
}
