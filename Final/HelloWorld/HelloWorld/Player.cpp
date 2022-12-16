#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include <memory>

using namespace std;


Player::Player(const char* shape, const Position<int>& pos, Screen& screen, InputSystem& input, Dimension dim)
	: GameObject(shape, pos, screen, input, dim), target(nullptr), targetPos(Position<float>::InvalidPosition)
{}

GameObject* Player::findNearestTarget()
{
	GameObject* target = nullptr;
	auto myPos = getPos();
	double dist = DBL_MAX;

	for (auto obj : objs)
	{
		auto enemy = dynamic_cast<Enemy*>(obj);
		if (enemy == nullptr) continue;

		auto pos = enemy->getPos();
		auto diff = pos - myPos;
		auto result = diff.sqrMagnitude();
		if (target == nullptr || result < dist) {
			dist = result;
			target = enemy;
		}
	}
	return target;
}


void Player::processInput()
{
	auto pos = getPos();
	if (input.getKey(0x57)) {
		pos.y--;
	}
	if (input.getKey(0x41)) {
		pos.x--;
	}
	if (input.getKey(0x53)) {
		pos.y++;
	}
	if (input.getKey(0x44)) {
		pos.x++;
	}
	setPos(pos);
	if (input.getKeyDown(VK_SPACE))
	{
		GameObject::pendingObjs.push_back(new Enemy("\xB0\xB0", { rand()%80, rand()%20}, screen, input, {2, 1}));
	}
}

void Player::move()
{
	auto pos = getPos();
	if (!target) {
		if (targetPos == Position<float>::InvalidPosition)
			return;
	}
	else {
		targetPos = target->getPos();
	}
	if (targetPos == pos) {
		if (target) {
			target->setEnabled(false);
			target = nullptr;
		}
		setPos(Position<int>(targetPos));
		targetPos = Position<float>::InvalidPosition;		
		return;
	}
	setPos(pos.moveForward(targetPos, 1.f));
}

void Player::update() 
{	
	if (input.getMouseButtonDown(0))
	{
		auto target = findNearestTarget();
		if (target != nullptr) {
			setTarget(target);
			return;
		}
		auto mousePos = input.getMousePosition();
		targetPos = mousePos;
	}
	else if (input.getMouseButton(1))
	{
		auto target = findNearestTarget();
		auto mousePos = input.getMousePosition();
		Position<float> pos = mousePos;
		if (target != nullptr) {
			pos = target->getPos();
		}
		auto direction = pos - getPos();
		if (direction == Position<float>( 0.0f, 0.0f) ) direction = Position<float>(1.0f, 0.0f);
		GameObject::pendingObjs.push_back(new Bullet(direction, getPos(), screen, input));
	}
	
	processInput();
	move();
}
