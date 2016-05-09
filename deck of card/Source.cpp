#include <iostream>
#include <set>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Play.h"

using std::cout;
using std::cin;

int main()
{

	Deck deck;
	Hand hand;
	Play pokerGame;

	pokerGame.playgame();

	/*while (!deck.isEmpty())
	{
		std::cout << deck.draw()->toString() << std::endl;
	}*/
	/*for (int j = 0; j < 100; ++j)
	{
		for (int i = 0; i < 5; ++i)
		{
			std::cout << deck.draw()->toString() << " ";
		}
		std::cout << std::endl;
		deck.shuffle();
	}*/

	
		/*	deck.shuffle();
	while (hand.size() < 5)
	{
		hand.addCard(deck.draw());
	}

	std::cout << hand.toString() << std::endl;
	hand.isPair();*/
	
		/*do 
		{
			hand.clear();
			
			deck.shuffle();
			
			while (hand.size() < 5)
			{
				hand.addCard(deck.draw());
			}
			std::cout << hand.toString() << std::endl;
			
		} while (hand.isPair()== false);*/



		


		system("pause");
}