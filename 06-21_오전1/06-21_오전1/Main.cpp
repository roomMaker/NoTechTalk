#include <iostream>
#include "ForwardListNode.h"
#include <forward_list>
using namespace std;

int main()
{
	std::forward_list<int> flist;
	ForwardList mylist;

	flist.push_front(1); // [1]
	mylist.push_front(1); // [1]

	if (flist.front() == mylist.front())
	{
		std::cout << "같음";
	}


	forward_list<int>::iterator iter = flist.begin();
	ForwardList::iterator liter = mylist.begin();

	mylist.insert_after(mylist.begin(), 3); // [1] [] [3] 
	liter++;

	cout << *liter << "\n";

	std::cout << "myflist 첫번째 값: " << mylist.front() << "\n";

	mylist.clear();

	if (mylist.empty())
	{
		cout << "mylist는 비었음." << "\n";
	}

	for (int i = 0; i < 10; i++)
	{
		mylist.push_front(i);
	}
	
	cout << "\n" << "테스트: ";
	for (liter = mylist.begin(); liter != mylist.end(); ++liter)
	{
		cout << "[" <<  * liter << "]" << " ";
	}

	mylist.erase_after(mylist.begin());
	
}