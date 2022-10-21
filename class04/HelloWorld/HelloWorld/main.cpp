#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include "GameObject.h"
#include "Utils.h"
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"
#include "InputSystem.h"

using namespace std;
// �ڷ���, return�� ��Ȯ�� ��� auto�� ����ϸ� �ڵ����� ó���ȴ�.
// staic ������ �����Ұ�� ���� �� ���ڴ� �빮�ڷ� ������Ѵ�.

// #define WINDOW_INPUT_TEST
// �ּ�ó���� ��� �ڵ尡 Ȱ��ȭ �ȴ�.

int main()
{
#ifdef WINDOW_INPUT_TEST

#endif

	Screen screen(20, 81);
	InputSystem input;
	Player player{ 2, 4, screen, input };
	Enemy enemy1{ rand() % 80, rand() % 20, screen, input};

	while (1)
	{
		screen.clear();
		input.readEveryFrame();

		//screen.draw(player.getPos(), player.getShape());
		//screen.draw(enemy1.getPos(), enemy1.getShape());
		
		player.draw();
		enemy1.draw();


		screen.render();
		
		
		player.update();
		enemy1.update();
	}
#endif
	
	return 0;
}