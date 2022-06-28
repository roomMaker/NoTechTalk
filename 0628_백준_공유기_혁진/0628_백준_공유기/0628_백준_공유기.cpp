#include <iostream>
#include <algorithm>
using namespace std;


int N, C;
int x[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 집의 개수와 공유기의 개수를 입력 받는다.
	cin >> N >> C;

	// 2. 집의 좌표를 입력 받는다.
	for (int i = 0; i < N; ++i)
	{
		cin >> x[i];
	}

	// 2-1. 공유기 사이의 거리를 구하기 위해 집의 좌표를 정렬한다.
	sort(x, x + N);

	// 2-2. 이진 검색을 할 범위는 가장 인접한 공유기 사이의 거리 => [1, x[N - 1]]

	// 3. 최대 거리를 구한다.
	int s = 1;
	int e = x[N - 1] - 1;
	int answer = 0;
	int d;
	while (s < e)
	{
		// 4-1. 중앙값을 해의 후보로 정한다.
		// s : 1, e : 10, m : 5
		int m = (s + e) / 2;

		// 4-2. 실제로 m 거리만큼 떨어뜨렸을 때, 몇 개의 공유기가 필요한지 계산한다.
		int count = 1;
		int p = 0; // 간격
		for (int i = 0; i < C; ++i)
		{
			if (x[i] - x[p] >= m)
			{
				++count;
				p = i;
			}
		}

		if (count < C)
		{
			e = m;
		}
		else
		{
			// 4-3. 최대 길이 최신화
			if (answer < m)
				answer = m;
			// 4-4. 더 찾을 수 있는지 범위 조절
			s = m + 1;
		}
		
	}

	// 5. 최대 거리를 출력한다.
	cout << answer;
	



}