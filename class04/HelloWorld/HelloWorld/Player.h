#pragma once
#include <conio.h>
#include "GameObject.h"

class Player :
    public GameObject
{
	auto processInput()
	{
		/*
		 int key;
		if (!_kbhit()) return;

		Borland::GotoXY(0, 21);
		key = _getch();
				
		Borland::GotoXY(1, 23);
		("player key is %c   %x %d\n", key, key, key);
		
		Borland::GotoXY(0, 21);
		auto pos = getPos();
		int minor;
		*/

		auto pos = getPos();
		if (input.getKey('w'))
		{
			pos.y--;
		}
		else if (input.getKey('a'))
		{
			pos.x--;
		}
		else if (input.getKey('s'))
		{
			pos.y++;
		}
		else if (input.getKey('d'))
		{
			pos.x++;
		}

		setPos(pos);
		/*
		switch (key) {
		case 224:
			auto minor = _getch();
			printf("player minor key is %c   %x %d\n", minor, minor, minor);
			switch (minor) {
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
			}
			break;
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
		*/
	}

public:
    Player(int x, int y, Screen& screen, InputSystem & input) 
		: GameObject('>', x, y, screen, input) {}


	void update() override
	{
		processInput();
	}

	void draw() override
	{
		GameObject::draw();
		screen.draw(getPos() +  Position{0, -1}, 'P'); // 현재위치 위에 Player 표시

	}

	
};

