#include <iostream>
#include <queue>
using namespace std;

int main()
{
	std::queue<int> ys;

	// 1. N번까지 사람 수 (입력)
	int N;
	cin >> N;

	// 2. K 입력(입력)
	int K;
	cin >> K;

	// 3. 요세푸스 사람 넣기

	for (int i = 1; i <= N; i++)
	{
		ys.push(i);
		// { 1, 2, 3, 4, 5, 6, 7 }
	}

	// 4. K번째를 출력하고 다음 순열에 지운다

	if (ys.front() != K)
	{
		ys.push(ys.front()); // 1, 2, (3), 4, 5, 6, 7
	}


}