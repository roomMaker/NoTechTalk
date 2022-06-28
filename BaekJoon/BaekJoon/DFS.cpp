#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
int N, M, V;

void dfs()
{
	// 1. �湮 ���θ� �����ؾ� �Ѵ�.
	bool isVisted[1001] = { false };

	// 2. DFS�� ����� ������ �����.
	stack<int> st; // ���ÿ��� ������ �湮�� ������ ���� �Ѵ�.
	st.push(V); // ù ��°�� �湮�� ����
	isVisted[V] = true;
	cout << V << " ";

	// 3. �� �̻� �湮�� ������ ���� ������ �湮�Ѵ�.
	while (!st.empty()) // ������ ����ִٸ� ��� ������ �湮�� ���̴�.
	{
		// 3-1. ������ �湮�Ѵ�.
		int node = st.top();
		st.pop();

		// 3-2. �������� �湮�� ������ ã�´�.
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

void bfs()
{
	// 1. �湮 ���θ� �����ؾ� �Ѵ�.
	bool isVisted[1001] = { false };


	// 2. DFS�� ����� ������ �����.
	queue<int> que; // ���ÿ��� ������ �湮�� ������ ���� �Ѵ�.
	que.push(V); // ù ��°�� �湮�� ����
	isVisted[V] = true;

	// 3. �� �̻� �湮�� ������ ���� ������ �湮�Ѵ�.
	while (false == que.empty()) // ������ ����ִٸ� ��� ������ �湮�� ���̴�.
	{
		// 3-1. ������ �湮�Ѵ�.
		int node = que.front();
		que.pop();
		cout << node << ' ';

		// 3-2. �������� �湮�� ������ ã�´�.
		for (int nextNode : graph[node])
		{
			if (false == isVisted[nextNode])
			{
				que.push(nextNode);
				isVisted[nextNode] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. �׷��� ����
	cin >> N >> M >> V;
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 2. ���� �������� �湮 ��Ű�� ���� ����
	for (int i = 0; i <= N; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	// 3. DFS
	dfs();
	cout << "\n";
	// 4. BFS
	bfs();

}