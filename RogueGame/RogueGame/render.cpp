#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include "render.h"
using namespace std;

void Render::renderPlayer()
{
	// Blank old enemy position
	gotoScreenPosition(playerPositionX, playerPositionY);
	std::cout << ' ';

	// Draw new enemy position
	gotoScreenPosition(newPlayerPositionX, newPlayerPositionY);
	std::cout << playerChar;

	playerPositionX = newPlayerPositionX;
	playerPositionY = newPlayerPositionY;

	Sleep(60);
}

void Render::renderGUI()
{

	//writes the gui on the screen
	gotoScreenPosition(9, levelHeight + 4);
	std::cout << "Inventory";
	gotoScreenPosition(2, levelHeight + 5);
	std::cout << "    [1]    |    [2]";
	gotoScreenPosition(13, levelHeight + 6);
	std::cout << "|";
	gotoScreenPosition(13, levelHeight + 7);
	std::cout << "|";
}