
#include "blackJack.h"
#include <iostream>
#include <string>



void main() {

	std::cout << "Let's play Blackjack!" << std::endl;
	bool play = 1;
	char playAgain = 'a';
	do
	{
		BlackJack test;// = BlackJack::BlackJack();
		bool winning = test.playGame();
		if (winning == true)
		{
			std::cout << "Congratulations, you won!" << std::endl;
		}
		else
		{
			std::cout << "Sorry, you lost." << std::endl;
		}
		std::cout << '\n' << "Do you want to play again? [Y/N]";
		std::cin >> playAgain;
			switch (toupper(playAgain))
			{
			case 'Y':
				play = true;
				break;
			case 'N':
				play = false;
				std::cout << "Bye bye!" << std::endl;
			default:
				break;
			}
	} while (play);




	/*
	TEST OF FUNCTIONS

	CardStruct test = { DIAMONDS, ACE };
	std::string test1 = suitToString(test.s);
	std::string test2 = rankToString(test.r);
	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
	
	std::string test3 = toString(test);
	std::cout << test3 << std::endl;
	
	std::string test4 = toStringShort(test);
	std::cout << test4 << std::endl;
	

	CardDeck test = CardDeck::CardDeck();
	//test.print();
	test.shuffle();
	test.print();
	std::cout << "--------------" << std::endl;
	Card test2 = test.drawCard();
	std::cout << test2.toString() << std::endl;
	*/
}