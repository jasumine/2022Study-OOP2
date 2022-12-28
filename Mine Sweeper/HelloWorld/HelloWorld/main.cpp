#define _CRT_SECURE_NO_WARNINGS

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
	Player player{ 2, 4 };
	Enemy enemy{ 10, 10 };

	Screen screen(10, 10);


	while (1)
	{
		screen.clear();

		screen.draw(player.getPos(), player.getShape());
		screen.draw(enemy.getPos(), enemy.getShape());

		screen.render();

		player.processInput();
	}
	
	return 0;
}