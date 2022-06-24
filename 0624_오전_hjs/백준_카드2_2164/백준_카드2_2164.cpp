#include <iostream>
#include <queue>
using namespace std;

// 1. N장의 카드가 있다
// 1-1. 카드는 1부터 N까지 번호가 붙어있다.
// 1-2. 1번 카드가 제일 위, N번 카드가 제일 아래다.
// 2. 제일 위 카드를 버리고, 현재 제일 위 카드를 제일 아래 카드 밑으로 옮긴다.
// 제일 마지막에 남게되는 카드를 구하는 문제

// ex) N = 4
// [1 2 3 4]
// [2 3 4] -> [3 4 2]
// [4 2] -> [4]

int main()
{
	// 카드 덱
	std::queue<int> cd;
	// 1. 명령 수
	int count = 1;
	int N;
	cin >> N;

	// 2. 카드 넣어주기
	for (int i = 1; i <= N; ++i)
	{
		cd.push(i);
	}
	// cd { 1, 2, 3, ... N }

	// 카드 하나가 남을 때 까지 
	while (cd.size() != 1)
	{
		//// 맨 윗 값을 없앤다
		cd.pop();
		// cd { 2, 3, ... N }
		
		//// 맨 윗 값을 제일 아래로 '옮긴다'
		cd.push(cd.front());
		// cd { 2, 3, ... N, 2 }
		cd.pop();
		// cd { 3, ... N, 2 }
	}
	cout << cd.front();
}