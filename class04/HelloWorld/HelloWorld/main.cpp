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
// 자료형, return이 명확한 경우 auto를 사용하면 자동으로 처리된다.
// staic 변수로 선언할경우 제일 앞 글자는 대문자로 적어야한다.

// #define WINDOW_INPUT_TEST
// 주석처리할 경우 코드가 활성화 된다.

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