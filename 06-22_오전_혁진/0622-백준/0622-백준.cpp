#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 수 배열 
	int stack[100000] = { 0 };
	int Wherecount = 0;
	// 1. 명령의 수 
	int input;
	cin >> input;

	// 2. 명령 입력	(1 <= M <= 100,000)

	for (int i = 0; i < input; i++)
	{
		int push_input;
		string command;
		cin >> command;

		if (command == "push")
		{
			cin >> push_input;
			stack[Wherecount] = push_input;
			Wherecount++;
		}
		else if (command == "pop")
		{
			if (stack[0] == NULL)
			{
				cout << "-1\n";
			}
			else
			{
				cout << stack[Wherecount -1] << "\n";
				stack[Wherecount-1] = NULL;
				Wherecount--;
			}
		}
		else if (command == "size")
		{
			cout << Wherecount << "\n";
		}
		else if (command == "empty")
		{
			if (stack[0] == NULL)
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (command == "top")
		{
			if (stack[0] == NULL)
			{
				cout << "-1\n";
			}
			else if(stack[Wherecount-1] != NULL)
			{
				cout << stack[Wherecount - 1] << "\n";
			}
			
		}
	}
}