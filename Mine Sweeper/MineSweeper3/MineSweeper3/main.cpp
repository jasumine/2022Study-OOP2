#include <iostream>
#include <string>
#include <time.h>

using namespace std;

// screen을 0으로 초기화하는 함수
void initialization(char screen[][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			screen[i][j] = '0';
		}
		printf("\n");
	}
}

// 10x10 화면에 지뢰 10개 랜덤 생성하는 함수
void setEnemy(char screen[][10], char enemyPos[][10])
{
	int enemyNumber = 10; // 지뢰 10개
	int count = 0;

	while (enemyNumber > count) // 지뢰 개수만큼 while문을 반복
	{
		int x, y;
		srand(time(NULL)); // 랜덤 생성
		x = rand() % 9;
		y = rand() % 9;
		if (screen[x][y] != '*') // 지뢰가 생성되어 있지않다면
		{
			screen[x][y] = '*'; // 지뢰 생성
			enemyPos[x][y] = 1; // 지뢰 위치 저장
		}
		count++;
	}

}

int main() 
{
	char screen[10][10];
	char enemyPos[10][10];

	initialization(screen);
	setEnemy(screen, enemyPos);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << screen[i][j] << endl;
		}
	}


	return 0;
}