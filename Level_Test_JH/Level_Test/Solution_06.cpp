#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));

	bool isInsert = true;
	// ������ ���� ���� �и�
    const char* shape[4] = {"��", "��", "��", "��"};
	const char* cardNum[13] = {"1","2","3","4","5","6","7","8","9","10","J","Q","K"};
	// ������ ���� ���� �����ϰ� �޾ƿͼ� ����ϱ� ���� �迭
	const char* randShape[14] = {0};
	const char* randCardNum[14] = { 0 };
	int joker;
	// ��Ŀ�� �� �� ���̹Ƿ� ���� ��Ŀ�� ���Դٸ� �� ������ �ʰ� �ϱ� ���� ����
	bool haveJoker = true;
	
	
	bool endline = true;


	
	cout << "Player 1 : ";
	for (int i = 0; i < 14;)
	{
		randShape[i] = shape[rand() % 4];
		randCardNum[i] = cardNum[rand() % 13];
		// 1/53 Ȯ�� 
		joker = rand() % 53;
		for (int j = 0; j < i; j++)
		{
			// ���ݱ��� �� ���� ���ؼ� ������ ���� ī��� true ��ȯ
			if (randShape[i] != randShape[j] || randCardNum[i] != randCardNum[j])
			{
				isInsert = true;
			}
			else
			{
				isInsert = false;
				break;
			}
		}
		// ��Ŀ�� Ư���� ���̰� ���� ��Ŀ�� ������ �ʾҴٸ� ��Ŀ �й�, ���Դٸ� �н�
		if (joker == 0 && haveJoker)
		{
			cout << "Joker";
			if (i != 6)
			{
				cout << ", ";
			}
			i++;
			haveJoker = false;
			isInsert = false;
		}
		// ī�� �� �ĸ��� ���ǿ� ���� ���
		if (isInsert)
		{
			cout << randShape[i] << randCardNum[i]; 
			if (i != 6 && i != 13)
			{
				cout << ", ";
			}
			isInsert = false;
			i++;
		}
		if (i == 7 && endline)
		{
			cout << endl << "Player 2 : ";
			endline = false;
		}
	}
		
	
	

	return 0;
}

