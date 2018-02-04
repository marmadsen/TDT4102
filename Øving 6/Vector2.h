#pragma once

#include "Matrix2x2.h"


class Vector2
{
public:
	double get(int row) const;
	void set(int row, double value);
	Vector2();
	Vector2(double a, double b);
	void printVector();

	double dot(const Vector2 &rightHandSide) const;
	double lengthSquared() const;
	double length() const;
private:
	double vector[2];
};

std::ostream& operator <<(std::ostream& out, const Vector2 &vector);

Vector2 operator*(const Matrix2x2& m, const Vector2& v);
Vector2 operator*(const Vector2& v, const Matrix2x2& m);
