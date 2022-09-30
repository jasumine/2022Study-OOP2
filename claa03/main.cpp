#define _CRT_SECURE_NO_WARINGS

#include <iostream>
#include <string>
#include "Dog.h"
#include "Utils.h"

using namespace std;

/*
// 전역 변수
// string _somethingHidden("unhappy");
// const char *_somethingHidden = "unhappy";
Pet unhappy("unhappy", 0); // 깊은 복사
// unhappy("unhappy",0);일 때 const char *name 으로 되어있으면 
// unhappy는 char자료형으로, 문자열을 복사해서 오는 것 - 깊은 복사 (복사 생성자 호출 X)
Pet& anotherUnhappy = unhappy;
Pet* anotherAnotherUnhappy = &unhappy;
// anotherAnotherUnhappy->name = "hello"; 이렇게 하면 이름이 "unhappy"에서 "hello"로 바뀐다.
*/

int main()
{ 
// 지역 변수 
// 
	// Dog happy = Dog("happy", 4, 3); 생성자 + 복사 생성자
	// Dog happy("happy", 4, 3);
	Pet *happy = new Dog("happy", 4, 3); 
	// 원래 dog가 생성자가 호출되지만, dog는 pet을 생성해서 pet이 먼저 생성되서 pet이 먼저 호출되고,
	// 이후 dog함수가 종료되면서 dog생성자도 호출한다.
	// Dog another_happy(happy); // 복사생성자
	// 
	// 	Pet *happy = new Dog("happy", 4, 3);  이렇게 바꾸면 happy는 그냥 pet이라서 dog의 bark를 쓸 수 없음.
	// 
	// cout << happy.getName() << endl;
	cout << happy->getName() << endl; // 부모에게 상속받아서 dog에 정의하지 않아도 사용 가능
	// 상속 받으면 언제든지 부모의 메서드를 사용할 수 있다.
	// 수정하고 싶을 경우 부모함수에 virtual을 써서 수정해 준다.
	/*
	Pet* pet = &happy; // 업캐스팅, 부모에 자식을 복사
	
	happy.bark();
	happy.eat();
	happy.sleep();
	*/

	Pet* pet = happy;

	// happy->bark();
	happy->eat();
	happy->sleep();

	// pet->bark(); 업캐스팅하면 dog의 메소드는 쓰지못함
	pet->eat();
	pet->sleep();

	((Dog*)pet)->bark(); // 다운캐스팅, 쓰지말것 많아질 경우 복잡해짐

	(static_cast<Dog*>(pet))->bark(); // pet이라는 포인터를 dog라는 포인터로 바꿔주세요
	// 이렇게 바꾸는게 안전하다.

	delete happy; 
	// happy는 Pet의 포인터여서 happy 소멸자가 호출된다. 
	// 하지만, 원래 만들어진 것은 dog여서 
	// delete (static_cast<Dog*>(happy)); 다운 캐스팅을 해서 dog소멸자를 호출한다.
	// 아니면 virtual를 pet소멸자에 작성해서 dog소멸자를 호출한다.

	return 0;
}