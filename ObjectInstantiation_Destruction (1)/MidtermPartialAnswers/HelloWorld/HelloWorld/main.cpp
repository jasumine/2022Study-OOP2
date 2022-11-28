
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

	// friend 뒤에 적힌 함수는 friend로 정해서 private에 접근이 가능하다.
	friend ostream& operator <<(ostream& os, const Student& s);

	bool MultipleOfThree()

	friend static bool isMultipleOfThree(const Student& student) { return student.age % 3 == 0; }
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


// teplate을 설정하면 자료형을 굳이 정해주지 않아도 된다.
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
/* functor를 사용할려면 구조체가 필요하다.
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
	 
	// 함수를 변수로넘기기위해서 func pointer를 사용
	function<bool(const Student&)> func;  //아래와 같음
	auto func = Student::isMultipleOfThree;
	func = &Student::isMultipleOfThree;  // 위와 같음

	*/
	/*
	// func는 함수를 변수처럼 넘겨주는 것
	// functor 은 func를 객체로 만들어 주는 것

	MultipleOfThree func; // func 을 변수취급. // functor

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

		// 람다 function(이름은 없지만, 함수의 기능을 한다)
		// true가 되는 값을 반환해서 위치를 찾는다.
		// main함수 안에 있지만, 다른 함수로 인식되서 바깥의 변수를 불러오지 못한다.  
		// 그래서 캡쳐를 담당하는 []에 기호를 넣어서 해결한다. =깊은복사, &얕은복사
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

	// ======= 3의 배수를 삭제 =======
	// for(auto student:students){} --> foreach 문은 읽기전용
	// iterator를 사용한 for문
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
	// vector는 배열이여서, 중간에 지워버리면 앞으로 복사해야함
	// -> 삭제해야되는 것을 뒤로 옮기고, 뒤에 있던것은 앞으로 옮겨서 (바꿔치기) 삭제한다.
	students.erase // 지워주세요
			(remove_if (students.begin(), // 처음부터
					students.end(),  // 끝까지
				[](auto& student) { return student.isMultipleOfThree(); } //조건에 해당되는 부분부터 (바꿔치기)
			), students.end()); // 끝까지

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