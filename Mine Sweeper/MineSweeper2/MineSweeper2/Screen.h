#pragma once
#include <iostream>

using namespace std;

class Screen
{


public:
	void girdSpace()
	{
		// 1. 10X10 gird 화면 생성
		cout << "\t\tWASD -  이동" << endl;
		cout << "\t\tR - 클릭" << endl;
		cout << "\t\tF - 깃발(#)" << endl;
		cout << "\t\tQ - 게임 종료" << endl;
		cout << "\t\t> - 현재 위치 표시" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << "\t";
			for (int k = 0; k < 41; k++)
			{
				cout << "-";
			}

			cout << endl;
			cout << "\t";
			for (int j = 0; j < 11; j++)
			{
				cout << "I   ";
			}
			cout << endl;
		}
		cout << "\t";
		for (int k = 0; k < 41; k++)
		{
			cout << "-";
		}
	}

};