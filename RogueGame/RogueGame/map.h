#pragma once
#include <string>
#include <rpcndr.h>
#include "player.h"

using namespace std;

class Map
{
public:
	void readMap(string path);
	void gotoScreenPosition(short C, short R);


	int levelHeight;
	int levelWidth;
	char* level = nullptr;
	string arrayStore = "";
	boolean widthFound = false;
};
