#pragma once

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

using namespace std;

class NOGADA
{
	void gotoxy(int x, int y)
	{
		COORD pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	void initialization(char Screen[][10], int size)
		// 화면을 0으로 초기화 하는 함수
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				Screen[i][j] = '0';
			}
		}
	}

	void randEnemy(char Screen[][10], int enemy, int enemyPos[][10])
	{
		int x, y;
		int enemyCount = 0;
		srand(time(NULL));
		while (enemyCount < enemy)
		{
			x = rand() % 9 + 1;
			y = rand() % 9 + 1;
			if (Screen[x][y] != '*')
			{
				Screen[x][y] = '*';
				enemyPos[x][y] = 1;
			}
			enemyCount++;
		}
	}

	void checkEnemy(char Screen[][10], int enemypos[][10], int enemy)
	{
		for (int i = 0; i < enemy; i++)
		{

		}
	}

	int check(int i, int j, int size)
	{
		if (i >= 0 && i < size && j >= 0 && j < size) return true;
		return false;
	}

	void gameStart()
	{
		char screen[10][10];
		int enemyPos[10][10];

		initialization(screen, 10);
		randEnemy(screen, 10, enemyPos);
		checkEnemy(screen, enemyPos, 10);
		char key;
	}

	int x = 0, y = 0;

	while (1)
	{
		gotoxy(x, y);
		if (_kbhit())
		{
			szChoice = _getch();
			switch (szChoice)
			{
			case 'w':
				y--;
				break;
			case 'a':
				x--;
				break;
			case 's':
				y++;
				break;
			case 'd':
				x++;
				break;
			case 'f':
				if (screen[x][y] == '*') {
					printf("#");
					gotoxy(x, y);
					screen[x][y] = "#";
				}
				break;
			case 'r':
				if (screen[x][y] == '*')
				{
					printf("Game Over \n");
					return 0;
				}
				else
				{
					printf(" ");
					printf("%c", Screen[x][y]);
				}
				break;
			}
		}
	}

};



void draw(char screen[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (screen[i][j] == 0) printf("□");
			else if (screen[i][j] == 1) printf("#");
			else if (screen[i][j] == 2) printf("0");
		}
		printf("\n");
	}
}

int map[10][10];
int hide[10][10];
srand((unsigned)time(NULL));
 
void initializeScreen(int screen[][10], int enemyPos[][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			screen[i][j] = 0;
			enemyPos[i][j] = 0;
		}
	}
}

void setEnemyPos(int enemyPos[][10], int enemyNumber)
{
	int count;
	while (enemyNumber < count)
	{
		int a, b;
		a = rand() % 9 + 1;
		b = rand() % 9 + 1;
		if (enemyPos[a][b] == 1) continue;
		else
		{
			enemyPos[a][b] == 1;
			count++;
		}
	}
}

while (1)
{
	draw(enemyPos);
}



