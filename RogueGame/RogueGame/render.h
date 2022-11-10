#pragma once
#include <string>
#include <rpcndr.h>
#include "map.h"
#include "player.h"
#include "map.h"
using namespace std;

class Render : public Player
{
public:
	void renderPlayer();
	void renderGUI();

};