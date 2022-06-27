#include <iostream>
#include <string>
using namespace std;

// 저장 될 큐
int Que[2000001] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 명령의 수 N
	int N = 0;
	cin >> N;

	// 1-1. 명령할 때 움직이는 count, 첫값 고정 first.
	int count = 0;
	int first = 0;

	// 2. 명령한다

	for (int i = 0; i < N; i++)
	{
		// 2=1. 명령어 입력
		string InputC;
		cin >> InputC;
		// 2-2. 정수 X 넣기
		int X = 0;

		// push X
		if (InputC == "push")
		{
			cin >> X;
			Que[count] = X;
			count++;
		}

		if (InputC == "pop")
		{
			if (Que[first] == NULL)
			{
				cout << "-1\n";
			}

			else
			{
				// 가장 앞 정수를 출력한다.
				cout << Que[first] << "\n";
				first++;
			}
		}

		if (InputC == "size")
		{
			cout << count - first << "\n";
		}

		if (InputC == "empty")
		{
			if (Que[first] == NULL)
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}

		if (InputC == "front")
		{
			if (Que[first] != NULL)
			{
				cout << Que[first] << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}

		if (InputC == "back")
		{
			if (Que[first] != 0 || Que[count] != 0)
			{
				cout << Que[count - 1] << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
	}
	return 0;
}