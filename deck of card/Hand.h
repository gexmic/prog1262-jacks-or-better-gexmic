#pragma once
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "Deck.h"
#include <algorithm>
#include <sstream>

using CardPtr = std::shared_ptr<Card>;

class Hand
{
public:
	Hand();
	~Hand();

	void addCard(CardPtr);
	void clear();
	int size();
	bool isPair() const;
	bool isThreeOfakind()const;
	bool isFourOfaKind()const;
	bool isFullHouse()const;
	bool isTwoPair()const;
	bool isFlush()const;
	bool isStrait()const;
	bool isStraitFlush() const;
	bool isRoyalFlush() const;
	std::string toString() const;

private:
	std::vector<CardPtr> _hand;
	std::map<Face, int> _checkFace;
	std::map<Suit, int> _checkSuit;
	std::set<Face> _checkForStrait;
};

