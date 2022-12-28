#include <iostream>
#include <string>
#include <time.h>

using namespace std;

// screen�� 0���� �ʱ�ȭ�ϴ� �Լ�
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

// 10x10 ȭ�鿡 ���� 10�� ���� �����ϴ� �Լ�
void setEnemy(char screen[][10], char enemyPos[][10])
{
	int enemyNumber = 10; // ���� 10��
	int count = 0;

	while (enemyNumber > count) // ���� ������ŭ while���� �ݺ�
	{
		int x, y;
		srand(time(NULL)); // ���� ����
		x = rand() % 9;
		y = rand() % 9;
		if (screen[x][y] != '*') // ���ڰ� �����Ǿ� �����ʴٸ�
		{
			screen[x][y] = '*'; // ���� ����
			enemyPos[x][y] = 1; // ���� ��ġ ����
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