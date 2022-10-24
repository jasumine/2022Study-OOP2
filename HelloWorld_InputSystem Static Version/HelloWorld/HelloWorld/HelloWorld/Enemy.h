#pragma once
#include <conio.h>
#include "GameObject.h"
class Enemy :
    public GameObject
{

    auto walkRandomly()
    {
        static Position idx2inc[] = { {-1, -1}, { 0, -1}, {1, -1}, {-1,0}, {0, 0},
            {1, 0}, { -1, 1}, {0, 1}, {1, 1} };

        setPos( getPos() + idx2inc[ rand() % 9 ] ) ;
    }

    void processInput()
    {
        auto pos = getPos();
        if (input.getKey(VK_LEFT)) { // left arraw
            pos.x--;
        }
        else if (input.getKey(VK_RIGHT)) { // right arraw
            pos.x++;
        }
        if (input.getKey(VK_UP)) { // up arraw
            pos.y--;
        }
        if (input.getKey(VK_DOWN)) { // down arraw
            pos.y++;
        }

        setPos(pos);
    }

public:
    Enemy(int x, int y, Screen& screen) 
        : GameObject('*', x, y, screen) 
    {}

    void update() override {
        //walkRandomly();
        processInput();
    }
};

