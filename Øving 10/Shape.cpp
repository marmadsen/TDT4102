#include "Shape.h"
#include <cmath> // To get sqrt
#include <algorithm> // min and max

using namespace std;

Line::Line( int x1, int y1, int x2, int y2, const Color &col )
	: Shape( col ) 
	, x1( x1 )
	, y1( y1 )
	, x2( x2 )
	, y2( y2 )
{
}

void Line::draw(Image &img) const {
	drawLine(img, x1, y1, x2, y2, getColor());
}
void Line::drawLine(Image& img, int x1, int y1, int x2, int y2, const Color & color) {
	if (abs(y2 - y1) < abs(x2 - x1)) { // If the line is more horizontal than vertical.
		
		const float a = static_cast<float>(y2 - y1) / (x2 - x1);
		const float b = y1 - a * x1;

		
		int x_min = max<int>(min<int>(x1, x2), 0);
		int x_max = min<int>(max<int>(x1, x2), (img.getWidth() - 1));
		
		if (y2 - y1 != 0) {
			if (a > 0) {
				x_min = max<int>(x_min, static_cast<int>(-b / a));
				x_max = min<int>(x_max, static_cast<int>((img.getHeight() - 1 - b) / a));
			}
			else {
				x_max = min<int>(x_max, static_cast<int>(-b / a));
				x_min = max<int>(x_min, static_cast<int>((img.getHeight() - 1 - b) / a));
			}
		}

		for (int x = x_min; x <= x_max; ++x) {
			img.setPixelColor(x, static_cast<int>(a * x + b), color);
		}
	}
	else { // Line is more vertical than horizontal, flip axis.
		
		const float a = static_cast<float>(x2 - x1) / (y2 - y1);
		const float b = x1 - a * y1;

		
		int y_min = max<int>(min(y1, y2), 0);
		int y_max = min<int>(max(y1, y2), img.getHeight() - 1);
		
		if (x2 - x1 != 0) {

			if (a > 0) {
				y_min = max<int>(y_min, static_cast<int>(-b / a));
				y_max = min<int>(y_max, static_cast<int>(((img.getWidth() - 1) - b) / a));
			}
			else {
				y_max = min<int>(y_max, static_cast<int>(-b / a));
				y_min = max<int>(y_min, static_cast<int>((img.getHeight() - 1 - b) / a));
			}

		}


		for (int y = y_min; y <= y_max; ++y) {
			img.setPixelColor(static_cast<int>(y * a + b), y, color);
		}
	}
}

Rectangle::Rectangle( int x1, int y1, int x2, int y2, const Color &col )

	: Shape(col)
	, top( max( y1, y2 ))
	, right( max( x1, x2 ))
	, left( min( x1, x2 ))
	, bottom( min( y1, y2 ))
	{}

void Rectangle::draw( Image &img ) const {
	Line::drawLine(img, left, top, left, bottom, getColor());
	Line::drawLine(img, right, top, right, bottom, getColor());
	Line::drawLine(img, left, top, right, top, getColor());
	Line::drawLine(img, left, bottom, right, bottom, getColor());

}


Circle::Circle( int x, int y, int r, const Color &col )
	: Shape( col ) 
	, x( x )
	, y( y )
	, r( abs( r ) )   
{}

void Circle::draw( Image &img ) const {
	const int rpow2 = r * r;
	for ( int i = -r; i <= r; ++i ) {
		const int j = static_cast<int>( sqrt( static_cast<double>( rpow2 - i * i ) ) );
		if ( x + i >= 0 && x + i < ( int ) img.getWidth() ) {
			if ( y + j >= 0 && y + j < ( int ) img.getHeight() ) {
				img.setPixelColor( x + i, y + j, getColor() );
			}
			if ( y - j >= 0 && y - j < ( int ) img.getHeight() ) {
				img.setPixelColor( x + i, y - j, getColor() );
			}
		}
		if ( y + i >= 0 && y + i < ( int ) img.getHeight() ) {
			if ( x + j >= 0 && x + j < ( int ) img.getWidth() ) {
				img.setPixelColor( x + j, y + i, getColor() );
			}
			if ( x - j >= 0 && x - j < ( int ) img.getWidth() ) {
				img.setPixelColor( x - j, y + i, getColor() );
			}
		}
	}
}


