#include <iostream>
#include <algorithm>
using namespace std;

int x[200000];
int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int N, C;
	cin >> N >> C;

	// ���� ��ǥ�� �Է� �޴´�.
	for (int i = 0; i < N; i++)
	{
		cin >> x[i];
	}
	// ������ ������ �Ÿ��� ���ϱ� ���� ���� ��ǥ�� ����
	sort(x, x + N);

	// ���� �˻��� �� ������ ���� ������ ������ ������ �Ÿ�
	int s = 1, e = x[N - 1] + 1;
	int answer = 0;
	while (s < e)
	{
		int m = (s + e) / 2;

		int count = 1, add = 0;
		for (int i = 0; i < N - 1; i++)
		{
			add += x[i + 1] - x[i];
			if (m <= add)
			{
				count++;
				add = 0;
			}
		}
		
		if (count < C)
		{
			e = m;
		}
		else
		{
			if (answer < m)
			{
				answer = m;
			}
			s = m + 1;
		}
	}

	cout << answer;
	return 0;

}