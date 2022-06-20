#include "Dalpeng.h"

int main()
{
	int inputSize;
	Snail snail;
	cout << "배열의 크기를 입력하세요 : ";
	cin >> inputSize;
	snail.Make(inputSize);
	snail.Print();
	snail.Clear();

	return 0;
}