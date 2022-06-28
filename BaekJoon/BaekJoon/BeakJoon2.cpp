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
//	// 1. 방문 여부를 저장해야 한다.
//	static bool isVisted[25][25] = {false};
//
//	if (V == 0)
//	{
//		return;
//	}
//	// 2. DFS에 사용할 스택을 만든다.
//	stack<int> st; // 스택에는 앞으로 방문할 정점을 저장 한다.
//	st.push(V); // 첫 번째로 방문할 정점
//	cout << V << " ";
//
//	// 3. 더 이상 방문할 정점이 없을 때까지 방문한다.
//	while (!st.empty()) // 스택이 비어있다면 모든 정점을 방문한 것이다.
//	{
//		// 3-1. 정점을 방문한다.
//		int node = st.top();
//		st.pop();
//
//		// 3-2. 다음으로 방문할 정점을 찾는다.
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
		if (graph[px][py] == 1 && isVisted[px][py] == false) { //현재 정점과 연결되어있고 방문되지 않았으면
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
	// 1. 그래프 구성
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

	//// 2. 작은 정점부터 방문 시키기 위해 정렬
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