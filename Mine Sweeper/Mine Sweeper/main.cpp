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
	Player player { 2, 4 }; // player Ŀ�� ��ġ (������)
	Enemy enemy { 10, 10 }; // enemy ��ġ (����) -> 10��
	Screen screen(30, 81); // ȭ���� ũ��
	
	while (1)
	{
		screen.clear(); // ȭ�� �ʱ�ȭ
		
		screen.draw(player.getPos(), player.getShape()); // player ��ġ
		screen.draw(enemy.getPos(), enemy.getShape()); // enemy ��ġ
		
		screen.render(); // 

		player.processInput(); // ������ ����
	}

	return 0;
}