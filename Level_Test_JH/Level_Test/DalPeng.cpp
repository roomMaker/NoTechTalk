#include "Dalpeng.h"

int main()
{
	int inputSize;
	Snail snail;
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	cin >> inputSize;
	snail.Make(inputSize);
	snail.Print();
	snail.Clear();

	return 0;
}