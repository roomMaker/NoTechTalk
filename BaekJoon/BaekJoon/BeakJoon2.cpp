#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[1001];
int N, M, V;

//DFS , BFS �⺻ Ʋ

// 1. �湮 ���θ� ������ ������ �����Ѵ�.
// 2. DFS��� ����, BFS��� ť�� �����Ѵ�. => ���� ����Ǵ� �����ʹ� ������ �湮�� ����
// 3. �� �̻� �湮�� ������ ���� ������ �湮�Ѵ�.


void dfs()
{
	// 1. �湮 ���θ� �����ؾ� ��.
	bool isVisited[1001] = {false};

	stack<int> st; // ���ÿ��� ������ �湮�� ������ ����ȴ�.

	st.push(V);
	isVisited[V] = true;

	// ���̻� �湮�� ������ ���� ������ �湮�Ѵ�.
	while (st.empty() == false) // ������ ����ٸ� ��� ������ �湮 �� ��
	{
		// ������ �湮�Ѵ�.
		int node = st.top();
		st.pop();
		cout << node << " ";

		// �������� �湮�� ������ ã�´�
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
	// 1. �湮 ���θ� �����ؾ� ��.
	bool isVisited[1001] = { false };

	queue<int> que; // ���ÿ��� ������ �湮�� ������ ����ȴ�.

	que.push(V);
	isVisited[V] = true;

	// ���̻� �湮�� ������ ���� ������ �湮�Ѵ�.
	while (que.empty() == false) // ������ ����ٸ� ��� ������ �湮 �� ��
	{
		// ������ �湮�Ѵ�.
		int node = que.front();
		que.pop();
		cout << node << " ";

		// �������� �湮�� ������ ã�´�
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