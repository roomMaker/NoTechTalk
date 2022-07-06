#include "Set_JH.h"
#include <initializer_list>
#include <iostream>
#define 엔터 std::cout << '\n'
int main()
{
	auto initList = { 10, 5, 1, 6, 17, 14, 21 };

	Set s;
	for (int elem : initList)
	{
		s.insert(elem);
	}

	s.traverseByLevelorder();
	엔터; 엔터;
	s.traverseByPreorder();
	엔터; 엔터;
	s.traverseByInorder();
	엔터; 엔터;
	s.traverseByPostorder();
}