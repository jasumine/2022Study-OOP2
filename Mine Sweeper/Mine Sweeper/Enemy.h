#pragma once
#include "GameObject.h"
class Enemy :
    public GameObject
{

public:
    Enemy(int x, int y) :GameObject('*', x, y){}

    // ������ġ ǥ���ϱ�
};

