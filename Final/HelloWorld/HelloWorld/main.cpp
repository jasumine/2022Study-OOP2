
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

/*
* 시험에 나오는 로직이니 코드를 꼭 알고오기
space - enemy추가
좌클릭 ( enemy를 따라감, 없다면 아무곳이나)
우클릭 ( bullet이 나오는데, 거리를 보고 나오는 속도를 다르게 구현)

+)
component 기반 설계 -> 클래스넷에 파일 업로드 되어있음
unity에서 쓰는 기능과 유사하다
unique_ptr은 시험에 나오지 않지만, 공부해보기
*/