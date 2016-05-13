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
/////////////////////////////////////////////////////////////////////#include "Util.h"


#include "Util.h"


Util::Util()
{
}


Util::~Util()
{
}


// game menu
void Util::gamesMenu() const
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

void Util::payTable() const
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

void Util::welcomeMessage() const
{
	std::cout << "        Hi and welcome to Jack or Better poker.\n" <<
		"\nThe player is given 5 cards and has the opportunity to discard one or more" <<
		"\nof them in exchange for new ones drawn from the same virtual deck. After the" <<
		"\ndraw, the machine pays out if the hand or hands played match one of the " <<
		"winning combinations, which are posted in the pay table.\n" << std::endl;

	system("pause");
}