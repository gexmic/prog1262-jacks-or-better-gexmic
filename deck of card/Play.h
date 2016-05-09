#pragma once
#include <iostream>
#include "Hand.h"


class Play
{
public:
	Play();
	~Play();

	void playgame();
	void gamesMenu() const;
	void payTable() const;
	void welcomeMessage() const;
	void dealHand() ;
	void findValueOftheHand() const;
	char getUserInput()const;

};

