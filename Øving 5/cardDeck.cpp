#include <iostream>
#include <string>
#include <sstream>

#include "cardDeck.h"
#include "utilities.h"


std::string suitToString(Suit s) {
	switch (s)
	{
	case CLUBS:
		return "Clubs";
	case DIAMONDS:
		return "Diamonds";
	case HEARTS:
		return "Hearts";
	case SPADES:
		return "Spades";
	}
}

std::string rankToString(Rank r) {
	switch (r)
	{
	case TWO:
		return "Two";
	case THREE:
		return "Three";
	case FOUR:
		return "Four";
	case FIVE:
		return "Five";
	case SIX:
		return "Six";
	case SEVEN:
		return "Seven";
	case EIGHT:
		return "Eight";
	case NINE:
		return "Nine";
	case TEN:
		return "Ten";
	case JACK:
		return "Jack";
	case QUEEN:
		return "Queen";
	case KING:
		return "King";
	case ACE:
		return "Ace";
	}
}

std::string intToString(int number) {
	std::stringstream ss;
	ss << number;
	return ss.str();
}


std::string toString(CardStruct card) {
	std::string suit = suitToString(card.s);
	std::string rank = rankToString(card.r);
	std::string returnString = rank + " of " + suit;
	return returnString;
}

std::string toStringShort(CardStruct card) {
	std::string suit = suitToString(card.s);
	std::string shortSuit = suit.substr(0, 1);
	std::string shortRank = intToString(card.r);
	return (shortSuit + shortRank);
}




//3b
void Card::initialize(Suit s, Rank r)
{
	this->s = s;
	this->r = r;
	invalid = false;
}

//3c
Suit Card::getSuit()
{
	return s;
}

//3d
Rank Card::getRank()
{
	return r;
}

//3e
std::string Card::toString()
{	
	CardStruct temp = { s, r };
	if (invalid)
	{
		return "Invalid card";
	}
	else
	{
		return ::toString(temp);
	}
}

//3f
std::string Card::toStringShort()
{
	CardStruct temp = { s, r };
	if (invalid)
	{
		return "Invalid card";
	}
	else
	{
		return ::toStringShort(temp);
	}
}

//3g
Card::Card()
{
	invalid = 1;
}

//3h
Card::Card(Suit s, Rank r)
{
	Card::initialize(s, r);
}




//4b
CardDeck::CardDeck()
{
	currentCardIndex = 0;
	for (int suit = CLUBS; suit<=SPADES; suit++) {
		for (int rank = TWO; rank<=ACE; rank++) {
			cards[currentCardIndex++] = Card(static_cast<Suit>(suit), static_cast<Rank>(rank));
			
		}
	}
	currentCardIndex = 0;
}

//4c
void CardDeck::swap(Card &cardA, Card &cardB)
{
	Card temp = cardA;
	cardA = cardB;
	cardB = temp;
}

//4d
void CardDeck::print()
{
	for (int i = 0; i < 52; i++)
	{
		std::cout << cards[i].Card::toString() << std::endl;
	}
}

//4e
void CardDeck::printShort()
{
	for (int i = 0; i < 52; i++)
	{
		std::cout << cards[i].Card::toStringShort() << std::endl;
	}
}

//4f
void CardDeck::shuffle()
{
	std::random_device seeder;
	std::default_random_engine generator(seeder());
	for (int i = 0; i < 100; i++)
	{
		int randA = modernRandomWithLimits(0, 51, generator);
		int randB = modernRandomWithLimits(0, 51, generator);
		if (randA != randB)
		{
			swap(cards[randA], cards[randB]);
		}
	}
}

//4g
Card CardDeck::drawCard()
{
	//currentCardIndex++;
	return cards[currentCardIndex++];
}