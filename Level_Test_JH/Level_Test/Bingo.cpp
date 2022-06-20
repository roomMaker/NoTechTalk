#include "BingoTech.h"

int main()
{
	Bingo b;
	b.Init();
	while (false == b.IsCompleted())
	{
		system("cls");
		b.Print();

		cout << "숫자를 입력해주세요 : ";
		int input;
		cin >> input;

		b.Update(input);

		
	}
	
	return 0;
}