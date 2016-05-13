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

#pragma once
#include <iostream>
#include "Hand.h"
#include "Util.h"

// class enum for the differente poker hand
enum class Rank{JACK_OR_BETTER, TWO_PAIR, THREE_OF_KIND, STRAIGHT, FLUSH, FULLHOUSE, FOUR_OF_KIND, STRAIGHT_FLUSH, ROYAL_FLUSH, NOTHING};

class Play
{
public:
	Play();
	~Play();

	void playgame();
	
	void dealHand() ;
	Rank findValueOftheHand() const;
	char getUserInput()const;
	void drawCard();

private:
	static const std::map<Rank,std::string> _handRank;
	static const std::map<Rank, int> _handPay;

};

