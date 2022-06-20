#include <forward_list> // std::forward_list를 쓰기 위한 헤더
#include <iostream>
using namespace std;

int main()
{
	std::forward_list<int> flist;

	// 삽입
	flist.push_front(1); // push_front() : 맨 앞에 삽입한다.
	// flist{ 1 }
	flist.insert_after(flist.begin(), 2); // insert_after(pos, value) : pos 뒤에 value를 삽입한다.
	// flist{ 1, 2 }
	flist.push_front(3); // flist { 3, 1, 2 }

	// 반복자
	std::forward_list<int>::iterator iter;
	iter = flist.before_begin();
	// [ ]->[3]->[1]->[2]->[ ]
	//  ↑
	iter = flist.begin();
	// [ ]->[3]->[1]->[2]->[ ]
	//       ↑
	iter = flist.end();
	// [ ]->[3]->[1]->[2]->[ ]
	//                      ↑

	// 삭제
	flist.pop_front(); // pop_front() : 첫 번째 원소를 삭제한다.
	// flist{ 1, 2 };
	flist.erase_after(flist.begin()); // erase_after(pos) : pos 다음 원소를 삭제한다.
	// flist{ 1 }
	flist.clear(); // clear() : 컨테이너를 전부 비운다.
	// flist{ }

	// 크기
	if (flist.empty()) // empty() : 비었는지 확인한다.
	{
		std::cout << "flist는 비었음.\n";
	}
	// 주의! 다른 컨테이너와 다르게 size()는 없음

	// 아래처럼 초기화 가능
	std::forward_list<int> flist2 = { 1, 2, 3, 4, 5 };

	// 읽기
	std::cout << "flist2.front() : " << flist2.front() << "\n"; // front() : 첫 번째 원소를 반환한다.

	// 비교 : 다른 컨테이너와 마찬가지로 == / != / > / >= / < / <= 지원
	flist = flist2;
	if (flist == flist2)
	{
		std::cout << "flist는 flist2와 같다.\n" << endl;
	}

	// C++17부터는 원소 타입을 적지 않아도 알아서 추론한다.

	std::forward_list flist3 = { 7, 1, 3, 4, 6 };
	std::forward_list flist4 = { 8, 3, 6, 9, 5 };

	cout << " flist3의 요소: ";
	for (auto iter3 = flist3.begin(); iter3 != flist3.end(); iter3++)
	{
		cout << *iter3 << " ";
	}
	cout << "\n";


	flist3.sort(); // 배열 정렬
	// flist3: sort [1 3 4 6 7]
	cout << " 정렬을 했을 때 flist3의 요소: ";
	for (auto iter3 = flist3.begin(); iter3 != flist3.end(); iter3++)
	{
		cout << *iter3 << " ";
	}
	cout << "\n";

	flist3.swap(flist4);
	// flist3: swap [8 3 6 9 5]
	cout << " flist3값) 스왑을 했을 때 : ";
	for (auto iter3 = flist3.begin(); iter3 != flist3.end(); iter3++)
	{
		cout << *iter3 << " ";
	}
	cout << "\n";
	
	// flist4: swap [1 3 4 6 7]
	cout << " flist4값) 스왑을 했을 때 : ";
	for (auto iter3 = flist4.begin(); iter3 != flist4.end(); iter3++)
	{
		cout << *iter3 << " ";
	}
	cout << "\n";

	// clear [ ]
	flist3.clear();
	cout << " 클리어를 했을 때 flist3의 요소: ";
	for (auto iter3 = flist3.begin(); iter3 != flist3.end(); iter3++)
	{
		cout << *iter3 << "클리어 되었스빈다. ";
	}
	cout << "\n";

	return 0;


}


//---------------------------------------------------------------
//int factorial(int n)
//{
//    if (n == 1)
//        return 1;
//    return n * factorial(n - 1_);
//}
//
//template<int n>
//struct FactorialTemplate
//{
//    enum { value = n * FactorialTemplate<n - 1> };
//};
//
//template<>
//struct FactorialTemplate<1>
//{
//    enum { value = 1};
//};
//
//factorial(200) // 실행시간에 계산
//// 10 * factorial(9)
//// 10 * 9 * factorial(8) ....
//
//FactorialTemplate<5>::value; // 컴파일시간에 계산
// struct FactorialTemplate<5> { enum { value = 5 * 24 } };
// struct FactorialTemplate<5> { enum { value = 4 * 6 } };
// struct FactorialTemplate<5> { enum { value = 3 * 2 } };
// struct FactorialTemplate<5> { enum { value = 2 * 1 } };
// 1에 들어갈 자리 : FactorialTemplate<4>::value
//---------------------------------------------------------------
