
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

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
	Student(const string& name, int age) : name(name), age(age) 
	{
		cout << "Studen Constructor" << endl;
	}

	Student(const Student& other) : name(other.name), age(age)
	{
		cout << " Student copy constructor" << endl;
	}


	~Student()
	{
		cout << "Student Destructor" << endl;
	}

	// friend �ڿ� ���� �Լ��� friend�� ���ؼ� private�� ������ �����ϴ�.
	friend ostream& operator <<(ostream& os, const Student& s);

	bool MultipleOfThree()

	friend static bool isMultipleOfThree(const Student& student) { return student.age % 3 == 0; }
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


// teplate�� �����ϸ� �ڷ����� ���� �������� �ʾƵ� �ȴ�.
template<typename T>
bool isMultipleOfFive(const T& item)
{
	return item % 5 == 0;
}


// template programing specialization 
template<>
bool isMultipleOfFive(const Student& s)
{
	return s.age % 5 == 0;
}
*/
template <typename T>
bool isMultipleOfThree(const T& s)
{
	return s % 3 == 0;
}

// special ?? template 
template<>
bool isMultipleOfThree(const Student& s)
{
	return s.age % 3 == 0;
}
/* functor�� ����ҷ��� ����ü�� �ʿ��ϴ�.
struct MultipleOfThree
{
	bool operator()(const Student& s)
	{
		return s.isMulipleOfThree();
	}
};*/


int main()
{
	vector<Student>students;

	students.push_back({ "Beomjoo Seo", 18 });
	students.push_back({ "Mr. Present", 60 });
	students.push_back({ "Mr. Lee", 62 }),
	students.push_back({ "Mr. Moon", 70 });
	cout << students << endl;

	cout << endl << "find" << endl;
	/*
	auto pos = students.begin();
	while ((pos = find_if(pos, students.end(), isMultipleOfThree<Student>)) != students.end())
	{
		cout << *pos << endl;
		pos++;
	}

	for (auto it = students.begin(); it != students.end(); it++)
	{
		auto& student = *it;
		if (student.isMultipleOfThree())
		{
			cout << student << endl;
		}
	}

	for (auto& student : students)
	{
		if (student.isMultipleOfThree())
		{
			cout << student << endl;
		}
	}

	bool (*func)(const Student & s);
	 
	// �Լ��� �����γѱ�����ؼ� func pointer�� ���
	function<bool(const Student&)> func;  //�Ʒ��� ����
	auto func = Student::isMultipleOfThree;
	func = &Student::isMultipleOfThree;  // ���� ����

	*/
	/*
	// func�� �Լ��� ����ó�� �Ѱ��ִ� ��
	// functor �� func�� ��ü�� ����� �ִ� ��

	MultipleOfThree func; // func �� �������. // functor

	cout << students[0] << "is" << func(students[0]) << endl;
	cout << students[1] << "is" << func(students[1]) << endl;
	cout << students[2] << "is" << func(students[2]) << endl;
	cout << students[3] << "is" << func(students[3]) << endl;
	cout << students[4] << "is" << func(students[4]) << endl;

	for (auto& student : students)
	{
		cout << student << "is" << func(student) << endl;
	}
	*/

	// auto nStudents = students.size();

	/*
	vector<Student>::iterator pos = students.begin();
	while ((pos = find_if(pos, students.end(),

		// ���� function(�̸��� ������, �Լ��� ����� �Ѵ�)
		// true�� �Ǵ� ���� ��ȯ�ؼ� ��ġ�� ã�´�.
		// main�Լ� �ȿ� ������, �ٸ� �Լ��� �νĵǼ� �ٱ��� ������ �ҷ����� ���Ѵ�.  
		// �׷��� ĸ�ĸ� ����ϴ� []�� ��ȣ�� �־ �ذ��Ѵ�. =��������, &��������
		[&](auto& s) {
			if (students.size() < 4) return return s.isMultipleOfThree();
			reurn false;
		} 
		)) != students.end())
	{
		cout << "iteraor pos " << *pos << endl;
		pos++;
	}
	*/

	// ======= 3�� ����� ���� =======
	// for(auto student:students){} --> foreach ���� �б�����
	// iterator�� ����� for��
	/*
	for (auto it = students.begin(); it != students.end(); it++)
	{
		auto& student = *it;
		if (student.isMulipleOfThree())
		{
			it = students.erase(it);
		}
		else it++;
	}
	*/

	// erase - remove idiom
	// vector�� �迭�̿���, �߰��� ���������� ������ �����ؾ���
	// -> �����ؾߵǴ� ���� �ڷ� �ű��, �ڿ� �ִ����� ������ �Űܼ� (�ٲ�ġ��) �����Ѵ�.
	students.erase // �����ּ���
			(remove_if (students.begin(), // ó������
					students.end(),  // ������
				[](auto& student) { return student.isMultipleOfThree(); } //���ǿ� �ش�Ǵ� �κк��� (�ٲ�ġ��)
			), students.end()); // ������

	cout << students << endl;




	return 0;

/* print(students.data(), students.size());


	cout << "before" << endl;
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