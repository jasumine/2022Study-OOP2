#pragma once

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Utils.h"


#define MAX_X 20
#define MAX_Y 20
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACEBAR 32
#define ESC 27



struct Node
{
    BOOL mine; // 지뢰
    BOOL strip; // 블록 제거
    BOOL flag; // 깃발
    int mineCnt; // 주변 지뢰 갯수
};



struct APoint
{
    int x; // 플레이어의 x 좌표
    int y; // 플레이어의 y 좌표
};



void initMap(struct Node(*gameMap)[MAX_Y], int gameLevel, int* retMineCnt);
void randMine(struct Node(*gameMap)[MAX_Y], int gameLevel, int* retMineCnt);
int gameStart(struct Node(*gameMap)[MAX_Y], int gameLevel, int* retMineCnt);
void displayMap(struct Node(*gameMap)[MAX_Y], int gameLevel, int* retMineCnt);
void mineRecursive(struct Node(*gameMap)[MAX_Y], int tmpX, int tmpY);
int resultFunc(struct Node(*gameMap)[MAX_Y], int gameLevel, int* retMineCnt, int tmpRetMineCnt);


int randx(int x, int y);
void gotoxy(int x, int y);
void textcolor(int color_number);



void main()
{
    struct Node gameMap[MAX_X][MAX_Y];
    int gameLevel = 10;
    int select;
    int retMineCnt;
    int elapsedTime = 0;
    int level1 = 999, level2 = 999, level3 = 999;

    while (1)
    {
       initMap(gameMap, gameLevel, &retMineCnt);
    }
}

void initMap(struct Node(*gameMap)[MAX_Y], int gameLevel, int* retMineCnt)
{
    int cx, cy;

    for (int i = 0; i < MAX_X - gameLevel; i++)
    {
        for (int j = 0; j < MAX_Y - gameLevel; j++)
        {
            gameMap[i][j].wall = 0;
            gameMap[i][j].flag = 0;
            gameMap[i][j].mine = 0;
            gameMap[i][j].strip = 0;
            gameMap[i][j].mineCnt = 0;
        }
    }

    for (int i = 0; i < MAX_X - gameLevel; i++)
    {
        for (int j = 0; j < MAX_Y - gameLevel; j++)
        {
            if (i == 0 || i == MAX_X - gameLevel - 1 || j == 0 || j == MAX_Y - gameLevel - 1)
                gameMap[i][j].wall = 1;
            else
                gameMap[i][j].strip = 0;
        }
    }
    randMine(gameMap, gameLevel, retMineCnt);

    for (int i = 0; i < MAX_X - gameLevel; i++)
    {
        for (int j = 0; j < MAX_Y - gameLevel; j++)
        {
            for (cx = i - 1; cx < i + 2; cx++)
            {
                for (cy = j - 1; cy < j + 2; cy++)
                {
                    if (gameMap[cx][cy].mine == 1)
                    {
                        gameMap[i][j].mineCnt++;
                    }
                }
            }
        }
    }
}

void randMine(struct Node(*gameMap)[MAX_Y], int gameLevel, int* retMineCnt)
{
    int i, j;
    int mineCntSet;

    if (gameLevel == 10)  mineCntSet = 10;
    else if (gameLevel == 5) mineCntSet = 30;
    else if (gameLevel == 0) mineCntSet = 80;
    else {}
    *retMineCnt = mineCntSet;

    do
    {
        i = randx(1, MAX_X - gameLevel - 2);
        j = randx(1, MAX_Y - gameLevel - 2);

        if (gameMap[i][j].mine == 0)
        {
            gameMap[i][j].mine = 1;
            mineCntSet--;
        }
    } while (mineCntSet);
}


int gameStart(struct Node(*gameMap)[MAX_Y], int gameLevel, int* retMineCnt)
{
    struct APoint player;
    char ch;
    int i, j;
    int tmpRetMinCnt;
    time_t startTime;
    time_t endTime;
    double elapsedTime = 0;

    time(&startTime);
    tmpRetMinCnt = *retMineCnt;
    player.x = 2;
    player.y = 1;
    displayMap(gameMap, gameLevel, retMineCnt);
    gotoxy(player.x, player.y);

    while (1)
    {
        if (kbhit())
        {
            ch = getch();
            switch (ch)
            {
            case LEFT:
                if (player.x - 2 > 0) gotoxy(player.x -= 2, player.y);
                break;
            case RIGHT:
                if (player.x < (MAX_Y - gameLevel - 2) * 2) gotoxy(player.x += 2, player.y);
                break;
            case UP:
                if (player.y - 1 > 0) gotoxy(player.x, --player.y);
                break;
            case DOWN:
                if (player.y + 1 < MAX_X - gameLevel - 1) gotoxy(player.x, ++player.y);
                break;
            default:
                break;
            }

            if (ch == 'f' || ch == 'F') // flag
            {
                if (gameMap[player.y][player.x / 2].flag == 0) { gameMap[player.y][player.x / 2].flag = 1; --* retMineCnt; }
                else { gameMap[player.y][player.x / 2].flag = 0; ++* retMineCnt; }

                if (resultFunc(gameMap, gameLevel, retMineCnt, tmpRetMinCnt) == 1)
                {
                    time(&endTime);
                    elapsedTime = difftime(endTime, startTime);
                    gotoxy(((MAX_X - gameLevel) * 2) + 3, 5);
                    printf("▤ 경과 시간 : %3d 초 ", (int)elapsedTime);
                    gotoxy(((MAX_X - gameLevel) * 2) + 3, 6);
                    system("pause");
                    return (int)elapsedTime;
                }
            }
            else if (ch == SPACEBAR)
            {
                if (gameMap[player.y][player.x / 2].mine != 1)
                {
                    mineRecursive(gameMap, player.y, player.x / 2);
                    if (resultFunc(gameMap, gameLevel, retMineCnt, tmpRetMinCnt) == 1)
                    {
                        time(&endTime);
                        elapsedTime = difftime(endTime, startTime);
                        gotoxy(((MAX_X - gameLevel) * 2) + 3, 5);
                        printf("▤ 경과 시간 : %3d 초 ", (int)elapsedTime);
                        gotoxy(((MAX_X - gameLevel) * 2) + 3, 6);
                        system("pause");
                        return (int)elapsedTime;
                    }
                }
                else // 지뢰일 경우
                {
                    for (i = 0; i < MAX_X - gameLevel; i++)
                    {
                        for (j = 0; j < MAX_Y - gameLevel; j++)
                        {
                            gameMap[i][j].strip = 1;
                        }
                    }
                    displayMap(gameMap, gameLevel, retMineCnt);
                    printf("You die...!!  ");
                    gotoxy(((MAX_X - gameLevel) * 2) + 3, 5);
                    system("pause");
                    return 999;
                }
            }
            else if (ch == ESC)
            {
                return 999;
            }
            displayMap(gameMap, gameLevel, retMineCnt);
            gotoxy(player.x, player.y);
        }
        Sleep(10);
    }
}

void displayMap(struct Node(*gameMap)[MAX_Y], int gameLevel, int* retMineCnt)
{
    int i, j;

    gotoxy(0, 0);
    for (i = 0; i < MAX_X - gameLevel; i++)
    {
        for (j = 0; j < MAX_Y - gameLevel; j++)
        {
            if (gameMap[i][j].wall == 1) { printf("■"); }
            else
            {
                if (gameMap[i][j].strip == 0)
                {
                    if (gameMap[i][j].flag == 0) { printf("■"); }
                    else { printf("¶"); }
                }
                else if (gameMap[i][j].strip == 1)
                {
                    if (gameMap[i][j].mine == 1) { printf("※"); }
                    else
                    {
                        if (gameMap[i][j].mineCnt == 0) { printf("○"); }
                        else if (gameMap[i][j].mineCnt == 1) { printf("①"); }
                        else if (gameMap[i][j].mineCnt == 2) { printf("②"); }
                        else if (gameMap[i][j].mineCnt == 3) { printf("③"); }
                        else if (gameMap[i][j].mineCnt == 4) { printf("④"); }
                        else if (gameMap[i][j].mineCnt == 5) { printf("⑤"); }
                        else if (gameMap[i][j].mineCnt == 6) { printf("⑥"); }
                        else if (gameMap[i][j].mineCnt == 7) { printf("⑦"); }
                        else if (gameMap[i][j].mineCnt == 8) { printf("⑧"); }
                    }
                }
            }
        }
        printf("\n");
    }

    gotoxy(((MAX_X - gameLevel) * 2) + 3, 3); textcolor(14); printf("▤ 깃발 개수 : %2d", *retMineCnt);
    gotoxy(((MAX_X - gameLevel) * 2) + 3, 4);
}


void mineRecursive(struct Node(*gameMap)[MAX_Y], int tmpX, int tmpY)
{
    int i, j;

    if (gameMap[tmpX][tmpY].wall == 1) return;
    if (gameMap[tmpX][tmpY].strip == 1) return;
    if (gameMap[tmpX][tmpY].mineCnt)
    {
        gameMap[tmpX][tmpY].strip = 1;
        return;
    }

    gameMap[tmpX][tmpY].strip = 1;
    for (i = tmpX - 1; i < tmpX + 2; i++)
    {
        for (j = tmpY - 1; j < tmpY + 2; j++)
        {
            mineRecursive(gameMap, i, j);
        }
    }
}

int resultFunc(struct Node(*gameMap)[MAX_Y], int gameLevel, int* retMineCnt, int tmpRetMineCnt)
{
    int i, j;
    int stripCnt = 0;
    int tmpCnt;
    tmpCnt = tmpRetMineCnt;

    for (i = 0; i < MAX_X - gameLevel; i++)
    {
        for (j = 0; j < MAX_Y - gameLevel; j++)
        {
            if (gameMap[i][j].wall != 1 && gameMap[i][j].strip == 0) stripCnt++;
        }
    }
    if (*retMineCnt == 0 && stripCnt == tmpCnt)
    {
        displayMap(gameMap, gameLevel, retMineCnt);

        gotoxy(((MAX_X - gameLevel) * 2) + 3, 4);
        printf("Good...!!  ");
        gotoxy(((MAX_X - gameLevel) * 2) + 3, 5);
        return 1;
    }
    return 0;
}


int randx(int x, int y)
{
    static int flag = 0;
    int retVal;
    if (flag == 0)
    {
        srand(time(NULL));
        rand(); rand(); rand(); rand();
        srand(rand());
        flag = 1;
    }
    retVal = rand() % (y - x + 1) + x;
    return retVal;
}

void gotoxy(int x, int y)
{
    COORD cd;
    cd.X = x;
    cd.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

Position pos;


