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
    {  
        cout << "Dog constructor" << endl;
    }

    ~Dog()
    {
        cout << "Doc destructor" << endl;
    }
    void bark() 
    {
        cout << "bark" << endl;
    }

    void sleep() 
    {
        cout << "rattling "; Pet::sleep();
        // ====virtual�� �������� ���� ���====
        // dog�� sleep�� pet�� slepp�� �ƹ� ���谡 ����.
        // pet�� sleep�Լ��� ������ �Լ��� ȣ�����ش�.

        /* Dog�� Pet�� ��ӹ޾Ƽ� Dog������ Pet�� sleep�� ���� ���� ���
        Pet* parent = static_cast<Pet*>(this);
        parent->sleep();
        dog�ڽ��� pet�� �����ͷ� ���� ����Ѵ�
        */

        // ====virtaul�� ������ ���====
        // ���� ���谡 �����.
    }
};

