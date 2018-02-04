#include "Matrix2x2.h"
#include "Vector2.h"

#include <iostream>

void main() {
	std::cout << "This program solves simultaneous equations.\n It does so by using matrices." << std::endl;
	std::cout << "----------\n" << "Matrix:\n" << "|a\tb| |x| = |p|\n|c\td| |y| = |q|\n" << std::endl;
	double a, b, c, d, p, q;
	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;
	std::cout << "Enter c: ";
	std::cin >> c;
	std::cout << "Enter d: ";
	std::cin >> d;
	std::cout << "Enter p: ";
	std::cin >> p;
	std::cout << "Enter q: ";
	std::cin >> q;

	Matrix2x2 matrix(a, b, c, d);
	Vector2 vector(p, q);
	double det = matrix.det();
	std::cout << det << std::endl;
	if (det == 0)
	{
		std::cout << "Determinant of matrix is zero, system unsolvable." << std::endl;
	}
	else
	{
		Vector2 result = matrix.inverse() * vector;
		std::cout << "Solution:\n" << result << std::endl;
	}




	/*
	//1c: test av 1b
	Matrix2x2 a(1,2,3,4),b(4,3,2,1),c(1.0,3.0,1.5,2.0),e;
	Vector2 x(4, 2);

	Vector2 result = a * x;
	std::cout << result << std::endl;
	*/
	//Matrix2x2 g = a.inverse();
	//std::cout << g << std::endl;
	/*
	//2c(g)
	Matrix2x2 d = a * b;
	a *= b;
	std::cout << e << std::endl;
	
	std::cout << "d:\n" << d << std::endl;

	//2e
	d *= b;
	d -= (a + c);
	//d = (d*b) - (a + c);
	std::cout << "d:\n" << d << std::endl;
	*/

	/*
	test of vector functions
	std::cout << "\n --------------- \n" << std::endl;
	Vector2 test(3, 6), test2(2,3);
	double dot = test.dot(test2);
	std::cout << test << std::endl;
	std::cout << "\n --------------- \n" << std::endl;
	std::cout << dot << std::endl;
	std::cout << "\n --------------- \n" << std::endl;
	double length = test.length();
	std::cout << length << std::endl;
	*/


}