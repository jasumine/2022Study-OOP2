#pragma once
#include "GameObject.h"

class Player :
    public GameObject
{
	void processInput()
	{
		int key;
		int minor;

		if (!_kbhit()) return; // 입력이 없으면 아무것도 하지 않겠다.
		Borland::GotoXY(0, 25);
		key = _getch();

		printf("\nplayer key is %c %d\n", key, key);

		Position pos = getPos();

		switch (key)
		{
			/*
		case 224:
			minor = _getch();
			printf("player minor key is %c  %x %d\n", minor, minor, minor);
			switch (minor)
			{
			case 'K':
				pos.x--;
				break;
			case 'M':
				pos.x++;
				break;
			case 'P':
				pos.y++;
				break;
			case 'H':
				pos.y--;
				break;
			}*/
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
		case 'r':
			&screen.draw(getPos(), 'X');
			break;
		}
		setPos(pos);
	}

public:
    Player(int x, int y, Screen &screen) : GameObject('>', x, y, screen) {}

	void update() override 
	{
		processInput();

	}

	
};

