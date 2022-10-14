#pragma once
#include <iostream>	
#include <conio.h>
#include "Utils.h"
#include "Screen.h"


using namespace std;

class GameObject
{
	Position pos; // 위치
	char* shape;  // 모양
	Dimension dim; // 크기 
	Screen& screen; 
	// 포인터 대신 레퍼런스를 쓸 경우 ***생성할 때 초기화***를 시켜주어야 한다.
	// int b ; int &a; a=b; (X) int &a = b; (O)

public:
	GameObject(char shape, int x, int y, Screen& screen) 
		: pos(x, y), shape(nullptr), dim(1, 1), screen(screen) // &screen으로 하며 원본정보가 바뀌기 때문에 사용X
	{
		this->shape = (char*)new char[dim.size() + 1];
		this->shape[0] = shape;
		this->shape[dim.size()] = '\0'; // 널문자
	}

	virtual ~GameObject() 
	{
		delete[] shape;
	}

	Position getPos() const { return pos; }

	void setPos(const Position& pos)
	{ 
		if (screen.checkValidPos(pos) == false)
			return;
		this->pos.x = pos.x, this->pos.y = pos.y; 
	}

	char getShape() const { return shape[0]; }

	virtual void update() {}

};

