#include <vector>
#include <algorithm>
#include <memory>
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include "Utils.h"

using namespace std;

// static 변수 정의는 헤더가 아닌 소스파일에 넣어준다.
vector<GameObject *> GameObject::objs; // 삭제를 하지 않는다.
vector<GameObject*> GameObject::pendingObjs; // 삭제하면 업데이트 되도록 obj 하나만 쓰는거 보다 안전함


void GameObject::Initialize(Screen& screen, InputSystem& input)
{
	// pendingObj에 들어가지만, 가독성 향상을 위해서 pendingObjs.push_back 해주고, 생성자 함수에서 pending.push_back을 지우는게 좋다
	new Enemy("\xB0\xB0", { 10, 5 }, screen, input, { 2, 1 }); 
	new Enemy("\xB0\xB0", { 5, 7 }, screen, input, { 2, 1 });
	new Enemy("\xB0\xB0", { 60, 18 }, screen, input, { 2, 1 });
	new Player("\xB2\xB2\xB2\xB2 \xB2\xB2 \xB2", { 40, 10 }, screen, input, { 3, 3 });
}

void GameObject::Update()
{	
	while (!pendingObjs.empty()) {
		objs.push_back( pendingObjs.back() );
		pendingObjs.pop_back();
	}
	for (auto obj : objs)
		obj->update();
}

void GameObject::DestoryDisabledObjects()
{
	for (auto it = objs.begin(); it != objs.end();) {
		auto obj = *it;
		if (obj->isEnabled()) {
			it++;
			continue;
		}
		it = objs.erase(it);
		delete obj;
	}
}

void GameObject::Draw()
{
	Borland::GotoXY(0, 30);
	cout << "objects = " << objs.size() << " ";

	for (auto obj : objs)
		obj->draw();
}

void GameObject::Deinitialize()
{	
}