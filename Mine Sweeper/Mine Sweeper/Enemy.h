#pragma once
#include <conio.h>
#include "GameObject.h"


class Enemy :
    public GameObject
{

    void walkRandomly ()
    {
        Position pos = getPos();
        
        int idx = rand() % 9;
        switch (idx)
        {
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

    }

    void processInput()
    {
        char key;

        if (!_kbhit()) return; // 입력이 없으면 아무것도 하지 않겠다.

        Borland::GotoXY(0, 21);
        key = _getch();

        Borland::GotoXY(1, 23);
        printf("\nenemy key is %c %d\n", key, key);

        Position pos = getPos();
        /*
        switch (key)
        {
        case 'w':
            pos.y--;
            break;
        case 'a':
            pos.x--;
            break;
        case 's':
            pos.y++;
            break;
        case 'd':
            pos.x++;
            break;
        }*/
        setPos(pos);
    }
public:
    Enemy(int x, int y, Screen &screen) :GameObject('*', x, y, screen) { }

    void update() override
    {
       processInput();
    }

};

