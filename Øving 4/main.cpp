// 1a) v0 vil fremdeles være lik 5
#include <iostream>
#include "tests.h"
#include "playMastermind.h"

void main() {
	int choice = 1;
	do
	{
		std::cout << "0) Avslutt programmet." << std::endl;
		std::cout << "1) test av call-by-value." << std::endl;
		std::cout << "2) test av call-by-pointer." << std::endl;
		std::cout << "3) test av swapNumbers." << std::endl;
		std::cout << "4) test tableSorting." << std::endl;
		std::cout << "5) test av c strenger." << std::endl;
		std::cout << "6) spill Mastermind!" << std::endl;
		std::cout << "Angi valg: ";
		std::cin >> choice;

		switch (choice)
		{
			case 0:
				std::cout << "Bye bye!" << std::endl;
				break;
			case 1:
				testCallByValue();
				break;
			case 2:
				testCallByPointer();
				break;
			case 3:
				testSwapNumbers();
				break;
			case 4:
				testTableSorting();
				break;
			case 5:
				testCstring();
				break;
			case 6:
				playMastermind();
				break;
			default:
				std::cout << "Ikke gyldig valg" << std::endl;
				break;
		}
	} while (choice != 0);

}