/*#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

unsigned int playerPositionX = 2;
unsigned int playerPositionY = 2;
unsigned int healthPositionX = 1;
unsigned int healthPositionY = 1;
unsigned int gunPositionX = 0;
unsigned int gunPositionY = 0;
unsigned int newPlayerPositionX = playerPositionX;
unsigned int newPlayerPositionY = playerPositionY;

int health = 0;
int armor = 0;

char playerChar = 'P';
char healthChar = 'H';
char armorChar = 'A';

char* level = NULL;
int levelHeight;
int levelWidth;
string arrayStore = "";
boolean widthFound = false;


void gotoScreenPosition(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void readMap(string path)
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


void handleInput()
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

void collider()
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

void renderPlayer()
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

void renderGUI()
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

void dropItem()
{
	//vector<char>::iterator it; //iterator called it
	//it = myDoubleArray.begin(); //set iterator at the begining of the vector
	char infrontOfPlayer = level[newPlayerPositionX * levelHeight + newPlayerPositionY];
	//if 1 is pressed then health is chosen
	if (GetKeyState('1'))
	{

		//Need a while loop to iterate through all of the elements to find where 'H' is stored after "1" is pressed
		//You then set the iterator "it" to the index of where the first 'H' was found
		//Then when 'F' is pressed the item is dropped on screen and is erased from the vector array
		//Same process for when number 2 is pressed and the iterator is set where the first 'G' was found


		gotoScreenPosition(2, levelHeight + 2);
		std::cout << "Inventory 1 picked";

		//if the health in inventory
		if (health >= 1)
		{
			//if f is pressed then drop item infront of player and print the item
			if (GetAsyncKeyState('F'))
			{
				if (level[(playerPositionY ) *levelWidth + playerPositionX + 1] == ' ')
				{
					gotoScreenPosition(playerPositionX + 1, playerPositionY);
					std::cout << healthChar;
					level[(newPlayerPositionY) *levelWidth + newPlayerPositionX + 1] = 'H';
					health--;
					if (health == 0)
					{
						gotoScreenPosition(7, levelHeight + 7);
						std::cout << ' ';
					}
				}
				else if (level[playerPositionY * levelWidth + (playerPositionX - 1)] == ' ')
				{
					gotoScreenPosition(playerPositionX - 1, playerPositionY);
					std::cout << healthChar;
					level[newPlayerPositionY * levelWidth + (newPlayerPositionX - 1)] = 'H';
					health--;
					if (health == 0)
					{
						gotoScreenPosition(7, levelHeight + 7);
						std::cout << ' ';
					}
				}
				else if (level[(playerPositionY - 1) * levelWidth + playerPositionX] == ' ')
				{
					gotoScreenPosition(playerPositionX, playerPositionY - 1);
					std::cout << healthChar;
					level[(newPlayerPositionY - 1) * levelWidth + newPlayerPositionX] = 'H';
					health--;
					if (health == 0)
					{
						gotoScreenPosition(7, levelHeight + 7);
						std::cout << ' ';
					}
				}
				else
				{
					gotoScreenPosition(playerPositionX, playerPositionY + 1);
					std::cout << healthChar;
					level[(newPlayerPositionY + 1) * levelWidth + newPlayerPositionX] = 'H';
					health--;
					if (health == 0)
					{
						gotoScreenPosition(7, levelHeight + 7);
						std::cout << ' ';
					}
				}

			}
			gotoScreenPosition(2, levelHeight + 9);
			std::cout << "Health available!"; // if health is avialable prompt health available message
		}
		else
		{

			gotoScreenPosition(2, levelHeight + 9);//if health is not avialable prompt inventory empty message
			std::cout << "Inventory Empty!";
		}
	}
	else if (GetKeyState('2')) //if 2 is pressed then armor is chosen
	{
		gotoScreenPosition(2, levelHeight + 2);
		std::cout << "Inventory 2 picked";

		//if the armor is in inventory
		if (armor >= 1)
		{
			//if f is pressed then drop item infront of player and print the item
			if (GetAsyncKeyState('F'))
			{
				if (level[(playerPositionY) *levelWidth + playerPositionX + 1] == ' ')
				{
					gotoScreenPosition(playerPositionX + 1, playerPositionY);
					std::cout << armorChar;
					level[(newPlayerPositionY) *levelWidth + newPlayerPositionX + 1] = 'A';
					armor--;
					if (armor == 0)
					{
						gotoScreenPosition(19, levelHeight + 7);
						std::cout << ' ';
					}
				}
				else if (level[playerPositionY * levelWidth + (playerPositionX - 1)] == ' ')
				{
					gotoScreenPosition(playerPositionX - 1, playerPositionY);
					std::cout << armorChar;
					level[newPlayerPositionY * levelWidth + (newPlayerPositionX - 1)] = 'A';
					armor--;
					if (armor == 0)
					{
						gotoScreenPosition(19, levelHeight + 7);
						std::cout << ' ';
					}
				}
				else if (level[(playerPositionY - 1) * levelWidth + playerPositionX] == ' ')
				{
					gotoScreenPosition(playerPositionX, playerPositionY - 1);
					std::cout << armorChar;
					level[(newPlayerPositionY - 1) * levelWidth + newPlayerPositionX] = 'A';
					armor--;
					if (armor == 0)
					{
						gotoScreenPosition(19, levelHeight + 7);
						std::cout << ' ';
					}
				}
				else
				{
					gotoScreenPosition(playerPositionX, playerPositionY + 1);
					std::cout << armorChar;
					level[(newPlayerPositionY + 1) * levelWidth + newPlayerPositionX] = 'A';
					armor--;
					if (armor == 0)
					{
						gotoScreenPosition(19, levelHeight + 7);
						std::cout << ' ';
					}
				}

			}
			gotoScreenPosition(2, levelHeight + 9);
			std::cout << "Armor available!"; //if armor is avialable prompt armor available message
		}
		else
		{
			gotoScreenPosition(2, levelHeight + 9);
			std::cout << "Inventory Empty!"; //if armor is not avialable prompt inventory empty message
		}
	}
	else
	{
		//blanks out the inventory information
		gotoScreenPosition(2, levelHeight + 2);
		std::cout << "                  ";
		gotoScreenPosition(2, levelHeight + 9);
		std::cout << "                 ";
	}

}

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 800, 800, TRUE);

	readMap("Map.txt");

	while (true)
	{
		// Handles the input and updates the players position
		handleInput();

		//Collides with items
		collider();

		// Render the scene
		renderPlayer();

		// Render the GUI
		renderGUI();

		//Drop item from inventory
		dropItem();
	}

	system("pause");
}*/