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
	/// �������� �ʱ�ȭ�Ѵ�.
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
	/// �������� ����Ѵ�.
	/// </summary>
	void Print() const
	{
		for (int r = 0; r < 5; r++)
		{
			for (int c = 0; c < 5; c++)
			{
				if (_board[r][c] == BLANK) //BLANK ���� =�� �ǵ��߳İ� �ǹ���
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
		cout << "���� " << _bingoCount << "���� ���� �ϼ��Ǿ����ϴ�.\n";
	}

	/// <summary>
	/// ���� ������Ʈ �Ѵ�.
	/// </summary>
	/// <param name="input"></param>
	void Update(int input)
	{
		
		// 3-1. ���Է��� ���Դٸ�
		if (input < 0 || input > 25)
		{
			// 2������ �ٽ� �����Ѵ�.
			return;
		}

		// 4. �������� �ֽ�ȭ => �ش� ���ڸ� �����ش�.
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
		// : ������ ��� ���ڸ� ���� ��

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
		// : ������ ��� ���ڸ� ���� ��
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
		// : �밢���� ��� ���ڸ� ���� ��
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