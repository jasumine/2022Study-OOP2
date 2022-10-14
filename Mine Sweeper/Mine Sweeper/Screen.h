#pragma once
#include <iostream>
#include "Utils.h"

using namespace std;

class Screen
{
	char* lines; 
	int n_rows;
	int n_cols;

	int pos2offset(int x, int y, int n_cols) const
	{
		return y * n_cols + x;
	}

public:
	Screen(int n_rows, int n_cols)
		: n_rows(n_rows), n_cols(n_cols),
		lines(new char[n_rows * n_cols + 1])
	{
		Borland::Initialize();
		clear();
	}

	virtual ~Screen() { delete[] lines; }

	void clear()
	{
		memset(lines, ' ',sizeof(char)*(n_rows * n_cols));
	}

	void draw(const Position& pos, char shape)
	{
		int offset = pos2offset(pos.x, pos.y, n_cols);

		lines[offset] = shape;
	}

	void render()
	{
		Borland::GotoXY(0,6);
		for (int i = 0; i < n_rows; i++)
		{
			lines[i * n_cols + n_rows - 1] = '\n';
		}
		lines[n_rows * n_cols] = '\0';
		
		cout << "─────────────────" << endl;
		printf("%s", lines);
		Sleep(100); // 0.1초 
		cout << "─────────────────" << endl;
	}

	bool checkValidPos(const Position& pos) const
	{
		// 범위 설정
		/*
		if (   pos.x < 0 || pos.x >= n_cols - 1 
			|| pos.y < 0 || pos.y >= n_cols - 1 ) 
			return false;
		return true;
		*/
		if ( pos.x >= 0 && pos.x < n_cols - 1
			&& pos.y >= 0 && pos.y < n_cols - 1 )
			return true;
		 return false;


		//int offset = pos2offset(pos.x, pos.y, n_cols);
		//// 연산 우선순위를 보기.
		//// ()의 조건이 true 면 false를 반환
		//// return !(offset < 0 || offset>n_rows * n_cols);
		//return offset >= 0 && offset <= n_rows * n_cols;

	}
};

