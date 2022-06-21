#include <forward_list> // std::forward_list를 쓰기 위한 헤더
#include <iostream>
#include "ForwardList.h"
#include "List.h"
using namespace std;

//int main()
//{
//	forward_list<int> flist = {1,6,2, 5, 4};
//
//	flist.push_front(4);
//
//	flist.insert_after(flist.begin(), 3);
//	auto iter = flist.begin();
//
//	cout << *iter;
//	iter++;
//	cout << *iter;
//	iter++;
//	cout << *iter;
//	iter++;
//	cout << *iter;
//	iter++;
//	cout << *iter;
//
//	forward_list<int> flist;
//	ForwardList mylist;
//	
//	flist.push_front(1);
//	mylist.push_front(1);
//
//	if (flist.front() == mylist.front())
//	{
//		cout << "같음\n";
//	}
//
//	forward_list<int>::iterator iter = flist.begin();
//	ForwardList::iterator myiter = mylist.begin();
//
//	for (int i = 0; i < 5; i++)
//	{
//		mylist.push_front(i);
//	}
//
//	for (myiter = mylist.begin(); myiter != mylist.end(); ++myiter)
//	{
//		cout << *myiter << '\n';
//	}
//
//	for (int i = 0; i < 5; i++)
//	{
//		flist.push_front(i);
//	}
//
//	for (iter = flist.begin(); iter != flist.end(); ++iter)
//	{
//		cout << *iter << '\n';
//	}
//	return 0;
//}

int main()
{
	List mylist;

	for (int i = 1; i < 6; i++)
	{
		mylist.push_back(i);
	}
	
	for (List::iterator iter = mylist.begin(); iter != mylist.end(); ++iter)
	{
		cout << *iter << "\n";
	}
	return 0;
}