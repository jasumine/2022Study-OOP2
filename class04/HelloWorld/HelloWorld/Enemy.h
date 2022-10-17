#pragma once
#include <conio.h>
#include "GameObject.h"
class Enemy :
    public GameObject
{

    auto walkRandomly()
    {   
        static Position idx2inc[] = { { -1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0, 0},
            {1, 0} , { -1, 1}, {0 ,1}, { 1, 1} };
        auto pos = getPos();
        setPos(pos + idx2inc[rand() % 9]);
        /*
        auto idx = rand() % 9;
        setPos(pos + idx2inc[idx]); 
        */
        /*
        switch (idx) {
        case 0:
            pos.x--; pos.y--;
            break;
        case 1:
            pos.y--;
            break;
        case 2:
            pos.x++; pos.y--;
            break;
        case 3:
            pos.x--;
            break;
        case 4:
            break;
        case 5:
            pos.x++;
            break;
        case 6:
            pos.x--; pos.y++;
            break;
        case 7:
            pos.y++;
            break;
        case 8:
            pos.x++; pos.y++;
            break;
        }

        setPos(pos);
        */
    }

    void processInput()
    {
        auto pos = getPos();
        if(input.getKey(224,'K'))// left arrow}
        {
            pos.x--;
        }
        else if (input.getKey(224, 'M')) // right arrow
        {
            pos.x++;
        }
        else if (input.getKey(224,'H')) // up arrow
        {
            pos.y--;
        }
        else if (input.getKey(2224, 'P')) // down arrow
        {
            pos.y++;
        }
       
    }

public:
    Enemy(int x, int y, Screen& screen, InputSystem& input) 
        : GameObject('*', x, y, screen, input) {}

    void update() override {
       // walkRandomly();
        processInput();
    }

    void draw() override
    {
        static int count = 0;
        if (count++ % 2)return; // 홀수 일때는 그리지말고

        GameObject::draw(); // 짝수일때만 그리기
        screen.draw(getPos() + Position{ 0, -1 }, 'E'); // 현재위치 위에 Enemy 표시

    }
};

