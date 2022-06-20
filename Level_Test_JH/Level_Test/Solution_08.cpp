#include <iostream>

using namespace std;

int main()
{
	int N = 0, j = 0, k = 0, insertArr = 1;
	// 오른쪽방향으로, 아랫쪽방향으로, 왼쪽방향으로, 윗쪽방향으로에 해당하는 4가지 상태를 나타낼 변수
	int flag = 0;

	// 얼마나 반복할지 알려주려고 만든 변수
	int len;


	cout << "배열의 크기를 입력하세요 : ";
	scanf_s("%d", &N);

	// 2차원 동적 배열 할당 (배열 생성하는건 구글링 했습니다 ㅠ)
	int** arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
	}

	// j 와 k 에 영향을 줄 변수, 계속 증가하면서 위치를 지정하는 역할
	int jUp = 0, kUp = 1;
	len = N - 1;

	
	while(len >= 0)
	{
		// flag가 각각 0일때는 오른쪽, 1일때는 아랫쪽, 2일때는 왼쪽, 3일때는 윗쪽으로 
		// 숫자가 이미 들어간 곳과 겹치지 않게 insertArr를 1씩 증가시키면서 달팽이 모양으로 삽입
		switch (flag)
		{
		case 0:
			for (j = jUp ; j <= len; j++)
			{
				arr[k][j] = insertArr;
				insertArr++;
			}
			flag++;
			jUp++;
			j--;
			break;
		case 1:
			for (k = kUp; k <= len; k++)
			{
				arr[k][j] = insertArr;
				insertArr++;
			}
			flag++;
			kUp++;
			len--;
			k--;
			break;
		case 2:
			for (j = len; j >= jUp - 1; j--)
			{
				arr[k][j] = insertArr;
				insertArr++;
			}
			flag++;
			j++;
			break;
		case 3:
			for (k = len; k >= kUp - 1; k--)
			{
				arr[k][j] = insertArr;
				insertArr++;
			}
			flag = 0;
			k++;
			break;
		};
		
	}

	// 출력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl << endl;
	}
	return 0;
}