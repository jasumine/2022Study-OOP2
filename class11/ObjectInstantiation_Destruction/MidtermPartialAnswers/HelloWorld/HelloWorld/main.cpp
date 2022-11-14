
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

// vector안에 있는 정보를 출력하는 함수
// 함수에 const를 안붙이는 이유는 멤버변수가 있으면 써서 변경되지 않게 하지만, 
// 지금은 전역함수 이기때문에 쓰지 않아도 된다.
// const를 붙인다면 레퍼런스 변수임을 명시해주자. (수정하지 않는다, 깊은복사가 일어나지않게 한다)
// cont int& item을 써도 됨. 

void coutVecter(const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int item = vec[i];
		cout << item << endl;
	}
	
	// vector라는 클래스 안에 intertator라는 클래스를 추가함 
	// interator는 변수공간, 내가 어느 공간에 있는지 알려준다.
	// vec에 빨간줄이 그어진 이유는 const를 붙인 vec를 수정하지 말라고 경고하는 뜻
	// c는 const라는 의미임. cbegin, cend-> 안붙여도 const_interator가 const의미를 내포하지만, 확실하게 하기위해서 써주는게 좋다.
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

// 변수가 수정되서 const를 붙이지 않음.
void increaseIntsBy1(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int& item = vec[i];
		item++;
	}
	// iterator의 begin(처음꺼, vec[0]), end(마지막꺼의 다음거, vec[size()+1])
	/*
	for (vector<int>::iterator it = vec.begin(); // 처음부터
		it != vec.end(); // 마지막 +1 이 아닐때까지 == 마지막까지
		it++ // it 을 1씩 더해준다.
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
		// int item = ints.at(i); // ints[i]와 같은 의미
		int& item = ints[i]; // item이 레퍼런스변수가 되어서 item = item +1 을 하면 원본정보를 수정하게 됨.
		cout << item << endl;
		item = item + 1 ; // 1씩 값을 증가 -> 복사된거라 바뀌지 않음
		// ints[i] = ints[i] + 1; // 원본을 수정해서 결과가 바뀜
		// ints[i] = item;과 같은 의미 
		
	}
	cout << "After" << endl;

	for (int i = 0; i < ints.size(); i++)
	{
		int item = ints.at(i); // ints[i]와 같은 의미
		cout << item << endl;
	}
	*/
	cout << "Before" << endl;
	coutVecter(ints);

	cout << "After" << endl;
	// increaseIntsBy1(ints);
	coutVecter(ints);
	
	cout << endl << "Find" << endl;

	vector<int>::iterator pos = ints.begin(); // pos에 시작위치를 넣어준다.
	while ( (pos = find(pos, ints.end(), 50)) != ints.end())
	{
		cout << *pos << endl;
		pos++; // pos가 다른 위치에도있다면, 그 개수만큼 보이도록 
	}
	// 마지막 값(38)이 있다면 그 위치를 출력하고, 아니면 end의 위치를 출력하는 함수.
	
	/*auto pos = find(ints.begin(), ints.end(), 50);
	if (pos != ints.end()) // end값이 아니다 = 38이 있다는 의미
	{
		cout << *pos << endl; // iterator라서 포인터로 그 값을 출력하면된다.
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