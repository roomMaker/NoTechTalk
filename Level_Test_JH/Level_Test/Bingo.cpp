#include "BingoTech.h"

int main()
{
	Bingo b;
	b.Init();
	while (false == b.IsCompleted())
	{
		system("cls");
		b.Print();

		cout << "���ڸ� �Է����ּ��� : ";
		int input;
		cin >> input;

		b.Update(input);

		
	}
	
	return 0;
}