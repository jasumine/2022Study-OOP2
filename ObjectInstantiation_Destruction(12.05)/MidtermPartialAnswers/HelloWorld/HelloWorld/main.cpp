
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "GameObject.h"
#include "Utils.h"
#include "Screen.h"
#include "InputSystem.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main()
{
	Screen screen(30, 81);
	InputSystem input;
	
	// <����Ƽ> -> pointer ������ �Ǿ� ������ ������, pointer ���������� �Ѵ�.
	// class�� ����Ǵ� �͵��� �������̴�.
	GameObject[] objs = GameObject[10];
	for (int i = 0; i < 10; i++)
		objs[i] = new GameObject...;
	
	// <C++>
	GameObject* objs = new (GameObject*)[10];
	for (int i = 0; i < 10; i + )
		objs[i] = new GameObject(..., screen, input, dim);





	// vector<GameObject> objs(10);  // GameObject�� �� �� �ִ� ���� 10���� ������ (�迭 10��) -> �⺻ ������ �Լ��� ��� �� �� ����.
	vector<GameObject> objs;
	objs.reserve(10); // vector�� �Լ� reserve. reserve(10) == 10���� ������ ����� �ּ���. (������ �Լ� ȣ��X)
	// malloc (������ Ȯ��)???, new (���ο� ������ �Ҵ�??)

	
//	Player player = Player{ "\xB2\xB2\xB2\xB2 \xB2\xB2 \xB2", { 40, 10 }, screen, input, { 3, 3 } };
//	objs.push_back(player);  GameOjbect��  player�� �����Ѱ��� �����ڵ�� �Ȱ���.

	objs.push_back(Player{ "\xB2\xB2\xB2\xB2 \xB2\xB2 \xB2", { 40, 10 }, screen, input, { 3, 3 } }); // GameObject��ü�� ������.
	objs.push_back(Enemy{ "\xB0\xB0", { 10, 5 }, screen, input, { 2, 1 } });
	objs.push_back(Enemy{ "\xB0\xB0", { 5, 7 }, screen, input, { 2, 1 } });
	
	// �̺κ� �����ϱ�!!!!
	// reserve�ؼ� ������� ������ �ʱ�ȭ�� �����ָ鼭 copy constructor�� ȣ��ǰ�, upcasting�� �ƴ�.
	// ������ ������� object�� copy �Ǽ� destructor�� ȣ��ȴ�. stack ���� (�����Ϳ� ���� �޸𸮸� ���� ���)
	// 
	// ***upcast �ϰ� �ʹٸ�***, pointer�� ���� �����Ѵ�. vector<GameObjcet*> objs; �� ���ԵǸ� new Player�� �����ش�.
	// ���� �����ʰ�, �ּ������� ����(8byte)-> ������,  heap ������ ������
	// ���� �Ҵ�Ǿ��� ������, �ݵ�� ���������� �����ش� obj.erase���� ���ش�.(���� ���������)


	// GameObject::Initialize(screen, input);

	while (true)
	{
		screen.clear();
		input.readEveryFrame();

		for (auto& obj : objs)obj.update(); // GameObject�� update�Լ��� ȣ��ȴ�.
		for (auto& obj : objs)obj.draw();
		
		screen.render();
	}

	GameObject::Deinitialize();

	
	return 0;
}