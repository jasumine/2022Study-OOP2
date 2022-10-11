#define _CRT_SECURE_NO_WARNINS

#include <iostream>
#include <cstring>
#include <string>
#include "GameObject.h"
#include "Utils.h"
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

int main()
{
	Player player { 2, 4 }; // player 커서 위치 (움직임)
	Enemy enemy { 10, 10 }; // enemy 위치 (고정) -> 10개
	Screen screen(30, 81); // 화면의 크기
	
	while (1)
	{
		screen.clear(); // 화면 초기화
		
		screen.draw(player.getPos(), player.getShape()); // player 위치
		screen.draw(enemy.getPos(), enemy.getShape()); // enemy 위치
		
		screen.render(); // 

		player.processInput(); // 움직임 구현
	}

	return 0;
}