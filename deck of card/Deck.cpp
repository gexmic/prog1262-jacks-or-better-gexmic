#include "Deck.h"
#include <time.h>



Deck::Deck()
{
	for (auto f : Card::faces)
		for (auto s : Card::suits)
			_deck.push_back(std::make_shared<Card>(Card(f,s)));
	_topOfDeck = _deck.size() - 1;

	// for test.
	
	//_deck.push_back(std::make_shared<Card>(Face::ACE, Suit::DIAMOND));
	//_deck.push_back(std::make_shared<Card>(Face::TEN, Suit::DIAMOND));
	//_deck.push_back(std::make_shared<Card>(Face::JACK, Suit::DIAMOND));
	//_deck.push_back(std::make_shared<Card>(Face::QUEEN, Suit::DIAMOND));
	//_deck.push_back(std::make_shared<Card>(Face::KING, Suit::DIAMOND));

	srand(unsigned(time(0)));
}

Deck::~Deck()
{
}

bool Deck::isEmpty() const
{
	return (_topOfDeck < 0);
}

void Deck::shuffle()
{
	for (int i = 0; i < _deck.size(); ++i)
	{
		swap(_deck[i], _deck[rand() % _deck.size()]);
	}
	_topOfDeck = _deck.size() - 1;
}


CardPtr Deck::draw()
{
	return _deck.at(_topOfDeck--);
}


