#pragma once
#include "GameObject.h"


class Enemy :
    public GameObject
{
    int enemyNumber = 0;
    const int MAX_enemyNumber = 10;
    int array[10];
public:
    Enemy(int x, int y) :GameObject('*', x, y) { array[enemyNumber], enemyNumber++; }

};

