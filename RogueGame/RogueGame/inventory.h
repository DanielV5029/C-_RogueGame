#pragma once
#include <string>
#include <rpcndr.h>
#include "map.h"
#include "player.h"
using namespace std;

class Inventory
{
public:
	void dropItem(Map& m, Player& p);

};