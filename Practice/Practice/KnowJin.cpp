#include <iostream>
#include <Windows.h>
void SeeKnowJin();

int knowTalk = 0;
int main()
{
	srand(time(NULL));
	while (1) 
	{
		SeeKnowJin();
	}
	return 0;
}

void SeeKnowJin()
{
	
	knowTalk++;
	if (knowTalk == 7) knowTalk = 1;
	switch (knowTalk)
	{
	case 1:
		std::cout << "\"������� ��ũ��\"�� �����غ���?" << std::endl;
		break;
	case 2:
		std::cout << "\"������� �⸳��¯����\"" << std::endl;
		break;
	case 3:
		std::cout << "������ ��� �� ������� ����?" << std::endl;
		break;
	case 4:
		std::cout << "������� �� �̻ڳ�..." << std::endl;
		break;
	case 5:
		std::cout << "\"������� ��������\"" << std::endl;
		break;
	case 6:
		std::cout << "�������? �� ���ο���" << std::endl;
		Sleep(1000);
		system("cls");
		break;
	}
		Sleep(1000);
	
}