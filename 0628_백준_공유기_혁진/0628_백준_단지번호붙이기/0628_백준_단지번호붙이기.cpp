#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[101];
vector<int> graph2[101];
int N, M;
int house[25][25];
void dfs(int x, int y)
{
	// 1. 방문/연결 여부를 저장해야 한다.
	bool isConnected[25] = { false };
	bool isVisted[25] = { false };

	// 2. DFS에 사용할 스택을 만든다.
	stack<int> st; // 스택에는 앞으로 방문할 정점을 저장 한다.
	st.push(M); // 첫 번째로 방문할 정점
	isVisted[M] = true;
	//cout << V << " ";

	// 3. 더 이상 방문할 정점이 없을 때까지 방문한다.
	while (!st.empty()) // 스택이 비어있다면 모든 정점을 방문한 것이다.
	{
		// 3-1. 정점을 방문한다.
		int node = st.top();
		st.pop();

		// 3-2. 다음으로 방문할 정점을 찾는다.
		for (int i = 0; i < graph[node].size(); ++i)
		{
			int nextNode = graph[node][i];
			if (false == isVisted[nextNode])
			{
				cout << nextNode << ' ';
				isVisted[nextNode] = true;

				st.push(node);
				st.push(nextNode);
				break;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 그래프 구성
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> house[i][j];
		}
	}

	// 3. DFS
	dfs();
	cout << "\n";

}