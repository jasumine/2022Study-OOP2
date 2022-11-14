
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include "GameObject.h"
#include "Utils.h"
#include "Screen.h"
#include "InputSystem.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

/*
void const coutVecter(const vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int item = vec[i];
		cout << item << endl;
	}
}
*/

// vector�ȿ� �ִ� ������ ����ϴ� �Լ�
// �Լ��� const�� �Ⱥ��̴� ������ ��������� ������ �Ἥ ������� �ʰ� ������, 
// ������ �����Լ� �̱⶧���� ���� �ʾƵ� �ȴ�.
// const�� ���δٸ� ���۷��� �������� ���������. (�������� �ʴ´�, �������簡 �Ͼ���ʰ� �Ѵ�)
// cont int& item�� �ᵵ ��. 

void coutVecter(const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int item = vec[i];
		cout << item << endl;
	}
	
	// vector��� Ŭ���� �ȿ� intertator��� Ŭ������ �߰��� 
	// interator�� ��������, ���� ��� ������ �ִ��� �˷��ش�.
	// vec�� �������� �׾��� ������ const�� ���� vec�� �������� ����� ����ϴ� ��
	// c�� const��� �ǹ���. cbegin, cend-> �Ⱥٿ��� const_interator�� const�ǹ̸� ����������, Ȯ���ϰ� �ϱ����ؼ� ���ִ°� ����.
	/*for (vector<int>::const_iterator it = vec.cbegin();
		it != vec.cend();
		it++
		)
	{
		int item = *it;
		cout << item << endl;
	}
	*/
	for (auto it = vec.cbegin();
		it != vec.cend();
		it++
		)
	{
		auto item = *it;
		cout << item << endl;
	}

}

// ������ �����Ǽ� const�� ������ ����.
void increaseIntsBy1(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int& item = vec[i];
		item++;
	}
	// iterator�� begin(ó����, vec[0]), end(���������� ������, vec[size()+1])
	/*
	for (vector<int>::iterator it = vec.begin(); // ó������
		it != vec.end(); // ������ +1 �� �ƴҶ����� == ����������
		it++ // it �� 1�� �����ش�.
		)
		{
		int& item = *it;
		item++;
		}
	*/
	for	(auto it = vec.begin();
		it != vec.end();
		it++
		)
	{
		auto & item = *it;
		item++;
	}
}

int main()
{
	vector<int> ints = vector<int>();
	ints.push_back(50);
	ints.push_back(20);
	ints.push_back(100);
	ints.push_back(50);
	ints.push_back(24);
	// 30, 20, 100, 50, 24 
	/*
	for (int i = 0; i < ints.size(); i++)
	{
		// int item = ints.at(i); // ints[i]�� ���� �ǹ�
		int& item = ints[i]; // item�� ���۷��������� �Ǿ item = item +1 �� �ϸ� ���������� �����ϰ� ��.
		cout << item << endl;
		item = item + 1 ; // 1�� ���� ���� -> ����ȰŶ� �ٲ��� ����
		// ints[i] = ints[i] + 1; // ������ �����ؼ� ����� �ٲ�
		// ints[i] = item;�� ���� �ǹ� 
		
	}
	cout << "After" << endl;

	for (int i = 0; i < ints.size(); i++)
	{
		int item = ints.at(i); // ints[i]�� ���� �ǹ�
		cout << item << endl;
	}
	*/
	cout << "Before" << endl;
	coutVecter(ints);

	cout << "After" << endl;
	// increaseIntsBy1(ints);
	coutVecter(ints);
	
	cout << endl << "Find" << endl;

	vector<int>::iterator pos = ints.begin(); // pos�� ������ġ�� �־��ش�.
	while ( (pos = find(pos, ints.end(), 50)) != ints.end())
	{
		cout << *pos << endl;
		pos++; // pos�� �ٸ� ��ġ�����ִٸ�, �� ������ŭ ���̵��� 
	}
	// ������ ��(38)�� �ִٸ� �� ��ġ�� ����ϰ�, �ƴϸ� end�� ��ġ�� ����ϴ� �Լ�.
	
	/*auto pos = find(ints.begin(), ints.end(), 50);
	if (pos != ints.end()) // end���� �ƴϴ� = 38�� �ִٴ� �ǹ�
	{
		cout << *pos << endl; // iterator�� �����ͷ� �� ���� ����ϸ�ȴ�.
	}
	else
	{
		cout << "cannot find any"; 
	}
	*/

	return 0;

	// =======================================================================
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