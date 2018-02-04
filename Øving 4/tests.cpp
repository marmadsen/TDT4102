#include "utilities.h"
#include <iostream>
#include <math.h>

void testCallByValue() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	std::cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " result: " << result << std::endl;
}

void testCallByPointer() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	incrementByValueNumTimesV2(increment, iterations, &v0);
	std::cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " v0: " << v0 << std::endl;
}

void testSwapNumbers() {
	int a = 5;
	int b = 8;
	std::cout << "a: " << a << " b: " << b << std::endl;
	swapNumbers(&a, &b);
	std::cout << "a: " << a << " b: " << b << std::endl;
}

//2a
void testTableSorting() {
	int percentages[20] = {}; //2b
	randomizeArray(percentages, 20); //2d
	printArray(percentages, 20);
	double median2 = medianOfArray(percentages, 20); //selvfølgelig blir dette dust...
	std::cout << "unsorted median: " << median2 << std::endl;
	swapNumbers(&percentages[0], &percentages[1]); //2e
	printArray(percentages, 20);
	sortArray(percentages, 20);
	printArray(percentages, 20);
	double median = medianOfArray(percentages, 20);
	std::cout << "median: " << median << std::endl;
}

//4a
void testCstring() {
	std::cout << "Dette programmet regner ut snittet ditt." << std::endl;
	int gradesCount[6] = {};
	for (int i = 1; i < 6; i++)
	{	
		std::cout << "Skriv inn karakterene for ditt " << i << ". aar:" << std::endl;
		char grades[9] = "";
		readInputToCString(grades, 9, 'A', 'F');
		std::cout << grades << std::endl;
		for (int i = 0; i < 6; i++)
		{
			gradesCount[i] += countOccurencesOfCharacter(grades, 9, (char) 'A' + i);
		}

	}
	printArray(gradesCount, 6);
	int sum = 0;
	for (int i = 1; i < 7; i++)
	{
		sum += (i * gradesCount[i - 1]);
	}
	double average = sum / (5.0*8.0);
	std::cout << "Din gjennomsnittskarakter er: ";
	std::cout << (char)('A' + round(average) - 1) << std::endl;
	
	/*
	int size = 9;
	char grades[9] = "";
	randomizeCString(grades, size, 'A', 'F'); //4d
	std::cout << grades << std::endl; //4e
	int gradesCount[6] = {};
	for (int i = 0; i < size - 1; i++)
	{
		switch (grades[i])
		{
		case 'A':
			gradesCount[0]++;
			break;
		case 'B':
			gradesCount[1]++;
			break;
		case 'C':
			gradesCount[2]++;
			break;
		case 'D':
			gradesCount[3]++;
			break;
		case 'E':
			gradesCount[4]++;
			break;
		case 'F':
			gradesCount[5]++;
			break;
		default:
			break;
		}
	}
	printArray(gradesCount, 6);		//4h
	*/


	//int count = countOccurencesOfCharacter(grades, 9, 'B');   //test av 4g
	//std::cout << "count: " << count << std::endl;
	/*
	char grades[9] = ""; // test av 4f
	readInputToCString(grades, 9, 'A', 'F');
	std::cout << grades << std::endl;
	*/
}