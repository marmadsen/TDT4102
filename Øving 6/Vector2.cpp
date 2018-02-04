#include "Vector2.h"
#include <iostream>
#include <cmath>


double Vector2::get(int row) const {
	return vector[row];
}

void Vector2::set(int row, double value) {
	vector[row] = value;
}

Vector2::Vector2() {
	vector[0] = 0;
	vector[1] = 0;
}

Vector2::Vector2(double a, double b) {
	vector[0] = a;
	vector[1] = b;
}

void Vector2::printVector() {
	std::cout << vector[0] << "\n" << vector[1] << std::endl;
}

double Vector2::dot(const Vector2 & rightHandSide) const {
	double sum = 0;
	for (int i = 0; i < 2; i++)
	{
		sum += this->get(i) * rightHandSide.get(i);
	}
	return sum;
}

double Vector2::lengthSquared() const {
	return this->dot(*this);
}

double Vector2::length() const {
	return sqrt(this->lengthSquared());
}


//3c
std::ostream & operator<<(std::ostream & out, const Vector2 & vector) {
	out << vector.get(0) << "\n" << vector.get(1);
	return out;
}

Vector2 operator*(const Matrix2x2 & m, const Vector2 & v)
{	
	Vector2 product(0, 0);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			product.set(i, product.get(i) + (v.get(j))*m.get(i, j));
		}
	}
	return product;
}

Vector2 operator*(const Vector2& v, const Matrix2x2& m) {
	Vector2 product(0, 0);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			product.set(i, product.get(i) + (v.get(j))*m.get(i, j));
		}
	}
	return product;
}