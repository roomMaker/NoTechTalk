#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);
	/*for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (arr[j] > arr[j + 1] && arr[j + 1] != NULL)
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}*/

	for (int i = 0; i < N; ++i)
	{
		cout << arr[i] << "\n";
	}
}