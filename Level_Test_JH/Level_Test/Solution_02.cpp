#include <iostream>


// n�� 3���� ��� ���ϸ鼭 1000�̸����� ��� 
int main()
{
	int n = 3;

	while (n < 1000)
	{
		std::cout << n << std::endl;
		n *= 3;
	}
 
	return 0;
}