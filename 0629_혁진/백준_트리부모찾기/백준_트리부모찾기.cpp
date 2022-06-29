#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int parr[100001];
vector<int> tree[100001];
bool isVisited[100001] = { false };

void dfs(int loot)
{
	// 루트가 되면 트루로 바꾼다.
	isVisited[loot] = true;
	// 트리 사이즈만큼 반복
	for (int i = 0;i < tree[loot].size();i++)
	{
		// 다음 방문할 곳은 tree[loot][i]
		int next = tree[loot][i];
		// 만약에 아직 안 간 곳이면
		if (isVisited[next] == false)
		{
			// arr[k][i] = 루트 값이 됨
			parr[next] = loot;
			dfs(next);
			// 후위 순회 보기cout << next << " ";
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	// 트리에 값을 입력 받는다.
	for (int i = 1; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	//cout << "후위 순회 : ";
	dfs(1);
	//cout << "\n";
	for (int i = 2; i <= N; ++i)
	{
		cout << parr[i] << "\n";
	}
}