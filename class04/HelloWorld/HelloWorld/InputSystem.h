#pragma once
#include <stdio.h>
#include <conio.h>
#include "Utils.h"

using namespace std;

class InputSystem
{
	// 키를 2개 읽는다.
	int key;
	int minor;

public:
	InputSystem() : key(0), minor(0) {}
	virtual ~InputSystem() {}

	void readEveryFrame()  // 매 프레임마다 읽는 함수
	{
		key = -1; minor = 0;

		if (!_kbhit()) return; // 키를 안누를경우 return;
		
		key = _getch();

		// debug 용
		Borland::GotoXY(0, 23);
		printf("player key is %c   %x %d\n", key, key, key);

		switch (key)
		{
		case 224: // left, right, up, down arrow key
			minor = _getch(); // 키를 누르는지 안누르는지 확인
			printf("minor is %c   %x %d\n", key, key, key);
			break;

		case 0: // F1, F2 ...
			minor = _getch();
			printf("minor is is %c   %x %d\n", key, key, key);
			break;
		default :
			printf("        ");
			break;

		}
	}

	auto getKey(int key)
	{ // -1 -> 키를 눌렀을때 
		return (this->key != -1 && this->key == key);
	}

	auto getKey(int key, int minor)
	{
		return (this->key != -1 &&
				this->minor != -1 &&
				this->key == key &&
				this->minor == minor);
	}
};

