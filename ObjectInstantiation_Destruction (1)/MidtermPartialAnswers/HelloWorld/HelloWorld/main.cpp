
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
	// friend �ڿ� ���� �Լ��� friend�� ���ؼ� private�� ������ �����ϴ�.
	friend ostream& operator <<(ostream& os, const Student& s);

	friend template<typename T>
	 bool isMultipleOfFive<Student>(const Student& s);
};

// �����Լ��� student�� ������ ����ϴ� �Լ�
// student Ŭ������ ���� �ʴ� ������ public���� �ִ��� ������ ���� �ٽ� �������־�� ����� �۵��Ѵ�.
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
// �ڷ����� ������ �� �ƴ� �ڷ����� �ڵ����� ���ش�.
template<typename T>
void print(const T* data, int size)
{
	for (int i = 0; i < size; i++)
		//cout << data[i] << endl;
	{
		// data[i].print(); class�� �ڿ� �ִ��� Ȯ���غ���
		// << �� ���������� �����ؼ� 
		cout << data[i] << endl;
	}
}
*/
/*
// template�� �����ϸ� �ڷ����� ���� �������� �ʾƵ� �ȴ�.
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
	// int���� char�� �ٲ��� �� ���� �Լ����� ������ int-> char�� �ٲ��� �ʰ�, Template�� ����Ѵ�.
	// auto ������ ����Ѵٰ� �����ϱ�.
	vector<char> ints{ 'A', 'B', 'C', 'D', 'E', 'F', 'G' };

	cout << "before" << endl;
	print<char>(ints.data(), ints.size());
	
	cout << endl<< "after" << endl;
	print<char>(ints.data(), ints.size());


	cout << endl << "find" << endl;

	// function pointer�� ����� ��.,....

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