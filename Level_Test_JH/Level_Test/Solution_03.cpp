#include <iostream>

using namespace std;


int main()
{
	char space = ' ', star = '*';

	for (int i = 0; i < 5; i++)
	{
		// 스페이스바로 빈 공간을 만들고
		for (int j = 4 - i; j > 0; j--)
		{
			cout << space;
		}
		// 별을 출력해서 피라미드 모양을 만듦
		for (int k = 0; k <= i + i; k++)
		{
			cout << star;
		}
		cout << endl;
	}
 
	return 0;
}