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
		std::cout << "������� �� �̻ڳ�..." << std::endl;
		break;
	case 2:
		std::cout << "\"������� �⸳��¯����\"" << std::endl;
		break;
	case 3:
		std::cout << "������ ��� �� ������� ����?" << std::endl;
		break;
	case 4:
		std::cout << "\"������� ��ũ��\"�� �����غ���?" << std::endl;
		break;
	case 5:
		std::cout << "�������? �� ���ο���" << std::endl;
		break;
	case 6:
		std::cout << "\"������� ��������\"" << std::endl;
		break;
	}
		Sleep(rand() % 1000);
	
}