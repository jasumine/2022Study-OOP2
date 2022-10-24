#pragma once
#include <conio.h>
#include "GameObject.h"

class Player :
    public GameObject
{

	auto processInput()
	{
		auto pos = getPos();
		if (input.getKeyDown(VK_LEFT)) { // left arraw
			pos.x--;
		}
		else if (input.getKeyDown(VK_RIGHT)) { // right arraw
			pos.x++;
		}
		if (input.getKeyDown(VK_UP)) { // up arraw
			pos.y--;
		}
		if (input.getKeyDown(VK_DOWN)) { // down arraw
			pos.y++;
		}

		setPos(pos);

	}

public:
    Player(int x, int y, Screen& screen) 
		: GameObject('>', x, y, screen) 
	{}


	void update() override
	{
		processInput();
	}

	
};

