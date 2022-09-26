#pragma once
#include "Pet.h"
class Dog :
    public Pet
{
public:

    Dog(string name, int age) :Pet(name, age)
    {
    }
};

