#pragma once
#include <iostream>
#include <string>

using namespace std;

// �������� ���븸 �����Ѵ�.
class Pet{
private:
	string name;
	int birth; 
	// ���̴� �ų� ��������ؼ� ������Ϸ� �޾� ����� �Ѵ�.

public:
	int age;
	Pet() {	} // ������
	Pet(string name, int age) : name(name), age(age) { } 
	~Pet() {} // �Ҹ���
	string getName() { return name; }
	int getAge() { return age; }
	void setName(string p_Name) {}
	void setAge(int p_Age) {}
	void eatting() {}
	void voice(string p_voice) {}
	void sleep() {}
};
