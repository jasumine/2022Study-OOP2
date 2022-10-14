#pragma once
#include "GameObject.h"

class Player :
    public GameObject
{
	void processInput()
	{
		char key;

		if (!_kbhit()) return; // 입력이 없으면 아무것도 하지 않겠다.
		Borland::GotoXY(0, 21);
		key = _getch();

		printf("\nkey is %c %d\n", key, key);

		Position pos = getPos();

		switch (key)
		{
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

public:
    Player(int x, int y) : GameObject('>', x, y) {}

	void update() override 
	{
		processInput();

	}

	
};

