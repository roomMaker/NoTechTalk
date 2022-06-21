#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	// 리스트 생성
	list<char> mylist;
	list<char>::iterator iter = mylist.begin();

	// 문자열 입력
	char wordN[100000] = { NULL, };
	cin >> wordN;

	// 입력할 명령어 개수
	int CommandN = 100000;
	cin >> CommandN;

	// 명령어 입력
	char inputC;
	char inputC_P;

	// 리스트에 값 넣기
	for (int i = 0; i < wordN[i]; i++)
	{
		mylist.push_back(wordN[i]);
	}

	// 잘 들어갔는지 테스트
	/*for (iter = mylist.begin(); iter != mylist.end(); ++iter)
	{
		cout << *iter;
	}*/

	for (int i = 0; i < CommandN; i++)
	{
		// 입력할 명령어
		cin >> inputC;

		// 1. L (커서 왼쪽으로 한칸)
		if (inputC == 'L')
		{
			// 1-1. 문장의 맨 앞이면 무시
			if (iter != mylist.begin())
			{
				iter--;
			}
		}
		// 2. D. (커서 오른쪽으로 한칸)
		if (inputC == 'D')
		{
			// 1-2. 문장의 맨 뒤이면 무시
			if (iter != mylist.end())
			{
				iter++;
			}
		}
		// 3. B. (커서 왼쪽문자 삭제)
		if (inputC == 'B')
		{
			mylist.erase(iter--);
		}
		// 4. P $. (커서 왼쪽에 문자추가)
		if (inputC == 'P')
		{
			cin >> inputC_P;
			mylist.insert(iter, inputC_P);
		}
	}
	for (iter = mylist.begin(); iter != mylist.end(); iter++)
	{
		cout << *iter;
	}




}