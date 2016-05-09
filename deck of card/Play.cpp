#include "Play.h"

Deck deck;
Hand hand;

Play::Play()
{
}


Play::~Play()
{
}

void Play::playgame()
{
	char userInput;
	do {

		gamesMenu();
		userInput = getUserInput();

		switch (userInput)
		{
		case 'P':
			dealHand();
			break;
		case 'S':
			payTable();
		case 'W':
			welcomeMessage();
		default:
			break;
		}
	} while (userInput != 'Q');
	

}

void Play::gamesMenu() const
{
	system("cls");
	std::cout <<
		"   *****************Jack or Better Poker**************\n" <<
		"   ***  (P) - Play                                 ***\n" <<
		"   ***  (S) - Show pay table                       ***\n" <<
		"   ***  (W) - Welcome and instruction              ***\n" <<
		"   ***                                             ***\n" <<
		"   ***  (Q) - Quit program                         ***\n" <<
		"   ***************************************************\n\n" <<
		"   ";
}

void Play::payTable() const
{
	std::cout <<
		"\n" <<
		"************** Pay Table **************\n" <<
		"*                                     *\n" <<
		"*        Royal Flush:      250        *\n" <<
		"*        Strait Flush:     50         *\n" <<
		"*        Four of a Kind:   25         *\n" <<
		"*        Full House:       9          *\n" <<
		"*        Flush:            6          *\n" <<
		"*        Straight:         4          *\n" <<
		"*        Three of a Kind:  3          *\n" <<
		"*        Two Pair:         2          *\n" <<
		"*        Jack or Better:   1          *\n" <<
		"*                                     *\n" <<
		"***************************************\n" << std::endl;
	system("pause");
}

void Play::welcomeMessage() const
{
	std::cout << "        Hi and welcome to Jack or Better poker.\n" <<
		"\nThe player is given 5 cards and has the opportunity to discard one or more" <<
		"\nof them in exchange for new ones drawn from the same virtual deck. After the" <<
		"\ndraw, the machine pays out if the hand or hands played match one of the " <<
		"winning combinations, which are posted in the pay table.\n"<<std::endl;

	system("pause");
}

void Play::dealHand() 
{	
	system("cls");
	
	hand.clear();
	deck.shuffle();

	while (hand.size() < 5)
	{
		hand.addCard(deck.draw());		
	}

	std::cout << hand.toString() << std::endl;
	findValueOftheHand();
	

	system("pause");

}

void Play::findValueOftheHand() const
{
	int pay = 0;

	if (hand.isRoyalFlush() == true)
	{
		pay = 250;
		std::cout << "Royal Flush You win " << pay << " time you bet." << std::endl;
	}		
	else if (hand.isStraitFlush() == true)
	{
		pay = 50;
		std::cout << "Strait Flush You win " << pay << " time you bet." << std::endl;
	}
	else if (hand.isFourOfaKind() == true)
	{
		pay = 25;
		std::cout << "Four of a Kind You win " << pay << " time you bet." << std::endl;
	}
	else if (hand.isFullHouse() == true)
	{
		pay = 9;
		std::cout << "Full house You win " << pay << " time you bet." << std::endl;
	}
	else if (hand.isFlush() == true)
	{
		pay = 6;
		std::cout << "Flush You win " << pay << " time you bet." << std::endl;
	}
	else if (hand.isStrait() == true)
	{
		pay = 4;
		std::cout << "Strait You win " << pay << " time you bet." << std::endl;
	}
	else if (hand.isThreeOfakind() == true)
	{
		pay = 3;
		std::cout << "Three of a Kind You win " << pay << " time you bet." << std::endl;
	}
	else if (hand.isTwoPair() == true)
	{
		pay = 2;
		std::cout << "Two Pair You win " << pay << " time you bet." << std::endl;
	}
	else if (hand.isPair() == true)
	{
		pay = 1;
		std::cout << "One Pair You win " << pay << " time you bet." << std::endl;
	}

	else
		std::cout << "You Lose " << pay << " time you bet." << std::endl;
}

char Play::getUserInput() const
{
	char userInput;
	std::cin >> userInput;
	userInput = toupper(userInput);

	while (std::cin.fail())
	{

		std::cin.clear();
		std::cout << "Please enter a valid choise\n";
		std::cin >> userInput;
		system("pause");
		std::cin.ignore();
	}


	return userInput;
}
