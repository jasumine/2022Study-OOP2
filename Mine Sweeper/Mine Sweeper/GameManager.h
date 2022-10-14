#pragma once
#include <iostream>
#include "Utils.h"

using namespace std;

class GameManager
{
public:
	virtual ~GameManager() { }



	bool comparePos(Position& pos1, Position *pos[])
	{
		for (int i = 0; i < 10; i++)
		{
			if (pos[i]->x == pos1.x && pos[i]->y == pos1.y)
				return true;
			return false;
		}
	}
};

