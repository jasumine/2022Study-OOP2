#pragma once
#include <iostream>

using namespace std;

class Screen
{


public:
	void girdSpace()
	{
		// 1. 10X10 gird ȭ�� ����
		cout << "\t\tWASD -  �̵�" << endl;
		cout << "\t\tR - Ŭ��" << endl;
		cout << "\t\tF - ���(#)" << endl;
		cout << "\t\tQ - ���� ����" << endl;
		cout << "\t\t> - ���� ��ġ ǥ��" << endl;
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