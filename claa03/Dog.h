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
        // ====virtual로 선언하지 않은 경우====
        // dog의 sleep과 pet의 slepp은 아무 관계가 없다.
        // pet의 sleep함수를 스코프 함수로 호출해준다.

        /* Dog는 Pet을 상속받아서 Dog내에서 Pet의 sleep을 쓰고 싶은 경우
        Pet* parent = static_cast<Pet*>(this);
        parent->sleep();
        dog자신을 pet의 포인터로 만들어서 사용한다
        */

        // ====virtaul로 선언한 경우====
        // 서로 관계가 생긴다.
    }
};

