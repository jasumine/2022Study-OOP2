#pragma once
#include <string>

using namespace std;

// 코드를 디자인 할 때 어떻게 할지 책임을 지고 작성해야한다. + 충분한 사유가 있어서 설득이 되도록 + 코드를 받는 사람이 의도를 알도록
// const를 쓸건지 말건지 반드시 생각하기!!!!!!!! 
// ex)setter 함수를 하지 않을 것, 생성자는 무조건 값을 입력해야한다. 
class Pet
{
	string name;
	int age;

public:
	// 생성자에서 멤버 변수값을 지정해 준다.
	// Pet(string name, int age) :name(name), age(age) {}
	// Pet() : name("unname"), age(0) {}

	Pet(const string& name= "unnamed", int age = 0) :name(name), age(age) {}
	// 레퍼런스 변수를 사용하면서 불필요한 복사를 막아준다. 
	// (원본 정보, 포인터나 레퍼런스를 쓰지 않으면 복사가 됨 -> 시간 소요, 메모리 낭비)
	// const를 사용해서 name은 절대로 바뀌지않는 것을 알려주고, age는 바뀔수 있는걸 알려준다.
	// ***바꾸지 않아야 되는 변수들은 const를 꼭 써줘서 나중에 바꿔서 실수하지 않게 해준다.***
	// 
	// 레퍼런스 변수랑 포인터를 사용하면 원본 정보를 수정할 수 있게 되는데, 
	// 수정하지 않을려면 const를 붙여주고, 수정할 경우엔 const를 붙이지 않으면 된다.
	// 
	// 포인터는 주소값을 계속 바꿔서 쓸 수 있지만, 레퍼런스 변수는 주소값을 바꿀 수 없는 차이가 있다.
	// 
	// class 랑 struct에서 생성자 함수를 쓸 때는 반드시 레퍼런스 변수를 사용해주고, (원본 정보)
	// 정보를 수정하지 않을거면 const를 사용한다. 아닐경우엔 const를 사용하지 않는다.

	/*
	Pet("happy",5);
	Pet("happy");
	Pet();
	Pet(5); (X)
	왼쪽부터 입력 받아야 하고, 비울 수 없음
	*/

	virtual ~Pet() {}

	// getter method (객체 지향에서는 함수라는 말 대신 method라고 한다.
	// getter (값을 받아오는 메소드), setter(값을 입력하는 메소드)
	string getName() { return name; }
	int getAge() { return age; }
};
