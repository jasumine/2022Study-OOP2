#pragma once
class GameManager
{


};/*
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<Windows.h>
#include<conio.h>
using namespace std;

const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;

const int NOTBOMB = -2;
const int BOMB = -1;
const int BORDER = -3;
const int FLAG = -4;

const int EASY_SIZE = 12;
const int NORMAL_SIZE = 17;
const int HARD_SIZE = 22;

const int EASY_BOMB_COUNT = 5;
const int NORMAL_BOMB_COUNT = 25;
const int HARD_BOMB_COUNT = 55;

const int EASY_MODE = 1;
const int NORMAL_MODE = 2;
const int HARD_MODE = 3;


//�ʱ�ȭ �� ����Լ� 
void Init(int** map, int** check, int size, int bomb);
void Print(int** map, int** check, int size, int mode);
void AroundBomb(int** map, int size);

//�ܼ� �Լ� 
void gotoxy(int x, int y);
void setColor(int color, int bgcolor);
//�÷��� �Լ� 
void PLAY(int** map, int** check, int mode);

int main(void)
{
    int menu;
    srand((unsigned)time(NULL));
    setColor(15, 0);
    system("cls");
    while (1)
    {
        system("mode con:cols=60 lines=43");
        gotoxy(10, 10);
        setColor(13, 0);
        cout << endl;
        cout << "\t             << M E N U >>  \t" << endl;
        cout << endl;
        setColor(15, 0);
        cout << "\t       1. �ʱ� ��� ( 10 �� 10 )\t" << endl;
        cout << endl;
        cout << "\t       2. �߱� ��� ( 15 �� 15 )\t" << endl;
        cout << endl;
        cout << "\t       3. ��� ��� ( 20 �� 20 )\t" << endl;
        cout << endl;
        cout << "\t       4. ���� �ϱ�\t" << endl;
        cout << endl;
        setColor(13, 0);
        cout << "\t       �޴��� �Է��ϼ��� : ";
        cin >> menu;
        setColor(15, 0);
        system("cls");
        if (menu == 4)
            break;
        switch (menu)
        {
        case 1: {
            //�ʱ޸��

            system("mode con:cols=50 lines=35");
            int** map_easy = new int* [EASY_SIZE];
            for (int i = 0; i < EASY_SIZE; i++)
            {
                map_easy[i] = new int[EASY_SIZE];
            }
            int** check_easy = new int* [EASY_SIZE];
            for (int i = 0; i < EASY_SIZE; i++)
            {
                check_easy[i] = new int[EASY_SIZE];
            }
            Init(map_easy, check_easy, EASY_SIZE, EASY_BOMB_COUNT); //���ʱ�ȭ 
            AroundBomb(map_easy, EASY_SIZE);
            Print(map_easy, check_easy, EASY_SIZE, 1); //������Լ� 
            PLAY(map_easy, check_easy, 1);
            system("cls");
            break;
        }
        case 2: {
            //�߱޸��
            system("mode con:cols=55 lines=40");
            int** map_normal = new int* [NORMAL_SIZE];
            for (int i = 0; i < NORMAL_SIZE; i++)
            {
                map_normal[i] = new int[NORMAL_SIZE];
            }
            int** check_normal = new int* [NORMAL_SIZE];
            for (int i = 0; i < NORMAL_SIZE; i++)
            {
                check_normal[i] = new int[NORMAL_SIZE];
            }
            Init(map_normal, check_normal, NORMAL_SIZE, NORMAL_BOMB_COUNT); //���ʱ�ȭ 
            AroundBomb(map_normal, NORMAL_SIZE);
            Print(map_normal, check_normal, NORMAL_SIZE, 2); //������Լ� 
            PLAY(map_normal, check_normal, 2);
            system("cls");
            break;
        }
        case 3: {
            //��޸�� 
            //�ʱ޸��
            int** map_hard = new int* [HARD_SIZE];
            for (int i = 0; i < HARD_SIZE; i++)
            {
                map_hard[i] = new int[HARD_SIZE];
            }
            int** check_hard = new int* [HARD_SIZE];
            for (int i = 0; i < HARD_SIZE; i++)
            {
                check_hard[i] = new int[HARD_SIZE];
            }
            Init(map_hard, check_hard, HARD_SIZE, HARD_BOMB_COUNT); //���ʱ�ȭ 
            AroundBomb(map_hard, HARD_SIZE);
            Print(map_hard, check_hard, HARD_SIZE, 3); //������Լ� 
            PLAY(map_hard, check_hard, 3);
            system("cls");
            break;
        }
        case 4: {
            break;
        }
        }
    }

    return 0;
}

//��, ��ź �ʱ�ȭ �Լ� 
void PLAY(int** map, int** check, int mode)
{

    int x = 10;
    int y = 6;
    int flag = 0;
    int m_row;
    int m_col;
    int count = 0;
    gotoxy(x, y);
    while (1)
    {//������ �迭������ �����¿� �����Ӱ� Ŀ���� ������ ���̸� ��� 
        m_row = (y - 6) + 1;
        m_col = (x - 10) / 2 + 1;
        int ch = _getch();
        if (ch == 112)
            break;
        if (ch == 13)//����ڰ� �ֺ� ���� ���� ���� ���� ���� ĥ ���
        {
            if (map[m_row][m_col] == BOMB)
            {
                cout << "��";
                if (mode == EASY_MODE)            gotoxy(10, 18);
                if (mode == NORMAL_MODE)    gotoxy(10, 25);
                if (mode == HARD_MODE)        gotoxy(10, 28);
                cout << "���ӿ� �����߽��ϴ�. �޴��� ���ư��ϴ�." << endl;
                Sleep(2000);
                break;
            }
            else //��ź�� �ƴҰ�� 
            {
                int row = (y - 6) + 1;
                int col = (x - 10) / 2 + 1;

                cout << map[row][col]; // ���� ���� �����ش� .

                if (map[row - 1][col - 1] != BOMB && map[row - 1][col - 1] != BORDER && map[row - 1][col - 1] != FLAG)
                {//�ϼ�                    
                    gotoxy(x - 2, y - 1);
                    cout << map[row - 1][col - 1];
                    gotoxy(x, y);
                }
                if (map[row][col - 1] != BOMB && map[row][col - 1] != BORDER && map[row][col - 1] != FLAG)
                {//��
                    gotoxy(x - 2, y);
                    cout << map[row][col - 1];
                    gotoxy(x, y);
                }
                if (map[row + 1][col - 1] != BOMB && map[row + 1][col - 1] != BORDER && map[row + 1][col - 1] != FLAG)
                {//����
                    gotoxy(x - 2, y + 1);
                    cout << map[row + 1][col - 1];
                    gotoxy(x, y);
                }
                if (map[row + 1][col] != BOMB && map[row + 1][col] != BORDER && map[row + 1][col] != FLAG)
                {//��
                    gotoxy(x, y + 1);
                    cout << map[row + 1][col];
                    gotoxy(x, y);
                }
                if (map[row - 1][col] != BOMB && map[row - 1][col] != BORDER && map[row - 1][col] != FLAG)
                {//��
                    gotoxy(x, y - 1);
                    cout << map[row - 1][col];
                    gotoxy(x, y);
                }
                if (map[row - 1][col + 1] != BOMB && map[row - 1][col + 1] != BORDER && map[row - 1][col + 1] != FLAG)
                {//�ϵ� 
                    gotoxy(x + 2, y - 1);
                    cout << map[row - 1][col + 1];
                    gotoxy(x, y);
                }
                if (map[row][col + 1] != BOMB && map[row][col + 1] != BORDER && map[row][col + 1] != FLAG)
                {//��
                    gotoxy(x + 2, y);
                    cout << map[row][col + 1];
                    gotoxy(x, y);
                }
                if (map[row + 1][col + 1] != BOMB && map[row + 1][col + 1] != BORDER && map[row + 1][col + 1] != FLAG)
                {//����
                    gotoxy(x + 2, y + 1);
                    cout << map[row + 1][col + 1];
                    gotoxy(x, y);
                }
            }
        }
        if (ch == 32) //����ڰ� SPACE Ű ���� ��� ��� �ȱ� 
        {
            cout << "��";
            if (map[m_row][m_col] == BOMB) //��ź�ϰ��
            {
                if (check[m_row][m_col] == 0)
                {
                    check[m_row][m_col]++;
                    flag += 1;

                    if (mode == EASY_MODE)
                    {
                        if (flag == EASY_BOMB_COUNT) //���� ����߿��� ��ź�� ��� ã���� ��� 
                        {
                            gotoxy(10, 18);
                            cout << "���ڸ� ��� ã�ҽ��ϴ�!" << endl;
                            Sleep(2000);
                            break;
                        }
                    }
                    if (mode == NORMAL_MODE) {
                        if (flag == NORMAL_BOMB_COUNT)
                        {
                            gotoxy(10, 25);
                            cout << "���ڸ� ��� ã�ҽ��ϴ�!" << endl;
                            Sleep(2000);
                            break;
                        }
                    }
                    if (mode == HARD_MODE) {
                        if (flag == HARD_BOMB_COUNT)
                        {
                            gotoxy(10, 28);
                            cout << "���ڸ� ��� ã�ҽ��ϴ�!" << endl;
                            Sleep(2000);
                            break;
                        }
                    }
                }
            }
            else // ��ź�� �ƴҰ��, ����� �ȴ´�.
            {
                map[m_row][m_col] = FLAG;
            }
        }
        if (ch == 224) // ����Ű ���� 
        {
            ch = _getch();
            switch (ch)
            {
            case UP: { //�����̵�
                if (map[m_row - 1][m_col] != BORDER)
                    y -= 1;
                break;
            }
            case DOWN: { //�Ʒ��� �̵�
                if (map[m_row + 1][m_col] != BORDER)
                    y += 1;
                break;
            }
            case LEFT: {//�������� �̵�
                if (map[m_row][m_col - 1] != BORDER)
                    x -= 2;
                break;
            }
            case RIGHT: {//���������� �̵� 
                if (map[m_row][m_col + 1] != BORDER)
                    x += 2;
                break;
            }
            }
            //cout << x;
            gotoxy(x, y);

        }

    }

}

void Print(int** map, int** check, int size, int mode)
{
    int x = 10;
    int y = 6;
    int temp = 0;
    size = size - 1;
    for (int i = 1; i < size; i++)
    {
        gotoxy(x, y);
        for (int j = 1; j < size; j++)
        {
            cout << "��";
            //if (map[i][j] != BOMB)
            //{
            //    cout << "��";
            //}
            //else // bomb�̸� 
            //{
            //    cout << "��";
            //}

        }
        y = y + 1;
    }
    cout << endl;

    if (mode == EASY_MODE)
        temp = 22;
    if (mode == NORMAL_MODE)
        temp = 28;
    if (mode == HARD_MODE)
        temp = 30;
    gotoxy(10, temp - 2);
    setColor(13, 0);
    cout << "      �ر⺻ �����         " << endl;
    setColor(15, 0);
    gotoxy(10, temp);
    cout << "��: ��\t     �Ʒ�: ��" << endl;
    gotoxy(10, temp + 2);
    cout << "����: ��     ������ : ��" << endl;
    gotoxy(10, temp + 5);
    cout << "�⺻ ã��: ENTER   ���: SPACE" << endl;
    gotoxy(10, temp + 7);
    cout << "��ź�� ���:��  ����� ���:��" << endl;
    gotoxy(10, temp + 9);
    cout << "�޴��� ���ư��� : PŰ";

    gotoxy(0, 0);
}
void AroundBomb(int** map, int size)
{
    size = size - 1;
    int count = 0;
    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (map[i][j] == NOTBOMB) //��ź�� �ƴѰ��϶� ������ ��ź ���� ī��Ʈ 
            {
                if (map[i - 1][j - 1] == BOMB)
                    count++;
                if (map[i - 1][j] == BOMB)
                    count++;
                if (map[i - 1][j + 1] == BOMB)
                    count++;
                if (map[i][j + 1] == BOMB)
                    count++;
                if (map[i][j - 1] == BOMB)
                    count++;
                if (map[i + 1][j - 1] == BOMB)
                    count++;
                if (map[i + 1][j] == BOMB)
                    count++;
                if (map[i + 1][j + 1] == BOMB)
                    count++;
                map[i][j] = count;
            }
            count = 0;
        }
    }
}
void Init(int** map, int** check, int size, int bomb) {

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            map[i][j] = BORDER;
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            check[i][j] = BORDER;
        }
    }
    size = size - 1;
    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            map[i][j] = NOTBOMB;
        }
    }
    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            check[i][j] = 0;
        }
    }

    for (int i = 0; i < bomb; i++)
    {
        int x = rand() % size;
        int y = rand() % size;
        if (map[x][y] == NOTBOMB)
        {
            map[x][y] = BOMB;
        }
        else
        {
            i--;
            continue;
        }
    }
}
void gotoxy(int x, int y)
{
    COORD Pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void setColor(int color, int bgcolor)
{
    color &= 0xf;
    bgcolor &= 0xf;
    static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(std_output_handle, bgcolor << 4 | color);
}*/
