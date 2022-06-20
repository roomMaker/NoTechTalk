#pragma once

#include <iostream>

using namespace std;

#define BLANK 0;

class Bingo
{
public:

	
	//빙고판 만들기
	void Make()
	{
		srand(time(NULL));
		for (int r = 0; r < 5; r++)
		{
			for (int c = 0; c < 5; c++)
			{
				int N = 0;
				do
				{
					N = 1 + rand() % 25;
				} while (isUsed[N]);
				board[r][c] = N;
				isUsed[N] = true;
			}
		}
	}
	// 입력함수
	void Input()
	{
		// 3. 사용자로부터 입력을 받음
		cout << "숫자를 입력해주세요 : ";

		cin >> input;

		// 3-1. 오입력이 들어왔다면
		if (input < 0 || input > 25)
		{
			// 다시 시작한다.
			return;
		}
	}

	void Update()
	{
		system("cls");

		deleteNum();
		isBingoH();
		isBingoV();
		isBingoD();
		isBingoD2();
		
		bingoCount = count;
		
	}

	void deleteNum()
	{
		isExit = false;
		for (int r = 0; r < 5; r++)
		{
			for (int c = 0; c < 5; c++)
			{
				if (board[r][c] == input)
				{
					board[r][c] = BLANK;

					isExit = true;
				}
			}

			if (isExit)
			{
				break;
			}
		}
	}
	void isBingoV()
	{
		// : 세로의 모든 숫자를 지운 것

		for (int r = 0; r < 5; r++)
		{
			//isBingo[0] = true;
			for (int c = 0; c < 5; c++)
			{
				if (board[c][r] != 0)
				{
					isBingo[0] = false;
					break;
				}
			}
			if (isBingo[0])
			{
				++count;
			}
		}
	}
	void isBingoH()
	{
		// : 가로의 모든 숫자를 지운 것
		for (int r = 0; r < 5; r++)
		{
			//isBingo[1] = true;
			for (int c = 0; c < 5; c++)
			{
				if (board[r][c] != 0)
				{
					isBingo[1] = false;
					break;
				}
			}

			if (isBingo[1])
			{
				++count;
			}
		}
		//board[0][0] / board[0][1] / ... board[0][4]
	}
	void isBingoD()
	{
		// : 대각선의 모든 숫자를 지운 것

		// board[0][0] / [1][1] / [2][2] / [3][3] / [4][4]
		for (int r = 0; r < 5; r++)
		{
			//isBingo[2] = true;

			for (int i = 0; i < 5; i++)
			{
				if (board[i][i] != 0)
				{
					isBingo[2] = false;
					break;
				}
			}

			if (isBingo[2])
			{
				count++;
			}
		}

	}

	void isBingoD2()
	{
		// [0][4] / [1][3] / [2][2] / [3][1] / [4][0]
		for (int r = 0; r < 5; r++)
		{
			//isBingo[3] = true;

			for (int i = 0; i < 5; i++)
			{
				if (board[i][4 - i] != 0)
				{
					isBingo[3] = false;
					break;
				}
			}

			if (isBingo[3])
			{
				count++;
			}
		}
	}




	// 출력함수
	void Print()
	{
		for (int r = 0; r < 5; r++)
		{
			for (int c = 0; c < 5; c++)
			{
				if (board[r][c] == 0) //BLANK 쓰면 =를 의도했냐고 되물음
				{
					cout << "\t";
				}
				else
				{
					cout << board[r][c] << "\t";
				}
			}
			cout << endl;
		}
		cout << "현재 " << bingoCount << "줄의 빙고가 완성되었습니다.\n";
	}




private:
	bool isExit = false;
	bool isBingo[4] = { true };
	int input;
	int count = 0;
	int bingoCount = 0;
	int isUsed[26] = { false };
	int board[5][5];
};