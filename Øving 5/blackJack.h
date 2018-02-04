#pragma once
#include "cardDeck.h"

class BlackJack
{
private:
	CardDeck deck;	//the deck of all 52 cards
	int playerHand;	//total value of their hand
	int dealerHand;
	int playerCardsDrawn;
	int dealerCardsDrawn;
public:
	bool isAce(Card &card);
	int getCardValue(Card &card);
	int getPlayerCardValue(Card &card);
	int getDealerCardValue(Card &card, int valueOfDealerHand);
	bool askPlayerDrawCard();
	void drawInitialCards();
	bool playGame();


};