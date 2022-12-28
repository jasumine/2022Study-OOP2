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
#include "GameManager.h"

// #include <vector>

using namespace std;

/// <summary>
/// *** ��� public���� ���� private�� ���� ���Ǳ�� �����ϱ� ***
/// *** � class�� ���� ����� �ϴ��� ��Ȯ�ϰ� �����ϱ� ***
/// *** �ڵ带 �ִ��� ���⽱�� �ۼ��ϱ�(�ڵ� ���̱�, �ٸ��߱�) ***
/// *** �ϳ��ϳ� ������� �ϱ� ***
/// �����ؾ��� ���
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
	GameManager gameManager;
	Screen screen(11, 11); // ȭ���� ũ��
	Player player{ 0, 0, screen }; 
	// ���� ���� 10��
	Enemy enemy1{ 0,0, screen };
	Enemy enemy2{ 1,1, screen };
	Enemy enemy3{ 2,2, screen };
	Enemy enemy4{ 3,3, screen };
	Enemy enemy5{ 4,4, screen };
	Enemy enemy6{ 5,5, screen };
	Enemy enemy7{ 6,6, screen };
	Enemy enemy8{ 7,7, screen };
	Enemy enemy9{ 8,8, screen };
	Enemy enemy10{ 9,9, screen };

	// ennemy 10�� ���� ����
	//Enemy* enemy[10];
	//srand(time(NULL));
	//int x = rand() % 9 + 1;
	//int y = rand() % 9 + 1;
	//for (int i = 0; i < 10; i++)
	//{
	//	enemy[i] = new Enemy(x, y, screen);
	//}
	int enemyCount = 10;

	cout << "WASD -  �̵�" << endl;
	cout << "R - Ŭ��" << endl;
	cout << "F - ���(#)" << endl;
	cout << "Q - ���� ����" << endl;
	cout << "> - ���� ��ġ ǥ��" << endl;

while (1)
{
	cout << "���� ���� : " << enemyCount << endl;
	screen.clear(); // ȭ�� �ʱ�ȭ

	screen.draw(player.getPos(), player.getShape()); // player ��ġ
	screen.draw(enemy1.getPos(), enemy1.getShape());
	screen.draw(enemy2.getPos(), enemy2.getShape());
	screen.draw(enemy3.getPos(), enemy3.getShape());
	screen.draw(enemy4.getPos(), enemy4.getShape());
	screen.draw(enemy5.getPos(), enemy5.getShape());
	screen.draw(enemy6.getPos(), enemy6.getShape());
	screen.draw(enemy7.getPos(), enemy7.getShape());
	screen.draw(enemy8.getPos(), enemy8.getShape());
	screen.draw(enemy9.getPos(), enemy9.getShape());
	screen.draw(enemy10.getPos(), enemy10.getShape());


	screen.render(); 

	player.update();

	char key = NULL; 
	// ============= ��ġ �� �Լ� ============
	/*if (key == 'r')
	{
		if (gameManager.comparePos(player.getPos(), enemy[i]->getPos(), ))
			return 0;
		else
	}*/

	//if (key == 'f')
	//{
	//	if (gameManager.comparePos(player.getPos(), enemy[i]->getPos(), ))
	//	{
	//		screen.draw(player.getPos(), '#');
	//		enemyCount--;
	//	}
	//}

	//if(enemyCount == 0, ����Լ� -> 0 �� ���)
	// cout << " VICTORY " << endl;
	// return 0;


	/* ���� �̻����� ��
	Screen screen(20, 81);

	vector<GameObject*> obj;

	objs.push_back(new Player(2, 4, screen));

	int maxCount = 5 * 10;
	int cout = 0;

	while (1)
	{
		screen.clear();
		for (auto obj : objs)
			screen.draw(obj->getPos(), obj->getShape());

		screen.render();
		if (count++ == maxCount)
		{
			count = 0;
			objs.push_back(new Enemy(rand() % 80, rand() % 20, screen));
		}
		for (auto obj : objs)
			obj->update();
	}*/
}

return 0;
}
