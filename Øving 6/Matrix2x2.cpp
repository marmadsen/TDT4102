#include "Matrix2x2.h"

#include <iostream>

//1b
double Matrix2x2::get(int row, int column) const {
	return matrix[row][column];
}

void Matrix2x2::set(int row, int column, double value) {
	matrix[row][column] = value;
}

//prints all elements in a 2x2 matrix in an ordered fashion
void Matrix2x2::printMatrix() {
	double a = get(0, 0);
	double b = get(0, 1);
	double c = get(1, 0);
	double d = get(1, 1);

	std::cout << a << "\t" << b << "\n" << c << "\t" << d << std::endl;
}

//1d
Matrix2x2::Matrix2x2() {
	set(0, 0, 1);
	set(0, 1, 0);
	set(1, 0, 0);
	set(1, 1, 1);
}

//1e
Matrix2x2::Matrix2x2(double a, double b, double c, double d) {
	set(0, 0, a);
	set(0, 1, b);
	set(1, 0, c);
	set(1, 1, d);
}


//2b
Matrix2x2& Matrix2x2::operator +=(const Matrix2x2 &rhs) {
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			set(i, j, get(i, j) + rhs.get(i, j));
		}
	}
	return *this;
}

Matrix2x2& Matrix2x2::operator -=(const Matrix2x2 &rhs) {
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			set(i, j, get(i, j) - rhs.get(i, j));
		}
	}
	return *this;
}

std::ostream& operator <<(std::ostream& out, const Matrix2x2 &matrix) {
	out << matrix.get(0, 0) << "\t" << matrix.get(0, 1) << "\n";
	out << matrix.get(1, 0) << "\t" << matrix.get(1, 1);
	return out;
}

//2d
Matrix2x2 Matrix2x2::operator+(const Matrix2x2 &rhs) const {
	Matrix2x2 retMat = *this;
	retMat += rhs;
	return retMat;
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2 &rhs) const {
	Matrix2x2 retMat = *this;
	retMat -= rhs;
	return retMat;
}

Matrix2x2 Matrix2x2::operator*(const Matrix2x2 &rhs) const {
	Matrix2x2 temp(0, 0, 0, 0);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int  k = 0; k < 2; k++)
			{
				temp.matrix[i][j] += (matrix[i][k] * rhs.get(k, j));
			}
		}
	}
	return temp;
}

//2f
Matrix2x2& Matrix2x2::operator*=(const Matrix2x2 &rhs) {
	*this = *this * rhs;
	return *this;
	
}

double Matrix2x2::det() const
{
	return (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
}

Matrix2x2 Matrix2x2::inverse() const {
	double det = this->det();
	if (det == 0)
	{
		Matrix2x2 retMat;
		return retMat;
	}
	else
	{
		Matrix2x2 retMat2((this->get(1, 1)*(1 / det)), (this->get(0, 1)*(-1 / det)), (this->get(1, 0)*(-1 / det)), (this->get(0, 0)*(1 / det)));
		return retMat2;
	}
}
