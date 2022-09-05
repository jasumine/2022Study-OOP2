#pragma once
#include "pet.h"
class Dog :
    public Pet
{

public:
    Dog(string name, int age) : Pet(name, age) {} // 멤버 초기화 함수

    ~Dog() {}
};

