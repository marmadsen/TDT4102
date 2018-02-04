#pragma once

//#include <cstdlib> //disse to er super viktig!
#include <random> //... og jeg aner ikke hvorfor

//random numbers in the interval between and including lower and upper
int randomWithLimits(int lower, int upper);


//more modern randomizer
//random numbers in the interval between and including lower and upper
int modernRandomWithLimits(int min, int max, std::default_random_engine& generator);

//increments startValue by increment numTimes
int incrementByValueNumTimes(int startValue, int increment, int numTimes);

//same as above but using call-by-pointers
void incrementByValueNumTimesV2(int increment, int numTimes, int* v0);

//swaps two integers using call-by-pointers
void swapNumbers(int *a, int *b);

//prints all members of an array
void printArray(int table[], int size);

// populates an array with integers between 0 and 100
void randomizeArray(int table[], int size);

// sorts an array from smallest to largest
void sortArray(int table[], int size);

//returns the median of an array of sorted integers
double medianOfArray(int table[], int size);

//populates a C string with random characters
void randomizeCString(char a[], int size, char charLower, char CharUpper);

//let's the user input text to a char array within a limit
//remember that the end of a char array, '\0', takes up the last spot in the array
void readInputToCString(char a[], int size, char charLower, char charUpper);

//returns how many times a character appear in a C string
int countOccurencesOfCharacter(char a[], int size, char character);

//checks if 2 char arrays has the same element in the same spot.
int checkCharactersAndPosition(char a1[], char a2[], int size);

//checks if 2 char arrays how many characters they have in common
int checkCharacters(char code[], char guess[], int size);