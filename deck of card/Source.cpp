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
/////////////////////////////////////////////////////////////////////#include <iostream>

#include "Play.h"

using std::cout;
using std::cin;

int main()
{
	Play pokerGame;

	pokerGame.playgame();

	system("pause");
}