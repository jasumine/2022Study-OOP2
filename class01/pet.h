#pragma once
#include <iostream>
#include <string>

using namespace std;

// 공통적인 내용만 구현한다.
class Pet{
private:
	string name;
	int birth; 
	// 나이는 매년 더해줘야해서 생년월일로 받아 계산을 한다.

public:
	int age;
	Pet() {	} // 생성자
	Pet(string name, int age) : name(name), age(age) { } 
	~Pet() {} // 소멸자
	string getName() { return name; }
	int getAge() { return age; }
	void setName(string p_Name) {}
	void setAge(int p_Age) {}
	void eatting() {}
	void voice(string p_voice) {}
	void sleep() {}
};
