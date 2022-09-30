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
	* ��������� ��üȭ ���Ѿ� ����� �����ϴ�. ��üȭ = ������ �����.
	* ����-> ��������, �������� / ������ ���������� ������ �ʴ´�.
	* ��ü ����= ��� ���� class���� �ҼӵǾ�� �Ѵ�.
	* class ���� �������, ����Լ� �տ� static�� ���̸� ��������, �����Լ�ó�� �� �� �ִ�. -> ��üȭ ��Ű�� �ʾƵ� �ȴ�.
	* => ���������� ���� �ȵǴµ� static�� �̿��� �ļ�ó�� �� �� �ִ�. ��ü���� ���信 ��������� �ʿ��� ��찡 �־ ����Ѵ�.
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

	static int WhereX() // ���� ���콺Ŀ���� X��ǥ
	{
		CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
		return csbiInfo.dwCursorPosition.X;
	}
	static int WhereY() // Y��ǥ
	{
		CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
		return csbiInfo.dwCursorPosition.Y;
	}
	static void GotoXY(int x, int y) // ���콺�� ��ǥ�� �ٲ� �� �ִ�.
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
