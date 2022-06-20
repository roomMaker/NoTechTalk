#include <iostream>

using namespace std;
int main()
{
	srand(time(NULL));
	int maxNum = 0, numCount = 0;
	bool isInsert = true;
	cout << "최대값 : ";
	cin >> maxNum;
	cout << "생성숫자 : ";
	cin >> numCount;

	// 최대값보다 생성숫자가 많으면 원하는 결과가 나오지 않음
	if (maxNum < numCount)
	{
		cout << "생성불가";
		return 0;
	}

	int* result = new int[numCount]; // numCount 만큼의 크기의 결과를 출력 할 배열 생성

	for (int i = 0; i < numCount;)
	{
		result[i] = 1 + rand() % maxNum;
		for (int j = 0; j < i; j++)
		{
			// 지금까지 들어간 수들과 비교하여 기존에 없던 숫자면 true 반환
			if (result[i] != result[j])
			{
				isInsert = true;
			}
			else
			{
				isInsert = false;
				break;
			}
		}
		// 기존에 없던 숫자면 배열에 저장
		if (isInsert)
		{
			cout << result[i] << endl;
			isInsert = false;
			i++;
		}
		
	}

	delete[] result;
	return 0;
}