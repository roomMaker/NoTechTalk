#pragma once

#define BLANK 0

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class Bingo
{
	static const int BOARD_SIZE = 5;
public :

	/// <summary>
	/// 빙고판을 초기화한다.
	/// </summary>
	void Init()
	{
		srand(time(NULL));
		bool isUsed[26] = { false };
		for (int r = 0; r < BOARD_SIZE; ++r)
		{
			for (int c = 0; c < BOARD_SIZE; ++c)
			{
				int n = 0;
				do
				{
					n = 1 + rand() % 25;
				} while (isUsed[n]);

				_board[r][c] = n;
				isUsed[n] = true;
			}
		}
	}

	/// <summary>
	/// 빙고판을 출력한다.
	/// </summary>
	void Print() const
	{
		for (int r = 0; r < 5; r++)
		{
			for (int c = 0; c < 5; c++)
			{
				if (_board[r][c] == BLANK) //BLANK 쓰면 =를 의도했냐고 되물음
				{
					cout << "\t";
				}
				else
				{
					cout << _board[r][c] << "\t";
				}
			}
			cout << endl;
		}
		cout << "현재 " << _bingoCount << "줄의 빙고가 완성되었습니다.\n";
	}

	/// <summary>
	/// 빙고를 업데이트 한다.
	/// </summary>
	/// <param name="input"></param>
	void Update(int input)
	{
		
		// 3-1. 오입력이 들어왔다면
		if (input < 0 || input > 25)
		{
			// 2번부터 다시 시작한다.
			return;
		}

		// 4. 빙고판을 최신화 => 해당 숫자를 지워준다.
		for (int r = 0; r < BOARD_SIZE; r++)
		{
			bool isExit = false;
			for (int c = 0; c < BOARD_SIZE; c++)
			{
				if (_board[r][c] == input)
				{
					_board[r][c] = BLANK;

					isExit = true;
				}
			}

			if (isExit)
			{
				break;
			}
			int count = countHorizontalBingo();
			count += countVirticalBingo();
			count += countDiagonalBingo();
			_bingoCount = count;
		}

	}

	bool IsCompleted() const
	{
		if (_bingoCount == BOARD_SIZE * 2 + 2)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}


private :
	int countHorizontalBingo() const
	{
		// : 가로의 모든 숫자를 지운 것

		int count = 0;

		for (int r = 0; r < 5; r++)
		{
			bool isBingo = true;
			for (int c = 0; c < 5; c++)
			{
				if (_board[r][c] != 0)
				{
					isBingo = false;
					break;
				}
			}

			if (isBingo)
			{
				++count;
			}
		}
		//board[0][0] / board[0][1] / ... board[0][4]
		return count;
	}
	int countVirticalBingo() const
	{
		// : 세로의 모든 숫자를 지운 것
		int count = 0;

		for (int r = 0; r < 5; r++)
		{
			bool isBingo = true;
			for (int c = 0; c < 5; c++)
			{
				if (_board[c][r] != 0)
				{
					isBingo = false;
					break;
				}
			}
			if (isBingo)
			{
				++count;
			}
		}
		return count;
	}
	int countDiagonalBingo() const
	{
		// : 대각선의 모든 숫자를 지운 것
		int count = 0;
			// board[0][0] / [1][1] / [2][2] / [3][3] / [4][4]
		for (int r = 0; r < 5; r++)
		{
			bool isBingo = true;

			for (int i = 0; i < 5; i++)
			{
				if (_board[i][i] != 0)
				{
					isBingo = false;
					break;
				}
			}

			if (isBingo)
			{
				count++;
			}

		}

		// [0][4] / [1][3] / [2][2] / [3][1] / [4][0]
		for (int r = 0; r < 5; r++)
		{
			bool isBingo = true;

			for (int i = 0; i < 5; i++)
			{
				if (_board[i][4 - i] != 0)
				{
					isBingo = false;
					break;
				}
			}

			if (isBingo)
			{
				count++;
			}
		}
		return count;
	}
private :
	int		_board[BOARD_SIZE][BOARD_SIZE] = { 0 };
	int		_bingoCount = 0;
};