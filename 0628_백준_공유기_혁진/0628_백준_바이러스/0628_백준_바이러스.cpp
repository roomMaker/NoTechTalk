#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[101];
int N, M, V = 1;

void dfs()
{
	// 1. 방문 여부를 저장해야 한다.
	bool isVisted[101] = { false };

	// 2. DFS에 사용할 스택을 만든다.
	stack<int> st; // 스택에는 앞으로 방문할 정점을 저장 한다.
	st.push(V); // 첫 번째로 방문할 정점
	isVisted[V] = true;
	int count2 = 0;
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
				count2++;
				/*cout << nextNode << ' ';*/
				isVisted[nextNode] = true;

				st.push(node);
				st.push(nextNode);
				break;
			}
		}
	}
	cout << count2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 그래프 구성
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 2. 작은 정점부터 방문 시키기 위해 정렬
	for (int i = 0; i <= N; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	// 3. DFS
	dfs();
	cout << "\n";

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "*";
		}
	}

}