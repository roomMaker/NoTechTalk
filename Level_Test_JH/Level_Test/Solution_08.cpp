#include <iostream>

using namespace std;

int main()
{
	int N = 0, j = 0, k = 0, insertArr = 1;
	// �����ʹ�������, �Ʒ��ʹ�������, ���ʹ�������, ���ʹ������ο� �ش��ϴ� 4���� ���¸� ��Ÿ�� ����
	int flag = 0;

	// �󸶳� �ݺ����� �˷��ַ��� ���� ����
	int len;


	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	scanf_s("%d", &N);

	// 2���� ���� �迭 �Ҵ� (�迭 �����ϴ°� ���۸� �߽��ϴ� ��)
	int** arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
	}

	// j �� k �� ������ �� ����, ��� �����ϸ鼭 ��ġ�� �����ϴ� ����
	int jUp = 0, kUp = 1;
	len = N - 1;

	
	while(len >= 0)
	{
		// flag�� ���� 0�϶��� ������, 1�϶��� �Ʒ���, 2�϶��� ����, 3�϶��� �������� 
		// ���ڰ� �̹� �� ���� ��ġ�� �ʰ� insertArr�� 1�� ������Ű�鼭 ������ ������� ����
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

	// ���
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