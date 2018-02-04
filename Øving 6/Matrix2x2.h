#pragma once

#include <iostream>

//1a
class Matrix2x2
{
public:
	double get(int row, int column) const;
	void set(int row, int column, double value);
	Matrix2x2();
	Matrix2x2(double a, double b, double c, double d);

	void printMatrix();

	Matrix2x2 &operator +=(const Matrix2x2 &rhs);
	Matrix2x2 &operator -=(const Matrix2x2 &rhs);
	Matrix2x2 operator+(const Matrix2x2 &rhs) const;
	Matrix2x2 operator-(const Matrix2x2 &rhs) const;
	Matrix2x2 operator*(const Matrix2x2 &rhs) const;
	Matrix2x2& operator*=(const Matrix2x2 &rhs);

	double det() const;
	Matrix2x2 inverse() const;
private:
	double matrix[2][2];
};

std::ostream& operator <<(std::ostream& out, const Matrix2x2 &matrix);



