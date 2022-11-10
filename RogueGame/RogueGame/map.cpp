#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include "map.h"

using namespace std;


void Map::readMap(string path)
{
	string line;
	ifstream mapLevel(path);

	//reset level
	if (mapLevel.is_open())
	{
		//Reset previous map
		levelHeight = 0;
		levelWidth = 0;
		if (level != NULL)
		{
			delete level;
		}
	}

	ifstream newLevel(path);

	//load file + find height and width
	if (newLevel.is_open())
	{
		while (getline(newLevel, line))
		{
			arrayStore += line;
			arrayStore.push_back('\n');
			char endOf = arrayStore.at(arrayStore.length() - 1);

			if (endOf == '\n')
			{
				if (widthFound == false)
				{
					levelWidth = arrayStore.length();
					widthFound = true;
				}
				levelHeight++;
			}
			cout << line << '\n';
		}

	}
	//Allocate the memory
	level = new char[levelWidth * levelHeight]{};

	//Add the characters into the array
	for (int i = 0; i < levelWidth; i++)
	{
		for (int j = 0; j < levelHeight; j++)
		{
			level[i * levelHeight + j] = arrayStore.at(i * levelHeight + j);
		}
	}


	gotoScreenPosition(9, levelHeight + 10);
	std::cout << "Width: " << levelWidth;
	gotoScreenPosition(9, levelHeight + 11);
	std::cout << "Height: " << levelHeight;

}

void Map::gotoScreenPosition(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
