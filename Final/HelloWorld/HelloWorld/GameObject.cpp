#include <vector>
#include <algorithm>
#include <memory>
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include "Utils.h"

using namespace std;

vector<GameObject *> GameObject::objs;
vector<GameObject*> GameObject::pendingObjs;

// ���ο� ������ �߰�,  push_back
void GameObject::Initialize(Screen& screen, InputSystem& input)
{
	GameObject::pendingObjs.push_back(new Enemy("\xB0\xB0", { 10, 5 }, screen, input, { 2, 1 }));
	GameObject::pendingObjs.push_back(new Enemy("\xB0\xB0", { 5, 7 }, screen, input, { 2, 1 }));
	GameObject::pendingObjs.push_back(new Enemy("\xB0\xB0", { 60, 18 }, screen, input, { 2, 1 }));
	GameObject::pendingObjs.push_back(new Player("\xB2\xB2\xB2\xB2 \xB2\xB2 \xB2", { 40, 10 }, screen, input, { 3, 3 }));
}

void GameObject::Update()
{	// pending�ȿ� �ִ� object ������ enable ���� �ƴ��� �Ǵ��ϵ���, ��� update �����ش�.
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
	Borland::GotoXY(0, 40);
	printf("objects = %5lld", objs.size());

	for (auto obj : objs)
		obj->draw();
}

void GameObject::Deinitialize()
{	
}