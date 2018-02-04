#pragma once
#include "Image.h"
#include <cstdlib>

class Shape {
private:
	Color color;
public:
	Shape(const Color & color) : color(color) {}
	const Color & getColor() const { return color; }
	virtual void draw( Image & ) const = 0;
	virtual ~Shape() = default;
	

};

class Line : public Shape {
public:
	Line( int x1, int y1, int x2, int y2, const Color &col );
	virtual void draw( Image &img ) const;
	static void drawLine(Image& img, int x1, int y1, int x2, int y2, const Color & color);
private:
	int x1, y1, x2, y2;
};

class Rectangle : public Shape {
public:
	Rectangle( int x1, int y1, int x2, int y2, const Color &col );
	virtual void draw( Image &img ) const;

private:
	int left, right, top, bottom;
};

class Circle : public Shape {
public:
	Circle( int x, int y, int r, const Color &col );
	virtual void draw( Image &img ) const;

private:
	int x, y, r;
};

