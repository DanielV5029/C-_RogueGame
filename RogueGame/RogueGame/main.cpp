#include <rend.h>
#include "map.h"
#include "player.h"
#include "render.h"

#include "inventory.h"
#include "Inventory.h"
master

int main()
{
	Player myPlayer;
	Render myRender;

	Inventory inventory;

	Inventory myInventory;



	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 800, 800, TRUE);
	myPlayer.readMap("Map.txt");


	while (true)
	{
		// Handles the input and updates the players position
		myPlayer.handleInput();

		//Collides with items
		myPlayer.collider();

		// Render the scene
		myRender.renderPlayer();

		// Render the GUI
		myRender.renderGUI();

		//Drop item from inventory

		inventory.dropItem(myMap, myPlayer);


		myInventory.dropItem(myMap, myPlayer);

		itemDrop.dropItem();

	}

	system("pause");
}