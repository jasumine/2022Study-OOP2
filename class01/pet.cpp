#pragma once
#include <iostream>
#include <string>
#include "pet.h"

Pet::Pet() {	} // 생성자
	
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
	cout << name << "이 밥을 먹고 있습니다." << endl;
}
void voice(string p_voice)
{
	cout << name << "이" << p_voice << "하며 웁니다" << endl;
}

