#pragma once
#include "Matrix.h"

class Vector : public Matrix {
public: 
	Vector() 
		: Matrix() { 	}
	
	Vector(unsigned int N, double fill = 0.0)
		: Matrix( N, 1, fill)
	{ }

	Vector( const Matrix & other ); 

	double & at(int index) {
		return Matrix::at(index, 0);
	}

	const double & at(int index) const  {
		return Matrix::at(index, 0);
	}

	double get(int index) const { 
		return at(index); 
	}

	void set(int index, double value) { 
		at(index) = value; 
	}

	double dot( const Vector & rhs ) const;
	double lengthSquared() const;
	double length() const;
};

