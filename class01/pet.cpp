#pragma once
#include <iostream>
#include <string>
#include "pet.h"

Pet::Pet() {	} // ������
	
Pet::Pet(string p_Name, int p_Age)
{
	name = p_Name;
	age = p_Age;
}
Pet::~Pet() {}

string getname()
{
	return Pet::name;
}
int getage()
{
	return age;
}
void setName(string p_name)
{
	name = p_name;
}
void setAge(int p_age)
{
	age = p_age;
}
void eatting()
{
	cout << name << "�� ���� �԰� �ֽ��ϴ�." << endl;
}
void voice(string p_voice)
{
	cout << name << "��" << p_voice << "�ϸ� ��ϴ�" << endl;
}

