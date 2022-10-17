#pragma once
#include <stdio.h>
#include <conio.h>
#include "Utils.h"

using namespace std;

class InputSystem
{
	// Ű�� 2�� �д´�.
	int key;
	int minor;

public:
	InputSystem() : key(0), minor(0) {}
	virtual ~InputSystem() {}

	void readEveryFrame()  // �� �����Ӹ��� �д� �Լ�
	{
		key = -1; minor = 0;

		if (!_kbhit()) return; // Ű�� �ȴ������ return;
		
		key = _getch();

		// debug ��
		Borland::GotoXY(0, 23);
		printf("player key is %c   %x %d\n", key, key, key);

		switch (key)
		{
		case 224: // left, right, up, down arrow key
			minor = _getch(); // Ű�� �������� �ȴ������� Ȯ��
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
	{ // -1 -> Ű�� �������� 
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

