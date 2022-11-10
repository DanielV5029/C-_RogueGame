#pragma once
#include <string>
#include <rpcndr.h>
#include "map.h"
using namespace std;

class Player : public Map
{
public:
	void handleInput();
	void collider();

	int health = 0;
	int armor = 0;
	char playerChar = 'P';
	char healthChar = 'H';
	char armorChar = 'A';
	char nextMove;
	unsigned int playerPositionX = 2;
	unsigned int playerPositionY = 2;
	unsigned int newPlayerPositionX = playerPositionX;
	unsigned int newPlayerPositionY = playerPositionY;
};