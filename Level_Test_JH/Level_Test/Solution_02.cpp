#include <iostream>


// n을 3으로 계속 곱하면서 1000미만까지 출력 
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