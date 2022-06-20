#pragma once
#include <iostream>
#include <string>
// Deck 타입
class Deck
{
	static bool isUsedCard[54];
	static int	remainCard;
public:
	/// <summary>
	/// 카드를 7장 뽑아서 덱을 구성한다.
	/// 모든 덱은 카드가 중복되지 않아야 한다.
	/// </summary>
	/// <returns>덱이 성공적으로 구성됐을 경우 true, 아니면 false</returns>
	bool	Make()
	{
		// isUsedCard을 순회하면서 남은 카드가 7장 이상인지를 확인한다.
		if (remainCard < 7)
		{
			return false;
		}
		// 사전 조건 : 남은 카드가 7장 이상일 때
		for (int i = 0; i < 7; i++)
		{
			int card = 0;
			do
			{
				card = 1 + rand() % 53;
			} while (isUsedCard[card]);
			_deck[i] = card;
			isUsedCard[card] = true; // 카드가 뽑았다고 알려줌
		}
		// 사후 조건 : 덱이 완성되었다.
		remainCard -= 7;
		return true;
	}
	// ToString()
	//   : 현재 덱의 카드를 표현하는 문자열을 만든다.
	//     카드가 없는 경우 "The deck is empty" 로 반환한다.
	//		예시 : :하트1:6, ◆2, ◆5, :스페이드:Q, :스페이드:K, :클럽:2, :클럽:3
	std::string ToString()
	{
		if (_deck[0] == 0)
		{
			return "The deck is empty";
		}
		std::string result;
		
		static const std::string CARD_TYPE[] = { "♠", "♣", "◆", "♥", "Joker" };
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