#pragma once
#include <string>

//using namespace std;


//en enum type for suits 1a)
enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

//en enum type for rank 1b)
enum Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

struct CardStruct {
	Suit s;
	Rank r;
};

//supporting function to convert from int to string
std::string intToString(int number);

//1c tar inn en variabel av typen suit og lagrer den som en streng
std::string suitToString(Suit s);

//1d tar inn en variabel av typen rank og lagrer den som en streng
std::string rankToString(Rank r);


//returns the string consisting of the suit and rank of a card "Ace of Spades".
std::string toString(CardStruct card);

//same as toString just in short form
std::string toStringShort(CardStruct card);

//classes

// a class that creates a card consisting of a suit and a rank
class Card
{
private:
	Suit s;
	Rank r;
	bool invalid;
public:
	void initialize(Suit s, Rank r);
	Suit getSuit();
	Rank getRank();
	std::string toString();
	std::string toStringShort();
	Card();
	Card(Suit s, Rank r);

};

//a class that creates a full deck of cards consisting of 52 cards
class CardDeck
{
private:
	Card cards[52];
	int currentCardIndex;
	void swap(Card &cardA, Card &cardB);
public:
	CardDeck();
	void print();
	void printShort();
	void shuffle();
	Card drawCard();
};