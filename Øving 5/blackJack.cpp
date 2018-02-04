#include "blackJack.h"
#include<iostream>

//5b
bool BlackJack::isAce(Card &card)
{
	if (card.getRank() == ACE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//5c
int BlackJack::getCardValue(Card &card)
{
	switch (card.getRank())
	{
	case TWO:
		return 2;
	case THREE:
		return 3;
	case FOUR:
		return 4;
	case FIVE:
		return 5;
	case SIX:
		return 6;
	case SEVEN:
		return 7;
	case EIGHT:
		return 8;
	case NINE:
		return 9;
	case TEN:
		return 10;
	case JACK:
		return 10;
	case QUEEN:
		return 10;
	case KING:
		return 10;
	case ACE:
		return -1;
	}
}

//5d
int BlackJack::getPlayerCardValue(Card &card)
{
	int temp = getCardValue(card);
	if (temp == -1)
	{
		int choice = 0;
		do {
			std::cout << "Do you want your ace to be 1 or 11? ";
			std::cin >> choice;
			switch (choice)
			{
			case 1:
				return 1;
			case 11:
				return 11;
			default:
				break;
			}

		} while (choice != 1 || choice != 11);
	}
	else
	{
		return temp;
	}
}

//5e
int BlackJack::getDealerCardValue(Card &card, int valueOfDealerHand)
{
	int temp = getCardValue(card);
	if (temp == -1)
	{
		if ((valueOfDealerHand + 11) > 21)
		{
			return 1;
		}
		else
		{
			return 11;
		}
	}
	else
	{
		return temp;
	}
}

//5f
bool BlackJack::askPlayerDrawCard()
{
	char choice = 'a';
	std::cout << "Would you like another card? [y/n]" << std::endl;
	do
	{
		std::cin >> choice;
		choice = toupper(choice);
		switch (choice)
		{
		case 'Y':
			return true;
		case 'N':
			return false;
		default:
			std::cout << "Invalid choice, try again." << std::endl;
			break;
		}
	} while (choice != 'Y' || choice != 'N' );
}

//5g
void BlackJack::drawInitialCards()
{
	playerCardsDrawn = 0;
	Card card1Player = deck.drawCard();
	playerCardsDrawn++;
	std::cout << "Player's first card: " << card1Player.toString() << std::endl;
	playerHand = getPlayerCardValue(card1Player);
	
	dealerCardsDrawn = 0;
	Card card1Dealer = deck.drawCard();
	dealerHand = getDealerCardValue(card1Dealer, 0);
	std::cout << "Dealer's first card: " << card1Dealer.toString() << std::endl;
	dealerCardsDrawn++;

	Card card2Player = deck.drawCard();
	playerCardsDrawn++;
	std::cout << "Player's second card: " << card2Player.toString() << std::endl;
	playerHand += getPlayerCardValue(card2Player);

	Card card2Dealer = deck.drawCard();
	dealerHand += getDealerCardValue(card1Dealer, dealerHand);
	//std::cout << "Dealer's second card: " << card2Dealer.toString() << std::endl;
	dealerCardsDrawn++;

	std::cout << "Player's hand is " << playerHand << std::endl;

}

//5h
bool BlackJack::playGame()
{
	deck = CardDeck::CardDeck();
	deck.shuffle();
	drawInitialCards();
	bool newCard = askPlayerDrawCard();
	do
	{	

		
		if (newCard)
		{
			Card card = deck.drawCard();
			std::cout << "Player drew: " << card.toString() << std::endl;
			playerCardsDrawn++;
			playerHand += getPlayerCardValue(card);
			std::cout << "Player's hand is " << playerHand << std::endl;
			newCard = askPlayerDrawCard();
		}
		


	} while (newCard == true);

	while (dealerHand < 17)
	{
			Card cardDealer = deck.drawCard();
			//std::cout << "Dealer drew: " << cardDealer.toString() << std::endl;
			dealerHand += getDealerCardValue(cardDealer, dealerHand);
			//std::cout << "Dealer's hand is " << dealerHand << std::endl;
			dealerCardsDrawn++;
	}
	
	
	if (playerHand == 21 && playerCardsDrawn == 2)
	{
		std::cout << "Player's hand was " << playerHand << " in " << playerCardsDrawn << " cards drawn." << std::endl;
		std::cout << "Dealer's hand was " << dealerHand << " in " << dealerCardsDrawn << " cards drawn." << std::endl;
		return true;
		
	}
	else if (dealerHand > 21)
	{
		std::cout << "Player's hand was " << playerHand << " in " << playerCardsDrawn << " cards drawn." << std::endl;
		std::cout << "Dealer's hand was " << dealerHand << " in " << dealerCardsDrawn << " cards drawn." << std::endl;
		return true;
	}
	else if (playerHand > 21)
	{
		std::cout << "Player's hand was " << playerHand << " in " << playerCardsDrawn << " cards drawn." << std::endl;
		std::cout << "Dealer's hand was " << dealerHand << " in " << dealerCardsDrawn << " cards drawn." << std::endl;
		return false;
	}
	else if (playerHand > dealerHand)
	{
		std::cout << "Player's hand was " << playerHand << " in " << playerCardsDrawn << " cards drawn." << std::endl;
		std::cout << "Dealer's hand was " << dealerHand << " in " << dealerCardsDrawn << " cards drawn." << std::endl;
		return true;
	}
	else if ((playerHand == dealerHand) && (playerCardsDrawn < dealerCardsDrawn))
	{
		std::cout << "Player's hand was " << playerHand << " in " << playerCardsDrawn << " cards drawn." << std::endl;
		std::cout << "Dealer's hand was " << dealerHand << " in " << dealerCardsDrawn << " cards drawn." << std::endl;
		return true;
	}
	else
	{
		//std::cout << "whoops, this shouldn't happen..." << std::endl;
		std::cout << "Player's hand was " << playerHand << " in " << playerCardsDrawn << " cards drawn." << std::endl;
		std::cout << "Dealer's hand was " << dealerHand << " in " << dealerCardsDrawn << " cards drawn." << std::endl;
		return false;
	}
}