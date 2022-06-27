#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

// 선형 자료구조 백준 풀이
#pragma region 에디터 백준
//int main()
//{
//	// 0. 입출력 속도를 향상 시킨다.
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	// 1. 문자열을 입력 받는다
//	string s; // 문자열
//	cin >> s;
//
//	// 2. 명령어의 개수를 입력 받는다.
//	int M;
//	cin >> M;
//
//	// 3. 명령어를 처리한다.
//	list<char> lst(s.begin(), s.end());
//	list<char>::iterator cursor = lst.end();
//
//	//string::size_type cursor = s.size() - 1;
//	
//	while (M--)
//	{
//		// 3-1. 명령어를 입력 받는다. 
//		char op;
//		cin >> op;
//
//		// 3-2. 각 명령어에 맞게 실행한다.
//		switch (op)
//		{
//		case'L':
//			if (cursor != lst.begin())
//			{
//				--cursor;
//			}
//			
//			break;
//		case'D':
//			if (cursor != lst.end())
//			{
//				++cursor;
//			}
//			
//			break;
//		case'B':
//			// 문자를 지운 후 커서 위치 업데이트 필요함.
//			if (cursor != lst.begin())
//			{
//				--cursor;
//				cursor = lst.erase(cursor);
//			}
//	
//			break;
//		case'P':
//			// 문자를 추가하기 전에 위치를 업데이트 해줘야 함.
//			char param;
//			cin >> param;
//
//			cursor = lst.insert(cursor, param);
//			cursor++;
//	
//			break;
//		}
//	}
//
//	// 4. 출력
//	for (list<char>::iterator iter = lst.begin(); iter != lst.end(); iter++)
//	{
//		cout << *iter;
//	}
//}
#pragma endregion

#pragma region 키로거
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	int TestCase;
//	cin >> TestCase;
//	while (TestCase--)
//	{
//		// 1. 문자열을 입력 받는다.
//		string input;
//		cin >> input;
//
//		//for (char ch : input) { 컨테이너를 수정하면 안된다. -> 컨테이너에 데이터를 삭제, 삽입하면 안된다. }// 모든 문자열 순회
//
//		// 2. 컨테이너 2개를 받는다
//		// 2-1. 하나는 커서 왼편에 존재하는 문자열로 정방향으로 저장
//		// 2-2. 다른 하나는 커서 오른편에 존재하는 문자열로 역방향으로 저장
//		vector<char> left, rightReversed;
//
//		// 3. 각 문자열을 적절하게 처리한다.
//		// 알파벳 대소문자, 숫자, 백스페이스(-), 화살표(<>)
//		for (char ch : input)
//		{
//			switch (ch)
//			{
//			case '<':
//				if (false == left.empty())
//				{
//					rightReversed.push_back(left.back());
//					left.pop_back();
//				}
//				break;
//			case '>':
//				if (false == rightReversed.empty())
//				{
//					left.push_back(rightReversed.back());
//					rightReversed.pop_back();
//				}
//				break;
//			case '-':
//				if (false == left.empty())
//				{
//					left.pop_back();
//				}
//				break;
//			default:
//				left.push_back(ch);
//				break;
//			}
//		}
//	cout << string(left.begin(), left.end()) << string(rightReversed.rbegin(), rightReversed.rend()) << "\n";
//	}
//}
#pragma endregion
