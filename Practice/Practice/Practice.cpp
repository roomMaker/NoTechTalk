#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int playerPosX = 0, playerPosY = 0;
    char player = 'P';
    char end = 'E';
    char map[10][10] = {};
    char imsi;

    while (1)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                map[i][j] = '#';
            }
        }

        map[8][8] = end;
        map[playerPosX][playerPosY] = player;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << map[i][j];
            }
            cout << endl;
        }

        if (playerPosX == 8 && playerPosY == 8)
        {
            cout << "탈출성공!";
            break;
        }

        cout << "이동할 방향 키를 입력해주세요 : ";
        //imsi = _getch();
        imsi = getchar();

        
        switch (imsi)
        {
        case 'a':
            if(playerPosY > 0)
            playerPosY--;
            break;
        case 's':
            if(playerPosX < 9)
            playerPosX++;
            break;
        case 'd':
            if(playerPosY < 9)
            playerPosY++;
            break;
        case 'w':
            if(playerPosX > 0)
            playerPosX--;
            break;
        }
        
        
        system("cls");
    }
}
