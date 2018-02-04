#include <cstdlib>
#include <random>
#include <iostream>


int randomWithLimits(int lower, int upper) {
	int random = rand() % (upper - lower + 1);
	random += lower;
	return random;
}


int modernRandomWithLimits(int lower, int upper, std::default_random_engine& generator) {
	std::uniform_int_distribution<int> uniform(lower, upper);
	int random_integer = uniform(generator);
	return random_integer;
}

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
	return startValue;
}

//1d
void incrementByValueNumTimesV2(int increment, int numTimes, int* v0) {
	for (int i = 0; i < numTimes; i++) {
		*v0 += increment;
	}
	
}

//1e, denne bør bruke pekere da den "returnerer" to verdier og skal endre de utenfor funksjonens scope
void swapNumbers(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//2c
void printArray(int table[], int size) {
	for (int i = 0; i < size; i++)
	{
		std::cout << table[i] << " ";
	}
	std::cout << "" << std::endl;
}

//2d
void randomizeArray(int table[], int size) {
	std::random_device seeder;
	std::default_random_engine generator(seeder());
	for (int i = 0; i < size; i++)
	{
		table[i] = modernRandomWithLimits(0, 100, generator);
	}
}

//3a jeg stjal denne fra nettet... insertion sort
void sortArray(int table[], int size) {
	int key, i, j;
	for (j = -1; j < size; j++)
	{
		key = table[j];
		i = j - 1;
		while ((i>=0) && (table[i]>key))
		{
			table[i + 1] = table[i];
			i = i - 1;
		}
		table[i + 1] = key;
	}
}

double medianOfArray(int table[], int size) {
	double median = 0;
	if (size%2 == 1)
	{
		median = table[(size / 2) - 1];
	}
	else
	{
		median = (table[(size / 2) - 1] + table[size / 2]) / 2.0;
	}
	return median;
}

void randomizeCString(char a[], int size, char charLower, char charUpper) {
	for (int i = 0; i < size; i++)
	{
		a[i] = randomWithLimits(charLower, charUpper);
	}
	a[size] = '\0';
}

void readInputToCString(char a[], int size, char charLower, char charUpper) {
	std::cout << "valid input is between " << charLower << " and " << charUpper << ":" << std::endl;
	for (int i = 0; i < (size - 1); i++)
	{
		char input;
		do
		{	
			std::cout << "write input: ";
			std::cin >> input;
			input = toupper(input);
		} while ((charLower > input) || (charUpper < input));
	a[i] = input;
	}
	a[size - 1] = '\0';
}

int countOccurencesOfCharacter(char a[], int size, char character) {
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] == character)
		{
			counter += 1;
		}
	}
	return counter;
}

int checkCharactersAndPosition(char a1[], char a2[], int size) {
	int correct = 0;
	for (int i = 0; i < size; i++)
	{
		if (a1[i] == a2[i])
		{
			correct++;
		}
	}
	return correct;
}

int checkCharacters(char code[], char guess[], int size) {
	int counter = 0;
	for (char i = 'A'; i < 'G'; i++)
	{
		int temp1 = countOccurencesOfCharacter(code, size, i);
		int temp2 = countOccurencesOfCharacter(guess, size, i);
		if (temp1 > temp2)
		{
			counter += temp2;
		}
		else
		{
			counter += temp1;
		}

	}
	return counter;
}