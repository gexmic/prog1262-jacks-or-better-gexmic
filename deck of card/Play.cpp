///////////////////////////////////////////////////////////////////////
// File:  Jack or Bette Games
//
// Author: Michael Landry
// This assignment represents my own work and is in accordance with the College Academic Policy
//
// Copyright (c) 2016 All Right Reserved by Michael Landry
// Contributors: 
// Description:  This is the game of poker Jack or Better, this programme simulate 5 card poker hand
// and the player is able to change any card for a redraw and have new card. the player win if I have a pair of jack or better
//
// Date: mai 13 2016
// Revisions:
//
/////////////////////////////////////////////////////////////////////

#include "Play.h"

Deck deck;
Hand hand;

Play::Play()
{
}


Play::~Play()
{
}

// fill up the map of the hand rank whit the Rank and a string to tell the user what he got
const std::map<Rank, std::string> Play::_handRank{
	{Rank::JACK_OR_BETTER, "You have one pair of jack or better"},
	{Rank::TWO_PAIR, "You have two pair"},
	{Rank::THREE_OF_KIND,"You have three of a kind"},
	{Rank::STRAIGHT,"You have Straight"},
	{Rank::FLUSH,"You have a Flush"},
	{Rank::FULLHOUSE,"You have a Full House"},
	{Rank::FOUR_OF_KIND,"You have a Four Of A Kind"},
	{Rank::STRAIGHT_FLUSH,"You have a Straight Flush"},
	{Rank::ROYAL_FLUSH,"You have a Royal Flush"},
	{Rank::NOTHING, "Nothing"}
};

// fill up the map whit the Rank and the value of how much time your bett pay depend from the Rank
const std::map<Rank, int> Play::_handPay{
	{Rank::NOTHING, 0},
	{Rank::JACK_OR_BETTER, 1 },
	{Rank::TWO_PAIR, 2 },
	{Rank::THREE_OF_KIND,3 },
	{Rank::STRAIGHT,4 },
	{Rank::FLUSH,6 },
	{Rank::FULLHOUSE,9 },
	{Rank::FOUR_OF_KIND, 25},
	{Rank::STRAIGHT_FLUSH,50 },
	{Rank::ROYAL_FLUSH,250 }
};


//swith statement to redirect the player to is choice
void Play::playgame()
{
	Util util;
	char userInput;
	do {

		util.gamesMenu();
		userInput = getUserInput();

		switch (userInput)
		{
		case 'P':
			dealHand();
			break;
		case 'S':
			util.payTable();
			break;
		case 'W':
			util.welcomeMessage();
			break;
		default:
			break;
		}
	} while (userInput != 'Q');


}



void Play::dealHand()
{
	// game loop
	system("cls");

	// clear the container to make sur noting is in it
	hand.clear();
	// shuffle the deck of card to have a new hand of card
	deck.shuffle();

	// put five card un the hand for poker whit five card
	while (hand.size() < 5)
	{
		hand.addCard(deck.draw());
	}

	// set the vector of bool to be true and have the same size that the player hand
	std::vector<bool> hold(hand.size(), true);
	// decide for the hold or draw
	hand.holdOrDraw(hold);
	// print the hand to the string
	std::cout << hand.toString() << std::endl;

	// player decide witch card he whant to draw
	drawCard();
	hand.DrawCardForSecoundHand();

	// add more card if the player discard some card
	while (hand.size() < 5)
	{
		hand.addCard(deck.draw());
	}
	// clear the screen and print the final hand
	system("cls");
	std::cout << hand.noHoldAndDrawToString() << std::endl;
	// find the value of the hand
	Rank rank = findValueOftheHand();
	// print the hand value 
	std::cout << _handRank.at(rank) << " it pays " << _handPay.at(rank) << " time your bet"<< std::endl;

	system("pause");

}

// it find the value of the current hand that the player have
Rank Play::findValueOftheHand() const
{

	if (hand.isRoyalFlush()) return Rank::ROYAL_FLUSH;
	else if (hand.isStraitFlush()) return Rank::STRAIGHT_FLUSH;
	else if (hand.isFourOfaKind()) return Rank::FOUR_OF_KIND;	
	else if (hand.isFullHouse())return Rank::FULLHOUSE;	
	else if (hand.isFlush())return Rank::FLUSH;	
	else if (hand.isStrait()) return Rank::STRAIGHT;	
	else if (hand.isThreeOfakind())return Rank::THREE_OF_KIND;	
	else if (hand.isTwoPair()) return Rank::TWO_PAIR;	
	else if (hand.isJackOrBetter())return Rank::JACK_OR_BETTER;
	else return Rank::NOTHING;
		
}

// get the user input in the menu
char Play::getUserInput() const
{
	char userInput;
	std::cin >> userInput;
	userInput = toupper(userInput);

	// make sure the user enter a valid choise
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

// print the phrase and get the user input for the card the player whant to draw or hold
void Play::drawCard()
{
	char userChoise = 'y';

	// going in the loop until the player enter p to play get the next card
	while (userChoise != 'p')
	{
		std::cout << "Choose the card you want to draw (1-5) and press (p) to play: ";
		std::cin >> userChoise;

		// check if the player enter a digit
		if (isdigit(userChoise))
		{
			userChoise = userChoise - 48;

			if (userChoise > 0 && userChoise <= 5)
			{
				hand.changCard(userChoise);
			}
			else
			{
				std::cout << "Please enter a number between 1 and 5\n";
				system("pause");
			}

		}
		system("cls");
		std::cout << hand.toString() << std::endl;
	}
}



