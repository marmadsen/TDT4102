#include "utilities.h"
#include <iostream>




void playMastermind() {
	//constants
	const int SIZE = 4;
	const int LETTERS = 6;
	const int TRIES = 10;

	int triesLeft = 10;
	char code[SIZE + 1] = "";
	char guess[SIZE + 1] = "";
	randomizeCString(code, SIZE, 'A', 'A' + LETTERS - 1);
	std::cout << code << std::endl; //for debug
	int correctCharAndPos = 0;
	do
	{
		readInputToCString(guess, SIZE + 1, 'A', 'A' + LETTERS - 1);
		std::cout << "your guess is: " << guess << std::endl;
		correctCharAndPos = checkCharactersAndPosition(code, guess, SIZE);
		std::cout << "You have " << correctCharAndPos << " characters in the right place." << std::endl;
		int rightChar = checkCharacters(code, guess, SIZE);
		std::cout << "You have " << rightChar << " in common with the code." << std::endl;
		triesLeft--;
		if (correctCharAndPos == SIZE)
		{
			std::cout << "Congratulations! You won!" << std::endl;
		}
		else if (triesLeft == 0)
		{
			std::cout << "You're out of tries, you lost!" << std::endl;
		}
	} while (correctCharAndPos < SIZE && triesLeft > 0);
	std::cout << "\n";
}