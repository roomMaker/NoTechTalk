#include <iostream>

void soltArray(int* arr, int n);

int main()
{
	int arr[5] = { 5, 2, 4, 1, 3 };

	soltArray(arr, sizeof(arr) / 4); // int 배열이므로 배열의 총 사이즈 / 4 로 수의 갯수를 구한다.
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i];
	}
	
	return 0;
}


// j 번째 와 j + 1 번째 수를 j 를 1씩 증가시키면서 크기를 비교하며
// 더 작은 수를 만날경우 서로 위치를 바꾸는 작업을 반복 수행하여 정렬
void soltArray(int* arr, int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}