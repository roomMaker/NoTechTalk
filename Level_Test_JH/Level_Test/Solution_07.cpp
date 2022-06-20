#include <iostream>
using namespace std;

#define BLANK 0;

int main()
{
	// 1. ���� ���� �ʱ�ȭ

	srand(time(NULL));
	int isUsed[26] = { false };
	int board[5][5];
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

	int bingoCount = 0;
	while (bingoCount < 12)
	{
		system("cls");

		// 2. ���� ��Ȳ ���
		for (int r = 0; r < 5; r++)
		{
			for (int c = 0; c < 5; c++)
			{
				if (board[r][c] == 0) //BLANK ���� =�� �ǵ��߳İ� �ǹ���
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
		cout << "���� " << bingoCount << "���� ���� �ϼ��Ǿ����ϴ�.\n";

		// 3. ����ڷκ��� �Է��� ����
		cout << "���ڸ� �Է����ּ��� : ";
		int input;
		cin >> input;

		// 3-1. ���Է��� ���Դٸ�
		if (input < 0 || input > 25)
		{
			// 2������ �ٽ� �����Ѵ�.
			continue;
		}

		// 4. �������� �ֽ�ȭ => �ش� ���ڸ� �����ش�.
		for (int r = 0; r < 5; r++)
		{
			bool isExit = false;
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

		// 5. ���� ������ ����.
		// : ������ ��� ���ڸ� ���� ��

		int count = 0;

		for (int r = 0; r < 5; r++)
		{
			bool isBingo = true;
			for (int c = 0; c < 5; c++)
			{
				if (board[r][c] != 0)
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

		// : ������ ��� ���ڸ� ���� ��

		for (int r = 0; r < 5; r++)
		{
			bool isBingo = true;
			for (int c = 0; c < 5; c++)
			{
				if (board[c][r] != 0)
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

		// : �밢���� ��� ���ڸ� ���� ��

		// board[0][0] / [1][1] / [2][2] / [3][3] / [4][4]

		{
			bool isBingo = true;

			for (int i = 0; i < 5; i++)
			{
				if (board[i][i] != 0)
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
		{
			bool isBingo = true;

			for (int i = 0; i < 5; i++)
			{
				if (board[i][4 - i] != 0)
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

		bingoCount = count;
	}
	// 6. 2������ �ٽ� �ݺ��Ѵ�.

}