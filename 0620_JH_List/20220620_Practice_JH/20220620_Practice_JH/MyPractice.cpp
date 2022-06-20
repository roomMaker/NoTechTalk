#include <forward_list> // std::forward_list를 쓰기 위한 헤더
#include <iostream>

using namespace std;

int main()
{
	forward_list<int> flist = {1,6,2, 5, 4};

	//flist.push_front(4);

	//flist.insert_after(flist.begin(), 3);
	auto iter = flist.begin();

	cout << *iter;
	iter++;
	cout << *iter;
	iter++;
	cout << *iter;
	iter++;
	cout << *iter;
	iter++;
	cout << *iter;



	return 0;
}