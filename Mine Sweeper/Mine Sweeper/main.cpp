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
/// *** 어떤걸 public으로 둘지 private를 둘지 주의깊게 생각하기 ***
/// *** 어떤 class가 무슨 기능을 하는지 명확하게 설정하기 ***
/// *** 코드를 최대한 보기쉽게 작성하기(코드 줄이기, 줄맞추기) ***
/// *** 하나하나 순서대로 하기 ***
/// 구현해야할 기능
/// 4. 깃발 표시 ( F 누를시 player position에 출력 + F 다시 누르면 깃발 없어지게 하기)
/// 5. 남은 지뢰갯수 (cout 으로 지뢰갯수 출력)
/// 6. 지뢰를 누를경우 게임 종료 ( R 입력 player pos == enemy pos 일경우 return 0)
/// </summary>
/// <returns></returns>
/// 
//// player 의 위치에서 wasd를 누르면 움직임
// 
// r 키를 누르면 클릭(재귀함수)
// r - 1 지뢰가 있으면 --> 게임 종료 ( R 입력 player pos == enemy pos 일경우 return 0)
// r - 2 지뢰가 없으면 --> 지뢰가 있는 근처까지 숫자를 보여준다. ( 재귀함수 )
// 
// F 키를 누르면 깃발
// F - 1 깃발이 생기면 무조건 지뢰 갯수 -1 ( F 입력 깃발 표시, enemy -- , R 입력 안되게하기 )
// F - 2 깃발 생긴 곳에 F 한번더 누르면 지뢰 갯수 +1 ( R 입력이 안되는곳(== 깃발이 생긴곳) 확인하고, F깃발 표시 제거, enemy ++)
// 
// 지뢰갯수가 0 이고, 다 오픈 된 경우 승리 ( enemy == 0 & 검사(재귀함수) 썼을때 다 오픈되어있으면 VICTORY)
// 지뢰갯수가 0보다 작을 경우엔 게임이 끝나지 않는다. ( 위으 조건을 제외하고는 게임이 끝나지 않음)
// 
// 게임이 끝나는 경우 -> esc 누르거나, 지뢰를 찾거나 이기거나 ( player key = esc || R 입력 player pos == enemy pos 일경우 return 0
// 이기는 경우 -> 지뢰갯수가 0이고 다 오픈되어 있을 경우. ( enemy == 0 & 검사(재귀함수) 썼을때 다 오픈되어있으면 VICTORY)


int main()
{
	GameManager gameManager;
	Screen screen(11, 11); // 화면의 크기
	Player player{ 0, 0, screen }; 
	// 지뢰 갯수 10개
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

	// ennemy 10개 랜덤 생성
	//Enemy* enemy[10];
	//srand(time(NULL));
	//int x = rand() % 9 + 1;
	//int y = rand() % 9 + 1;
	//for (int i = 0; i < 10; i++)
	//{
	//	enemy[i] = new Enemy(x, y, screen);
	//}
	int enemyCount = 10;

	cout << "WASD -  이동" << endl;
	cout << "R - 클릭" << endl;
	cout << "F - 깃발(#)" << endl;
	cout << "Q - 게임 종료" << endl;
	cout << "> - 현재 위치 표시" << endl;

while (1)
{
	cout << "지뢰 개수 : " << enemyCount << endl;
	screen.clear(); // 화면 초기화

	screen.draw(player.getPos(), player.getShape()); // player 위치
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
	// ============= 위치 비교 함수 ============
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

	//if(enemyCount == 0, 재귀함수 -> 0 일 경우)
	// cout << " VICTORY " << endl;
	// return 0;


	/* 제일 이상적인 것
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
