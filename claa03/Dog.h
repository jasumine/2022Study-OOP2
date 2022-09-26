#pragma once
#include "Pet.h"
#include <iostream>
#include <string>

using namespace std;

class Dog :
    public Pet
{
    unsigned char durationRattling; // in seconds 꼬리를 흔드는 상태
    // uint8_t int 8비트 타입 이라는 뜻
    // UNIT8 대문자로 표시하면 자료형이라는 의미

public:
    //cont string &name
    Dog(const char* name, int age, unsigned char durationRattling) : Pet(name, age), durationRattling(1)
    {  }

    void bark() 
    {
        cout << "bark" << endl;
    }
};

