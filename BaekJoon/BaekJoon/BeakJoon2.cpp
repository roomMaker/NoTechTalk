#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[1001];
int N, M, V;

//DFS , BFS 기본 틀

// 1. 방문 여부를 저장할 변수를 생성한다.
// 2. DFS라면 스택, BFS라면 큐를 생성한다. => 각각 저장되는 데이터는 다음에 방문할 정점
// 3. 더 이상 방문할 정점이 없을 때까지 방문한다.


void dfs()
{
	// 1. 방문 여부를 저장해야 함.
	bool isVisited[1001] = {false};

	stack<int> st; // 스택에는 앞으로 방문할 정점이 저장된다.

	st.push(V);
	isVisited[V] = true;

	// 더이상 방문할 정점이 없을 때까지 방문한다.
	while (st.empty() == false) // 스택이 비었다면 모든 정점을 방문 한 것
	{
		// 정점을 방문한다.
		int node = st.top();
		st.pop();
		cout << node << " ";

		// 다음으로 방문할 정점을 찾는다
		for (int nextNode : graph[node])
		{
			if (false == isVisited[nextNode])
			{
				st.push(nextNode);
				isVisited[nextNode] = true;
				
			}
		}
		
	}

}
void bfs()
{
	// 1. 방문 여부를 저장해야 함.
	bool isVisited[1001] = { false };

	queue<int> que; // 스택에는 앞으로 방문할 정점이 저장된다.

	que.push(V);
	isVisited[V] = true;

	// 더이상 방문할 정점이 없을 때까지 방문한다.
	while (que.empty() == false) // 스택이 비었다면 모든 정점을 방문 한 것
	{
		// 정점을 방문한다.
		int node = que.front();
		que.pop();
		cout << node << " ";

		// 다음으로 방문할 정점을 찾는다
		for (int nextNode : graph[node])
		{
			if (false == isVisited[nextNode])
			{
				que.push(nextNode);
				isVisited[nextNode] = true;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	
		dfs();
		cout << "\n";
		bfs();

	
	return 0;
}