#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include "inventory.h"
using namespace std;

void Inventory::dropItem(Map& m, Player& p)
{
	//if 1 is pressed then health is chosen
	if (GetKeyState('1'))
	{


		m.gotoScreenPosition(2, m.levelHeight + 2);
		std::cout << "Inventory 1 picked";

		//if the health in inventory
		if (p.health >= 1)
		{
			//if f is pressed then drop item infront of player and print the item
			if (GetAsyncKeyState('F'))
			{
				if (m.level[(p.playerPositionY)*m.levelWidth + p.playerPositionX + 1] == ' ')
				{
					m.gotoScreenPosition(p.playerPositionX + 1, p.playerPositionY);
					std::cout << p.healthChar;
					m.level[(p.newPlayerPositionY)*m.levelWidth + p.newPlayerPositionX + 1] = 'H';
					p.health--;
					if (p.health == 0)
					{
						m.gotoScreenPosition(7, m.levelHeight + 7);
						std::cout << ' ';
					}
				}
				else if (m.level[p.playerPositionY * m.levelWidth + (p.playerPositionX - 1)] == ' ')
				{
					m.gotoScreenPosition(p.playerPositionX - 1, p.playerPositionY);
					std::cout << p.healthChar;
					m.level[p.newPlayerPositionY * m.levelWidth + (p.newPlayerPositionX - 1)] = 'H';
					p.health--;
					if (p.health == 0)
					{
						m.gotoScreenPosition(7, m.levelHeight + 7);
						std::cout << ' ';
					}
				}
				else if (m.level[(p.playerPositionY - 1) * m.levelWidth + p.playerPositionX] == ' ')
				{
					m.gotoScreenPosition(p.playerPositionX, p.playerPositionY - 1);
					std::cout << p.healthChar;
					m.level[(p.newPlayerPositionY - 1) * m.levelWidth + p.newPlayerPositionX] = 'H';
					p.health--;
					if (p.health == 0)
					{
						m.gotoScreenPosition(7, m.levelHeight + 7);
						std::cout << ' ';
					}
				}
				else
				{
					m.gotoScreenPosition(p.playerPositionX, p.playerPositionY + 1);
					std::cout << p.healthChar;
					m.level[(p.newPlayerPositionY + 1) * m.levelWidth + p.newPlayerPositionX] = 'H';
					p.health--;
					if (p.health == 0)
					{
						m.gotoScreenPosition(7, m.levelHeight + 7);
						std::cout << ' ';
					}
				}

			}
			m.gotoScreenPosition(2, m.levelHeight + 9);
			std::cout << "Health available!"; // if health is avialable prompt health available message
		}
		else
		{

			m.gotoScreenPosition(2, m.levelHeight + 9);//if health is not avialable prompt inventory empty message
			std::cout << "Inventory Empty!";
		}
	}
	else if (GetKeyState('2')) //if 2 is pressed then armor is chosen
	{
		m.gotoScreenPosition(2, m.levelHeight + 2);
		std::cout << "Inventory 2 picked";

		//if the armor is in inventory
		if (p.armor >= 1)
		{
			//if f is pressed then drop item infront of player and print the item
			if (GetAsyncKeyState('F'))
			{
				if (m.level[(p.playerPositionY)*m.levelWidth + p.playerPositionX + 1] == ' ')
				{
					m.gotoScreenPosition(p.playerPositionX + 1, p.playerPositionY);
					std::cout << p.armorChar;
					m.level[(p.newPlayerPositionY)*m.levelWidth + p.newPlayerPositionX + 1] = 'A';
					p.armor--;
					if (p.armor == 0)
					{
						m.gotoScreenPosition(19, m.levelHeight + 7);
						std::cout << ' ';
					}
				}
				else if (m.level[p.playerPositionY * m.levelWidth + (p.playerPositionX - 1)] == ' ')
				{
					m.gotoScreenPosition(p.playerPositionX - 1, p.playerPositionY);
					std::cout << p.armorChar;
					m.level[p.newPlayerPositionY * m.levelWidth + (p.newPlayerPositionX - 1)] = 'A';
					p.armor--;
					if (p.armor == 0)
					{
						m.gotoScreenPosition(19, m.levelHeight + 7);
						std::cout << ' ';
					}
				}
				else if (m.level[(p.playerPositionY - 1) * m.levelWidth + p.playerPositionX] == ' ')
				{
					m.gotoScreenPosition(p.playerPositionX, p.playerPositionY - 1);
					std::cout << p.armorChar;
					m.level[(p.newPlayerPositionY - 1) * m.levelWidth + p.newPlayerPositionX] = 'A';
					p.armor--;
					if (p.armor == 0)
					{
						m.gotoScreenPosition(19, m.levelHeight + 7);
						std::cout << ' ';
					}
				}
				else
				{
					m.gotoScreenPosition(p.playerPositionX, p.playerPositionY + 1);
					std::cout << p.armorChar;
					m.level[(p.newPlayerPositionY + 1) * m.levelWidth + p.newPlayerPositionX] = 'A';
					p.armor--;
					if (p.armor == 0)
					{
						m.gotoScreenPosition(19, m.levelHeight + 7);
						std::cout << ' ';
					}
				}

			}
			m.gotoScreenPosition(2, m.levelHeight + 9);
			std::cout << "Armor available!"; //if armor is avialable prompt armor available message
		}
		else
		{
			m.gotoScreenPosition(2, m.levelHeight + 9);
			std::cout << "Inventory Empty!"; //if armor is not avialable prompt inventory empty message
		}
	}
	else
	{
		//blanks out the inventory information
		m.gotoScreenPosition(2, m.levelHeight + 2);
		std::cout << "                  ";
		m.gotoScreenPosition(2, m.levelHeight + 9);
		std::cout << "                 ";
	}

}
