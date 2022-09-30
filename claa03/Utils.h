#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <Windows.h>


struct Position {
	int x;
	int y;

	Position(int x, int y) : x(x), y(y) {}
};

typedef Position Dimension;

class Borland {

	/*
	* 멤버변수를 객체화 시켜야 사용이 가능하다. 객체화 = 변수로 만든다.
	* 변수-> 전역변수, 지역변수 / 가능한 전역변수는 만들지 않는다.
	* 객체 지향= 모든 것은 class내에 소속되어야 한다.
	* class 내에 멤버변수, 멤버함수 앞에 static을 붙이면 전역변수, 전역함수처럼 쓸 수 있다. -> 객체화 시키지 않아도 된다.
	* => 전역변수를 쓰면 안되는데 static을 이용해 꼼수처럼 쓸 수 있다. 객체지향 개념에 위배되지만 필요한 경우가 있어서 사용한다.
	*/

public:
	static void Initialize()
	{
		CONSOLE_CURSOR_INFO cci;
		cci.dwSize = 25;
		cci.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
		SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	}

	static int WhereX() // 현재 마우스커서의 X좌표
	{
		CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
		return csbiInfo.dwCursorPosition.X;
	}
	static int WhereY() // Y좌표
	{
		CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
		return csbiInfo.dwCursorPosition.Y;
	}
	static void GotoXY(int x, int y) // 마우스의 좌표를 바꿀 수 있다.
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _COORD{ (SHORT)x, (SHORT)y });
	}
	static void GotoXY(const Position* pos)
	{
		if (!pos) return;
		GotoXY( (*pos).x, (*pos).y);
	}
	static void GotoXY(const Position& pos)
	{
		GotoXY( pos.x, pos.y);
	}
};

#endif 
