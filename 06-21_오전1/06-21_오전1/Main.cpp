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
		std::cout << "����";
	}


	forward_list<int>::iterator iter = flist.begin();
	ForwardList::iterator liter = mylist.begin();

	mylist.insert_after(mylist.begin(), 3); // [1] [] [3] 
	liter++;

	cout << *liter << "\n";

	std::cout << "myflist ù��° ��: " << mylist.front() << "\n";

	mylist.clear();

	if (mylist.empty())
	{
		cout << "mylist�� �����." << "\n";
	}

	for (int i = 0; i < 10; i++)
	{
		mylist.push_front(i);
	}
	
	cout << "\n" << "�׽�Ʈ: ";
	for (liter = mylist.begin(); liter != mylist.end(); ++liter)
	{
		cout << "[" <<  * liter << "]" << " ";
	}

	mylist.erase_after(mylist.begin());
	
}