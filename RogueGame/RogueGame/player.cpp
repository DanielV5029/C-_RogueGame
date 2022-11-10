#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include "player.h"
using namespace std;

void Player::handleInput()
{
	//player movement
	newPlayerPositionX = playerPositionX;
	newPlayerPositionY = playerPositionY;
	if (GetKeyState(VK_UP) & 0x8000)
	{
		newPlayerPositionY = playerPositionY - 1;
	}

	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		newPlayerPositionY = playerPositionY + 1;
	}

	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		newPlayerPositionX = playerPositionX + 1;
	}

	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		newPlayerPositionX = playerPositionX - 1;
	}
}

void Player::collider()
{
	char nextMove = level[newPlayerPositionY * levelWidth + newPlayerPositionX];
	
	//if it collides with the wall
	switch (nextMove)
	{
	case 'a':
		newPlayerPositionX = playerPositionX;
		newPlayerPositionY = playerPositionY;
		break;
	case 'H': //if player collides with H on the array of the map
		health++; //health goes up by 1
		level[newPlayerPositionY * levelWidth + newPlayerPositionX] = ' '; //changes the letter to blank space
		gotoScreenPosition(7, levelHeight + 7); //goes to this screen position
		std::cout << healthChar; //prints H in the inventory gui
		break;
	case 'A': //if player collides with A on the array of the map
		armor++; //armor goes up by 1
		level[newPlayerPositionY * levelWidth + newPlayerPositionX] = ' '; //changes the letter to blank space
		gotoScreenPosition(19, levelHeight + 7); //goes to this screen position
		std::cout << armorChar; //prints A in the inventory gui
		break;
	}
}