#include <iostream>
#include <string>
using namespace std;
int Money[1000000] = { 0 };

// 숫자가 입력된다.
// 잘못된 숫자가 나오면 0을 입력하여 top 숫자를 지운다.
// 처음부터 끝까지의 총 합을 구하라.
// ex) 4(테스트 횟수) 3 -> 0(3지움) -> 4 -> 0(4지움) = 0 이 된다.
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 반복할 횟수 K를 입력한다.
	int K;
	cin >> K;

	// 2. 배열 선언
	int Where = 0;		// 위치

	// 2-1. 돈 입력
	int InputMoney = 0; // 입력한 돈
	int sumMoney = 0;	// 다 더한 값

	// 2-2. 0을 카운트 해서 뒷부분에 0 있어도 count 더해짐
	int zeroCount = 0;

	// 3. 횟수 만큼 반복하는 반복문
	for (int i = 0; i < K; i++)
	{
		cin >> InputMoney;
		Money[Where] = InputMoney;
		Where++;
	}

	// 0 뒷 숫자들을 삭제

	for (int j = K - 1; j >= 0; j--)
	{
		if (Money[j] == 0)
		{
			zeroCount++;
		}

		else if (zeroCount > 0)
		{
			Money[j] = 0;
			zeroCount--;
		}
	}

	// 4. 더한값 출력 
	for (int i = 0; i < K; i++)
	{
		sumMoney += Money[i];
	}
	cout << sumMoney << "\n";
}