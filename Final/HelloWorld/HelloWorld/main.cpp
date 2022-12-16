
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
* ���迡 ������ �����̴� �ڵ带 �� �˰����
space - enemy�߰�
��Ŭ�� ( enemy�� ����, ���ٸ� �ƹ����̳�)
��Ŭ�� ( bullet�� �����µ�, �Ÿ��� ���� ������ �ӵ��� �ٸ��� ����)

+)
component ��� ���� -> Ŭ�����ݿ� ���� ���ε� �Ǿ�����
unity���� ���� ��ɰ� �����ϴ�
unique_ptr�� ���迡 ������ ������, �����غ���
*/