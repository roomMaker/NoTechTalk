#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <string>
using namespace std;

//#FizzBuzz
/*
//1. 1에서 100까지 출력한다.
//2. 3의 배수는 숫자대신 Fizz를 출력한다
//3. 5의 배수는 숫자대신 Buzz를 출력한다.
//4. 3과 5의 공배수는 FizzBuzz를 출력한다.

int main()
{
	int i = 1;

	cout << i << endl;

	while(i < 100)
	{
		i++;

		if (i % 3 == 0 && i % 5 == 0)
		{
			cout << "FizzBuzz" << endl;
		}

		else if (i % 3 == 0)
		{
			cout << "Fizz" << endl;
		}

		else if (i % 5 == 0)
		{
			cout << "Buzz" << endl;
		}

		else
		{
			cout << i << endl;
		}

	}


	return 0;
}
*/
//#배열
/*
10명의 학생들 점수를 받아서
그 반의 평균을 계산하는
프로그램을 작성하세요.
*/
/*
int main()
{
	int i = 0;
	int num = 10;
	float result = 0;

	float avg[10] = { 0.0f };

	for (i = 0; i < num; i++)
	{
		cin >> avg[i];
		result += avg[i];
	}
	cout << result / num;
}
*/

// 탈출게임

// 1. 플레이어는 P로 표현한다.
// 1-1. 플레이어의 초기 위치는 (0,0)이다
// 2. 맵은 10x10으로 표현한다.
// 3. 탈출지점은 E로 표현한다.
// 4. 탈출지점의 위치는 (8,8)
// 5. 키입력은 w / a / s / d 이다.
/*int main()
{
	int playerX = 0, playerY = 0;
	char map[10][10] = { 0, };
	int InputKey = 0;
	// 10 x 10 map 만들고
	while (1)
	{
		system("cls");
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				map[i][j] = '#';
			}
		}

		map[8][8] = 'E';
		map[playerX][playerY] = 'P';

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}

		if (map[playerX][playerY] == map[8][8])
		{
			cout << "노우진은 테크톡을 사랑한다" << endl;
			break;
		}

		cout << "이동할 방향 키를 입력해주세요 : " << InputKey << endl;
		cout << "X : " << playerX << endl;
		cout << "Y : " << playerY;

		InputKey = _getch();
		switch (InputKey)
		{
		case 'w':
			playerX--;
			break;
		case 'd':
			playerY++;
			break;
		case 'a':
			playerY--;
			break;
		case 's':
			playerX++;
			break;
		}
	}
}
*/


void SeeNowoojin()
{
	cout << "허벅지가 참 이쁘네." << endl;
	Sleep(rand() % 100);
}

void SawNowoojin()
{
	cout << "허벅지가 참 이뻤지.." << endl;
	Sleep(rand() % 100);
}

void TaNowoojin()
{
	cout << "(손가락으로 위협하며) 허벅지가 참 이쁘네...." << endl;
	Sleep(rand() % 100);
}

void ChoiceWoo(int input)
{
	if (input == 1)
	{
		cout << "허벅지가 너무 이쁘네..." << endl;
	}

	else if (input == 2)
	{
		cout << "허벅지가 맛있어보이네...." << endl;
	}

	else if (input == 3)
	{
		cout << "허벅지가 참 이쁘네...." << endl;
	}
}

void ChoiceWoo_2(int input)
{
	if (input == 1)
	{
		while (1)
		{
			SeeNowoojin();
			SawNowoojin();
			TaNowoojin();
		}
	}

	else if (input == 2)
	{
		int random_woo;
		while (1)
		{
			random_woo = rand() % 3 + 1;
			switch (random_woo)
			{
			case 1:
				SeeNowoojin();
			case 2:
				SawNowoojin();
			case 3:
				TaNowoojin();
			}
		}
	}
}

int main()
{
	int input = 0;
	srand(time(NULL));

	cout << "NWJ이 좋아하는 것은?: " << endl;
	cout << "1. 코딩  2. 수면  3. 테크톡" << endl;
	cout << endl;
	cin >> input;

	ChoiceWoo(input);

	cout << "도망갈까?" << endl;
	cout << "1. 네  2. 아니오" << endl;
	cout << endl;
	cin >> input;

	ChoiceWoo_2(input);
}