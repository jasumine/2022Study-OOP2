#define _CRT_SECURE_NO_WARNINS

#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "GameObject.h"
#include "Utils.h"
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"


using namespace std;

/// <summary>
/// �����ؾ��� ���
/// 1. �׸���(���ڹ��� �����ϱ�)
/// 4. ��� ǥ�� ( F ������ player position�� ��� + F �ٽ� ������ ��� �������� �ϱ�)
/// 5. ���� ���ڰ��� (cout ���� ���ڰ��� ���)
/// 6. ���ڸ� ������� ���� ���� ( R �Է� player pos == enemy pos �ϰ�� return 0)
/// </summary>
/// <returns></returns>
/// 
//// player �� ��ġ���� wasd�� ������ ������
// 
// r Ű�� ������ Ŭ��(����Լ�)
// r - 1 ���ڰ� ������ --> ���� ���� ( R �Է� player pos == enemy pos �ϰ�� return 0)
// r - 2 ���ڰ� ������ --> ���ڰ� �ִ� ��ó���� ���ڸ� �����ش�. ( ����Լ� )
// 
// F Ű�� ������ ���
// F - 1 ����� ����� ������ ���� ���� -1 ( F �Է� ��� ǥ��, enemy -- , R �Է� �ȵǰ��ϱ� )
// F - 2 ��� ���� ���� F �ѹ��� ������ ���� ���� +1 ( R �Է��� �ȵǴ°�(== ����� �����) Ȯ���ϰ�, F��� ǥ�� ����, enemy ++)
// 
// ���ڰ����� 0 �̰�, �� ���� �� ��� �¸� ( enemy == 0 & �˻�(����Լ�) ������ �� ���µǾ������� VICTORY)
// ���ڰ����� 0���� ���� ��쿣 ������ ������ �ʴ´�. ( ���� ������ �����ϰ�� ������ ������ ����)
// 
// ������ ������ ��� -> esc �����ų�, ���ڸ� ã�ų� �̱�ų� ( player key = esc || R �Է� player pos == enemy pos �ϰ�� return 0
// �̱�� ��� -> ���ڰ����� 0�̰� �� ���µǾ� ���� ���. ( enemy == 0 & �˻�(����Լ�) ������ �� ���µǾ������� VICTORY)


int main()
{
	Player player{ 2, 4 }; // player Ŀ�� ��ġ (������)

	// ennemy 10�� ���� ����
	Enemy* enemy[10];
	srand(time(NULL));
	int x = rand() % 9 + 1;
	int y = rand() % 9 + 1;
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = new Enemy(x, y);
	}
	int enemyCount = 10;

	Screen screen(10, 10); // ȭ���� ũ��

	cout << "             WASD -  �̵�" << endl;
	cout << "             R - Ŭ��" << endl;
	cout << "             F - ���(7)" << endl;
	cout << "             > - ���� ��ġ ǥ��" << endl;

	
	while (1)
	{
		screen.clear(); // ȭ�� �ʱ�ȭ
		
		screen.draw(player.getPos(), player.getShape()); // player ��ġ
		for (int i = 0; i < 10; i++)
		{
			screen.draw(enemy[i]->getPos(), enemy[i]->getShape()); // enemy ��ġ
		}

		screen.render(); // 

		player.processInput(); // ������ ����

		char key = NULL;
		/* ============= ��ġ �� �Լ� ============
		if (key == 'r')
		{
			if (player.getPos() == enemy->getPos())
				return 0;
			else
			============ ����Լ� =============
			screen.draw(player.getPos(), 'X');
		}

		if (key == 'f')
		{
			screen.draw(player.getPos(), '#');
			enemyCount --;
		}

		if(enemyCount == 0, ����Լ� -> 0 �� ���)
		 cout << " VICTORY " << endl;
		 return 0;

		*/
		
	}

	return 0;
}