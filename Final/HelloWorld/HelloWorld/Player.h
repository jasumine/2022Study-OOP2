#pragma once
#include <conio.h>
#include "GameObject.h"

class Enemy;

class Player :
    public GameObject
{
	GameObject* target;
	Position<float> targetPos;

	void processInput();

	void move();

	GameObject* findNearestTarget();


public:
	Player(const char* shape, const Position<int>& pos, Screen& screen, InputSystem& input, Dimension dim = { 1,1 });

	void update() override;

	void draw() override
	{	
		GameObject::draw();
	}

	void setTarget(GameObject* target) { this->target = target; }
	
};

