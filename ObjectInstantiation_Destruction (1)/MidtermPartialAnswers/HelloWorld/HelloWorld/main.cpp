
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

class Student
{
	string name;
	int age;

public:
	Student(const string& name, int age) : name(name), age(age) {}

	string getName()
	{
		return name;
	}

	int getAge()
	{
		return age;
	}
	/*
	void print()
	{
		cout << "name = " << name << ", age = " << age << endl;
	}
	*/
	// friend 뒤에 적힌 함수는 friend로 정해서 private에 접근이 가능하다.
	friend ostream& operator <<(ostream& os, const Student& s);

	friend template<typename T>
	 bool isMultipleOfFive<Student>(const Student& s);
};

// 전역함수로 student의 변수를 출력하는 함수
// student 클래스에 넣지 않는 이유는 public으로 넣더라도 밖으로 빼서 다시 정의해주어야 제대로 작동한다.
ostream& operator<< (ostream& os, const Student& s)
{
	os << "name = " << s.name << ", age = " << s.age << endl;
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& container)
{
	for (auto &item : container) cout << container << endl;

	return os;
}

/*
// 자료형을 정했을 때 아는 자료형은 자동으로 해준다.
template<typename T>
void print(const T* data, int size)
{
	for (int i = 0; i < size; i++)
		//cout << data[i] << endl;
	{
		// data[i].print(); class가 뒤에 있는지 확인해보기
		// << 를 전역변수로 설정해서 
		cout << data[i] << endl;
	}
}
*/
/*
// template을 설정하면 자료형을 굳이 정해주지 않아도 된다.
template<typename T>
bool ismultipleOfFive(const T& item)
{
	return item % 5 == 0;
}
*/
// template programing specialization 
template<>
bool isMultipleOfFive(const Student& s)
{
	return s.age % 5 == 0;
}

int main()
{

	vector<Student>students{ {"Beomjoo Seo", 18}, {"Mr. Present", 60}, {"Mr. Lee", 62}, {"Mr. Moon", 70} };

	cout << students << endl;

	// print(students.data(), students.size());


/*	cout << "before" << endl;
	print(ints.data(), ints.size());

	cout << endl << "after" << endl;

	cout << "find" << endl;
	auto pos = students.begin();
	while ((pos = find_if(pos, students.end(), ismultipleOfFive<Student>)) != students.end())
	{
		cout << *pos << endl;
		pos++;
	}
	*/
	/*
	// int에서 char로 바꿨을 때 위의 함수에서 변수를 int-> char로 바꾸지 않고, Template을 사용한다.
	// auto 쓰듯이 사용한다고 생각하기.
	vector<char> ints{ 'A', 'B', 'C', 'D', 'E', 'F', 'G' };

	cout << "before" << endl;
	print<char>(ints.data(), ints.size());
	
	cout << endl<< "after" << endl;
	print<char>(ints.data(), ints.size());


	cout << endl << "find" << endl;

	// function pointer를 사용한 것.,....

	auto pos = ints.begin();
	while ((pos = find_if(pos, ints.end(), ismultipleOfFive<char>)) != ints.end())
	{ 
		cout << *pos << endl;
		pos++;
		cout << "next " << *pos << endl;
	}

	*/

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