#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int result[100000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	priority_queue<int> que;
	int N, input;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		que.push(input);
		
	}
	for (int i = 0; i < N; i++)
	{

	}
	return 0;
}
