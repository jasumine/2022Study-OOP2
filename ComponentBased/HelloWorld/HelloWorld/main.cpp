
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "Vector2.h"
#include "GameObject.h"
#include "Utils.h"
#include "Screen.h"
#include "InputSystem.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main()
{
	Vector2<int> pos, pos1;
	Vector2<float> fPos;



	pos.set(10, 20);
	Vector2<int> pos2(30, 40);
	Vector2<int> pos3;

	pos3 = pos2; // 복사 연산자이지만, copy constructor가 호출 된다. 
	Vector2<int> pos4;
	pos = pos4 = pos3; // pos = pos3 이라는 뜻
	
	pos = pos3 + pos2; 
	pos = pos3 - pos2;

	int scale = 3;
	Vector2<int> newPos = pos1 + pos2 * scale;

	float div = 3;
	pos = pos3 / 3;

	Vector2<int> pos5 = scale * (pos1 + pos2); // 전역함수를 써야함
	
	pos5.reset();
	pos3 = pos5 = 10;

	pos5 = Vector2<int>::zero;
	pos5 = Vector2<int>::one;

	cout << pos5;
	cin >> pos5;
	
	double sz = pos5.magnitude(); // sqrt(x*x + y*y)
	double sqredSize = pos5.sqrMagnitude();  // x* x + y * y
	Vector2<double> dPos = pos; // 자료형을 바꿔주는 코드

	
	return 0;

	Screen screen(30, 81);
	InputSystem input;

	GameObject::Initialize(screen, input);

	while (true)
	{
		screen.clear();
		input.readEveryFrame();

		GameObject::Update();
		GameObject::DestoryDisabledObjects();
		GameObject::Draw();
		
		screen.render();
	}

	GameObject::Deinitialize();

	
	return 0;
}