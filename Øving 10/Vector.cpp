#include "Vector.h"
#include <cmath>


Vector::Vector( const Matrix & other )
		: Matrix()
{	
	if (other.isValid() && other.getColumns() == 1)
		Matrix::operator=(other); 	
}




double Vector::dot( const Vector & rhs ) const {
	if ( !this->isValid() || this->getRows() != rhs.getRows())
		return nan("");

	double sum = 0.0;
	for ( unsigned int i = 0; i < this->getColumns(); ++i )
		sum += this->get(i)*rhs.get(i);
	
	return sum;
}

double Vector::lengthSquared() const {
	return this->dot(*this);
}

double Vector::length() const {
	return sqrt( lengthSquared() );
}

