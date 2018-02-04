#include <iostream>
#include <math.h>


//1a
void inputAndPrintInteger() {
	int input = 0;
	std::cout << "Skriv inn ett tall: ";
	std::cin >> input;
	std::cout << "Du skrev: " << input << std::endl;
}

//1b
int inputInteger() {
	int input = 0;
	std::cout << "Skriv inn ett tall: ";
	std::cin >> input;
	return input;
}

//1c
void inputIntegersAndPrintSum() {
	int tallA = inputInteger();
	int tallB = inputInteger();
	std::cout << "Summen av tallene: " << tallA + tallB << std::endl;
}

//1d
//jeg brukte inputInteger fordi den returnerer en verdi som jeg assigner til tallA/tallB

//1e
bool isOdd(int number) {
	if (number%2 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//1f
void printHumanReadableTime(int seconds) {
	int hours = seconds / 3600;
	seconds -= hours * 3600;
	int minutes = seconds / 60;
	seconds -= minutes * 60;
	std::cout << hours << " hour(s), " << minutes << " minute(s), and " << seconds << " second(s)" <<  std::endl;
}

//2a
void inputIntegersUsingLoopAndPrintSum() {
	int sum = 0;
	int sizeOfSum = 0;
	std::cout << "Hvor mange tall vil du summere? ";
	std::cin >> sizeOfSum;
	for (int i = 0; i < sizeOfSum; i++)
	{
		sum += inputInteger();
	}
	std::cout << "Summen av de " << sizeOfSum << " tallene er: " << sum << std::endl;
}

//2b
/*en for-løkke er best egnet hvis man vet lengden av summen, mens en do-while er bedre hvis den ikke er kjent
*/

//2c
double inputDouble() {
	double input = 0.0;
	std::cout << "Skriv inn et flyttall: ";
	std::cin >> input;
	return input;
}

//2d
void currencyConverter() {
	std::cout << "Denne funksjonen konverterer fra NOK til EUR, skriv inn antall NOK:" << std::endl;
	double NOK = inputDouble();
	while (NOK <= 0.0) {
		std::cout << "NOK maa vaere positiv, proev igjen." << std::endl;
		NOK = inputDouble();
	} 
	double EUR = NOK / static_cast<double>(9.64); // iomanip cout << fixed << setprsicion(2)
	std::cout << NOK << "NOK = " << EUR << "EUR" << std::endl;
}
//2e oppgaveteksten sier bruker skal skrive et desimaltall, det funker ikke med inputInteger.

//3b
void multiplicationTable() {
	int height = 0;
	int width = 0;
	std::cout << "Denne funksjonen printer en gangetabell" << std::endl;
	std::cout << "Angi hoeyde paa gangetabellen: ";
	std::cin >> height;
	std::cout << "Angi bredde paa gangetabellen: ";
	std::cin >> width;
	for (int i = 1; i < height + 1; i++)
	{
		for (int j = 1; j < width + 1; j++) {
			std::cout << i * j << "\t";
		}
		std::cout << std::endl;
	}

}

//4a
double discriminant(double a, double b, double c) {
	double delta = (b * b) - (4 * a * c);
	return delta;
}

//4b
void printRealRoots(double a, double b, double c) {
	double delta = discriminant(a, b, c);
	if (delta > 0)
	{
		double x1 = (-b + sqrt(delta)) / static_cast<double>(2 * a);
		double x2 = (-b - sqrt(delta)) / static_cast<double>(2 * a);
		std::cout << "polynomet har 2 reele roetter: " << x1 << " og " << x2 << std::endl;

	}
	else if (delta == 0)
	{
		double x = (-b) / static_cast<double>(2 * a);
		std::cout << "polynomet har 1 reel rot: " << x << std::endl;
	}
	else
	{
		std::cout << "Ingen reele loesninger." << std::endl;
	}
}

//4c
void solveQuadraticEquation() {
	double a = inputDouble();
	double b = inputDouble();
	double c = inputDouble();
	printRealRoots(a, b, c);
}
//4d de funker

void calculateLoanPayments() {
	int years = 10;
	std::cout << "Skriv laanebeloep: ";
	double loanAmount = inputDouble();
	std::cout << "Skriv rente: ";
	double interest = inputDouble();
	double remaningLoan = loanAmount;
	std::cout << "Aar\tInnbetaling\tGjenstaaende Laan" << std::endl;
	for (int i = 1; i <= years; i++)
	{	
		double payment = (loanAmount / static_cast<double>(years)) + (interest / static_cast<double>(100))*remaningLoan;
		remaningLoan = remaningLoan - payment + (interest / static_cast<double>(100))*remaningLoan;
		std::cout << i << "\t" << payment << "\t\t" << remaningLoan << std::endl;
	}

}

//3a
void main() {
	int choice = 1;
	do
	{	
		
		std::cout << "0) Avslutt" << std::endl;
		std::cout << "1) Summer to tall" << std::endl;
		std::cout << "2) Summer flere tall" << std::endl;
		std::cout << "3) Sjekk om et tall er odd" << std::endl;
		std::cout << "4) Konverter sekunder til timer" << std::endl;
		std::cout << "5) Konverter NOK til EURO" << std::endl;
		std::cout << "6) Gangetabell" << std::endl;
		std::cout << "7) Polynomsolver" << std::endl;
		std::cout << "8) Laanekalkulator" << std::endl;
		std::cout << "Angi valg: ";
		std::cin >> choice;

		switch (choice)
		{
			case 0:
				std::cout << "Bye bye" << std::endl;
				break;
			case 1:
				inputIntegersAndPrintSum();
				break;
			case 2:
				inputIntegersUsingLoopAndPrintSum();
				break;
			case 3:
				if (isOdd(inputInteger()))
				{
					std::cout << "Tallet er odd." << std::endl;
				}
				else
				{
					std::cout << "Tallet er et partall." << std::endl;
				}
				break;
			case 4:
				printHumanReadableTime(inputInteger());
				break;
			case 5:
				currencyConverter();
				break;
			case 6:
				multiplicationTable();
				break;
			case 7:
				solveQuadraticEquation();
				break;
			case 8:
				calculateLoanPayments();
				break;
			default:
				std::cout << "Ikke gyldig valg" << std::endl;
				break;
		}
	} while (choice != 0);

	//inputAndPrintInteger();
	
	//int number = inputInteger();
	//std::cout << "Du skrev: " << number;
	
	//inputIntegersAndPrintSum();
	
	/*for (int i = 10; i < 15; i++) {
		if (isOdd(i)) {
			std::cout << i << " er et oddetall." << std::endl;
		}
		else {
			std::cout << i << " er et partall." << std::endl;
		}
	}*/
	
	//printHumanReadableTime(3727);
	
	//inputIntegersUsingLoopAndPrintSum();

	//double number = inputDouble();
	//std::cout << "Du skrev: " << number;

	//currencyConverter();



}