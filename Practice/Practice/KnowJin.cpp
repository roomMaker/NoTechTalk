#include <iostream>
#include <Windows.h>
void SeeKnowJin();


int main()
{
	int count = 0;
	srand(time(NULL));
	while (1) 
	{
		SeeKnowJin();
		if (count == 20)
		{
			system("cls");
			count = 0;
		}
		count++;
	}
	return 0;
}

void SeeKnowJin()
{
	int knowTalk = 0;
	knowTalk = 1 + rand() % 6;
	switch (knowTalk)
	{
	case 1:
		std::cout << "허벅지가 참 이쁘네..." << std::endl;
		break;
	case 2:
		std::cout << "\"노우진식 기립팔짱수면\"" << std::endl;
		break;
	case 3:
		std::cout << "오늘은 어느 쪽 허벅지를 볼까?" << std::endl;
		break;
	case 4:
		std::cout << "\"노우진식 테크톡\"을 시작해볼까?" << std::endl;
		break;
	case 5:
		std::cout << "쥬라기공원? 좀 별로였어" << std::endl;
		break;
	case 6:
		std::cout << "\"노우진식 간접참조\"" << std::endl;
		break;
	}
		Sleep(rand() % 1000);
	
}