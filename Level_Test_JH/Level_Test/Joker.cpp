#include "Joker.h"
using namespace std;


int main()
{
	srand(time(NULL));
	Deck decks[8];
	for (int i = 0; i < 8; i++)
	{
		if (false == decks[i].Make())
		{
			cout << i + 1 << "��°�� �� ���� ����\n";
		}
	}

	for (int i = 0; i < 8; i++)
	{
		cout << decks[i].ToString() << '\n';
	}
}