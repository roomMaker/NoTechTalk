#include <iostream>
#include <list>
#include "List.h"
using namespace std;

int main()
{
	List mylist;
	std::list<int> flist;

	/*mylist.push_front(1);
	flist.push_front(1);*/

	
	
	auto iter = mylist.begin();
	cout << "현재 mylist 첫번째 값: " << *iter << "\n";

	for (int i = 0; i < 10; i++)
	{
		mylist.push_front(i);
		// [1] [1] [2] ... [8] [9] 
		flist.push_front(1);
	}
	if (flist.front() == mylist.front())
	{
		cout << "같음\n";
	}
	for (iter = mylist.begin(); iter != mylist.end(); ++iter)
	{
		cout << "[" << *iter << "]" << " ";
	}
}