#pragma once
#include "Pet.h"
#include <iostream>
#include <string>

using namespace std;

class Dog :
    public Pet
{
    unsigned char durationRattling; // in seconds ������ ���� ����
    // uint8_t int 8��Ʈ Ÿ�� �̶�� ��
    // UNIT8 �빮�ڷ� ǥ���ϸ� �ڷ����̶�� �ǹ�

public:
    //cont string &name
    Dog(const char* name, int age, unsigned char durationRattling) : Pet(name, age), durationRattling(1)
    {  }

    void bark() 
    {
        cout << "bark" << endl;
    }
};

