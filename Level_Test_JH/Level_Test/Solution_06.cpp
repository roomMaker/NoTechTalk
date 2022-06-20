#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));

	bool isInsert = true;
	// 도형과 수를 각각 분리
    const char* shape[4] = {"♠", "♣", "♥", "◆"};
	const char* cardNum[13] = {"1","2","3","4","5","6","7","8","9","10","J","Q","K"};
	// 도형과 수를 각각 랜덤하게 받아와서 출력하기 위한 배열
	const char* randShape[14] = {0};
	const char* randCardNum[14] = { 0 };
	int joker;
	// 조커는 한 장 뿐이므로 만약 조커가 나왔다면 또 나오지 않게 하기 위한 변수
	bool haveJoker = true;
	
	
	bool endline = true;


	
	cout << "Player 1 : ";
	for (int i = 0; i < 14;)
	{
		randShape[i] = shape[rand() % 4];
		randCardNum[i] = cardNum[rand() % 13];
		// 1/53 확률 
		joker = rand() % 53;
		for (int j = 0; j < i; j++)
		{
			// 지금까지 들어간 수를 비교해서 기존에 없던 카드면 true 반환
			if (randShape[i] != randShape[j] || randCardNum[i] != randCardNum[j])
			{
				isInsert = true;
			}
			else
			{
				isInsert = false;
				break;
			}
		}
		// 조커가 특정한 수이고 아직 조커가 나오지 않았다면 조커 분배, 나왔다면 패스
		if (joker == 0 && haveJoker)
		{
			cout << "Joker";
			if (i != 6)
			{
				cout << ", ";
			}
			i++;
			haveJoker = false;
			isInsert = false;
		}
		// 카드 및 컴마를 조건에 따라 출력
		if (isInsert)
		{
			cout << randShape[i] << randCardNum[i]; 
			if (i != 6 && i != 13)
			{
				cout << ", ";
			}
			isInsert = false;
			i++;
		}
		if (i == 7 && endline)
		{
			cout << endl << "Player 2 : ";
			endline = false;
		}
	}
		
	
	

	return 0;
}

