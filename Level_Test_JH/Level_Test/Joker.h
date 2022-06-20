#pragma once
#include <iostream>
#include <string>
// Deck Ÿ��
class Deck
{
	static bool isUsedCard[54];
	static int	remainCard;
public:
	/// <summary>
	/// ī�带 7�� �̾Ƽ� ���� �����Ѵ�.
	/// ��� ���� ī�尡 �ߺ����� �ʾƾ� �Ѵ�.
	/// </summary>
	/// <returns>���� ���������� �������� ��� true, �ƴϸ� false</returns>
	bool	Make()
	{
		// isUsedCard�� ��ȸ�ϸ鼭 ���� ī�尡 7�� �̻������� Ȯ���Ѵ�.
		if (remainCard < 7)
		{
			return false;
		}
		// ���� ���� : ���� ī�尡 7�� �̻��� ��
		for (int i = 0; i < 7; i++)
		{
			int card = 0;
			do
			{
				card = 1 + rand() % 53;
			} while (isUsedCard[card]);
			_deck[i] = card;
			isUsedCard[card] = true; // ī�尡 �̾Ҵٰ� �˷���
		}
		// ���� ���� : ���� �ϼ��Ǿ���.
		remainCard -= 7;
		return true;
	}
	// ToString()
	//   : ���� ���� ī�带 ǥ���ϴ� ���ڿ��� �����.
	//     ī�尡 ���� ��� "The deck is empty" �� ��ȯ�Ѵ�.
	//		���� : :��Ʈ1:6, ��2, ��5, :�����̵�:Q, :�����̵�:K, :Ŭ��:2, :Ŭ��:3
	std::string ToString()
	{
		if (_deck[0] == 0)
		{
			return "The deck is empty";
		}
		std::string result;
		
		static const std::string CARD_TYPE[] = { "��", "��", "��", "��", "Joker" };
		static const std::string CARD_NUMBER[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

		for (int i = 0; i < 7; i++)
		{
			cardTypeIndex = _deck[i] / 13;
			cardNumberIndex = _deck[i] % 13;


			if (cardTypeIndex == 4)
			{
				result += "Joker\t";
			}
			else
			{
				result += CARD_TYPE[cardTypeIndex] + CARD_NUMBER[cardNumberIndex] + "\t";
			}
		}
		return result;
	}
private:
	int		_deck[7];
	int cardTypeIndex;
	int cardNumberIndex;
};
bool Deck::isUsedCard[54] = { false };
int Deck::remainCard = 54;