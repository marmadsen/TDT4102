#include <iostream>
//2a
int fibonacci(int n) {
	int a = 0;
	int b = 1;
	std::cout << "Fibonacci numbers:" << std::endl;
	for (int i = 0; i < n; i++) {
		int temp = b;
		b = a + b; //+=
		a = temp;
		std::cout << i << " " << b << std::endl;
	}
	std::cout << "----" << std::endl;
	return b;
}
//2b
int triangleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;
	std::cout << "Triangle numbers below " << n << ":" << std::endl;
	while (num+acc < n) {
		acc = acc + num;
		num += 1;
		std::cout << acc << std::endl;
	}
	std::cout << "" << std::endl;
	return 0;
}

bool isTriangleNumber(int number) {
	int acc = 1;
	while (number > 0) {
		number = number - acc;
		acc = acc + 1;
	}
	if (number == 0) {
		return true;
	}
	else {
		return false;
	}
}

//2c
int squareNumberSum(int n) {
	int totalSum = 0;
	for (int i = 0; i < n; i++) {
		totalSum += i*i;
		std::cout << i*i << std::endl;
	}
	std::cout << totalSum << std::endl;
	return totalSum;
}

//2d
double max(double a, double b) {
	if (a > b)
	{
		std::cout << "A is greater than B" << std::endl;
		return a;
	}
	else
	{
		std::cout << "B is greater than or equal to A" << std::endl;
		return b;
	}
}

//2e
bool isPrime(int n) {
	bool primeness = true;
	for (int j = 2; j < n; j++)
	{
		if (n%j == 0) {
			primeness = false;
			break;
		}
	}
	return primeness;
}

//2f
void naivePrimeNumberSearch(int n) {
	for (int number = 2; number < n; number++)
	{
		if (isPrime(number)) {
			std::cout << number << " is a prime" << std::endl;
		}
	}
}

//2g
int findGreatestDivisor(int n) {
	for (int divisor = n-1; divisor > 0; divisor--) {
		if (n%divisor == 0) {
			return divisor;
		}
	}
	return 1;
}

//2h
void compareListOfNumbers(int list[], int length) {
	int r[3] = { 0 };
	for (int i = 0; i < length; i++)
	{
		if (list[i] < 0) {
			r[0] += 1;
		}
		else if (list[i] == 0) {
			r[1] += 1;
		}
		else {
			r[2] += 1;
		}
	}
	std::cout << r[0] << " numbers were below zero" << std::endl;
	std::cout << r[1] << " numbers were zero" << std::endl;
	std::cout << r[2] << " numbers were greater than zero" << std::endl;
}

int main() {
	fibonacci(5);
	//triangleNumbersBelow(100);
	//std::cout << isTriangleNumber(9) << std::endl;
	//squareNumberSum(5);
	//max(2.67, 3.2);
	//std::cout << isPrime(9) << std::endl;
	//naivePrimeNumberSearch(10);
	//std::cout << findGreatestDivisor(156) << std::endl;
	//int list[] = { -2,3,0,0,-5 };
	//compareListOfNumbers(list,5);
	return 0;
}