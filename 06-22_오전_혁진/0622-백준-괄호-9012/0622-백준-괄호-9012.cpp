#include <iostream>
#include <string>
using namespace std;

// 0. 괄호 배열
string VPS;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 입력 개수 (TestCase)
	int T = 0;
	cin >> T;

	// 1-1. 카운트

	// 개행문자 없애주는 애
	std::cin.ignore();

	for (int i = 0; i < T; i++)
	{
		int count1 = 0;
		int count2 = 0;
		bool a = false;
		std::getline(std::cin, VPS);

		for (int i = 0; i < VPS.size();++i)
		{
			if (VPS[i] == '(')
			{
				count1++;
			}
			else if (VPS[i] == ')')
			{
				count2++;
				if (count2 > count1)
				a = true;
			}
		}
		if (count1 == count2 && a == false)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
		
	}
}