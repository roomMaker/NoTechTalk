#include "Set_JH.h"
#include <initializer_list>
#include <iostream>
#define ���� std::cout << '\n'
int main()
{
	auto initList = { 10, 5, 1, 6, 17, 14, 21 };

	Set s;
	for (int elem : initList)
	{
		s.insert(elem);
	}

	s.traverseByLevelorder();
	����; ����;
	s.traverseByPreorder();
	����; ����;
	s.traverseByInorder();
	����; ����;
	s.traverseByPostorder();
}