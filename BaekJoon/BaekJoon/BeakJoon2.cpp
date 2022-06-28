#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int graph[27][27] = {0};
int homeCount[626] = { 0 };
int nx[4] = { 1 , -1 , 0, 0 };
int ny[4] = { 0,  0 , 1, -1 };
int hc = 0;
int N, M, V;
static bool isVisted[27][27] = { false };

//void dfs(int V)
//{
//	// 1. �湮 ���θ� �����ؾ� �Ѵ�.
//	static bool isVisted[25][25] = {false};
//
//	if (V == 0)
//	{
//		return;
//	}
//	// 2. DFS�� ����� ������ �����.
//	stack<int> st; // ���ÿ��� ������ �湮�� ������ ���� �Ѵ�.
//	st.push(V); // ù ��°�� �湮�� ����
//	cout << V << " ";
//
//	// 3. �� �̻� �湮�� ������ ���� ������ �湮�Ѵ�.
//	while (!st.empty()) // ������ ����ִٸ� ��� ������ �湮�� ���̴�.
//	{
//		// 3-1. ������ �湮�Ѵ�.
//		int node = st.top();
//		st.pop();
//
//		// 3-2. �������� �湮�� ������ ã�´�.
//		for (int i = 1; i < N; ++i)
//		{
//			for (int j = 1; j < N; j++)
//			{
//				int nextNode = graph[i][j];
//				if (false == isVisted[i][j] && nextNode == 1)
//				{
//					cout << i<<j << " ";
//					isVisted[i][j] = true;
//					homeCount[hc]++;
//					st.push(1);
//					//st.push(nextNode);
//					if (graph[i][j + 1] == 0)
//						break;
//				}
//				if (!st.empty())
//				{
//					st.pop();
//				}
//			}
//		}
//	}
//	
//}
void DFS(int x, int y) {
	isVisted[x][y] = true;
	homeCount[hc]++;
	for (int i = 0; i < 4; i++) {
		int px = x + nx[i];
		int py = y + ny[i];
		if (graph[px][py] == 1 && isVisted[px][py] == false) { //���� ������ ����Ǿ��ְ� �湮���� �ʾ�����
			DFS(px, py);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	char userInput[30][30];
	// 1. �׷��� ����
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> userInput[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			graph[i + 1][j + 1] = userInput[i][j] - 48;
		}
	}

	//// 2. ���� �������� �湮 ��Ű�� ���� ����
	//for (int i = 0; i <= N; ++i)
	//{
	//	sort(graph[i].begin(), graph[i].end());
	//}

	// 3. DFS
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (graph[i][j] != 0 && isVisted[i][j] == false)
			{
				DFS(i, j);
				hc++;
			}
		}
	}

	cout << hc << '\n';
	sort(homeCount, homeCount + hc);
	for (int i = 0; i < hc; i++)
	{
		cout << homeCount[i] << "\n";
	}
	
}