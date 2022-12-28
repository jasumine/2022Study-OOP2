#pragma once
#include "GameObject.h"

class Player :
    public GameObject
{

public:
    Player(int x, int y) : GameObject('>', x, y) {}

	void processInput()
	{
		char key;

		cin >> key;

		Borland::GotoXY(0, 21);
		printf("key is %c %d\n", key, key);

		Position pos = getPos();

		switch (key) {
		case 'w':
			pos.y--;
			break;
		case 'a':
			pos.x--;
			break;
		case 's':
			pos.y++;
			break;
		case 'd':
			pos.x++;
			break;
		}

		setPos(pos);

	}
};

