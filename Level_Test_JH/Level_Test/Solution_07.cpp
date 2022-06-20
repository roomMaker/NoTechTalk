#include <iostream>
using namespace std;

#define BLANK 0;

int main()
{
	// 1. 빙고 판을 초기화

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

		// 2. 빙고 현황 출력
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

		// 3. 사용자로부터 입력을 받음
		cout << "숫자를 입력해주세요 : ";
		int input;
		cin >> input;

		// 3-1. 오입력이 들어왔다면
		if (input < 0 || input > 25)
		{
			// 2번부터 다시 시작한다.
			continue;
		}

		// 4. 빙고판을 최신화 => 해당 숫자를 지워준다.
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

		// 5. 빙고 개수를 센다.
		// : 가로의 모든 숫자를 지운 것

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

		// : 세로의 모든 숫자를 지운 것

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

		// : 대각선의 모든 숫자를 지운 것

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
	// 6. 2번부터 다시 반복한다.

}