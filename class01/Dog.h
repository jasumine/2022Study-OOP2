#pragma once
#include "pet.h"
class Dog :
    public Pet
{

public:
    Dog(string name, int age) : Pet(name, age) {} // ��� �ʱ�ȭ �Լ�

    ~Dog() {}
};

