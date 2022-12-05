
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
	
	// <유니티> -> pointer 선언이 되어 있지는 않지만, pointer 변수역할을 한다.
	// class로 선언되는 것들은 포인터이다.
	GameObject[] objs = GameObject[10];
	for (int i = 0; i < 10; i++)
		objs[i] = new GameObject...;
	
	// <C++>
	GameObject* objs = new (GameObject*)[10];
	for (int i = 0; i < 10; i + )
		objs[i] = new GameObject(..., screen, input, dim);





	// vector<GameObject> objs(10);  // GameObject가 들어갈 수 있는 공간 10개를 만들어둠 (배열 10개) -> 기본 생성자 함수가 없어서 쓸 수 없다.
	vector<GameObject> objs;
	objs.reserve(10); // vector의 함수 reserve. reserve(10) == 10개의 공간을 만들어 주세요. (생성자 함수 호출X)
	// malloc (공간만 확보)???, new (새로운 정보를 할당??)

	
//	Player player = Player{ "\xB2\xB2\xB2\xB2 \xB2\xB2 \xB2", { 40, 10 }, screen, input, { 3, 3 } };
//	objs.push_back(player);  GameOjbect에  player를 생성한것은 위의코드랑 똑같다.

	objs.push_back(Player{ "\xB2\xB2\xB2\xB2 \xB2\xB2 \xB2", { 40, 10 }, screen, input, { 3, 3 } }); // GameObject객체로 들어가진다.
	objs.push_back(Enemy{ "\xB0\xB0", { 10, 5 }, screen, input, { 2, 1 } });
	objs.push_back(Enemy{ "\xB0\xB0", { 5, 7 }, screen, input, { 2, 1 } });
	
	// 이부분 복습하기!!!!
	// reserve해서 만들어진 공간에 초기화를 시켜주면서 copy constructor가 호출되고, upcasting도 아님.
	// 기존에 만들어진 object는 copy 되서 destructor가 호출된다. stack 공간 (포인터에 비해 메모리를 많이 사용)
	// 
	// ***upcast 하고 싶다면***, pointer로 만들어서 적용한다. vector<GameObjcet*> objs; 로 적게되면 new Player로 적어준다.
	// 복사 되지않고, 주소정보를 저장(8byte)-> 빠르다,  heap 공간에 들어가있음
	// 동적 할당되었기 때문에, 반드시 동적해제를 시켜준다 obj.erase에서 해준다.(따로 적어줘야함)


	// GameObject::Initialize(screen, input);

	while (true)
	{
		screen.clear();
		input.readEveryFrame();

		for (auto& obj : objs)obj.update(); // GameObject의 update함수가 호출된다.
		for (auto& obj : objs)obj.draw();
		
		screen.render();
	}

	GameObject::Deinitialize();

	
	return 0;
}