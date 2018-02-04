#pragma once

#include <vector>
#include "Shape.h"

class Canvas {
public:
	void addShape( const Shape *shape );
	void rasterizeTo( Image &img );

private: 
	std::vector<const Shape *> shapes;

};
