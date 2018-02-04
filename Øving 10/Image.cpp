#include "Image.h"
#include <cassert>
#include <cstring>

const unsigned int COLOR_COMPONENT_COUNT = 3;

Image::Image( unsigned int width, unsigned int height )
	: data( 0 )
	, width( width )
	, height( height ) {
	
	assert( width * height > 0 );

	data = new unsigned char [width * height * COLOR_COMPONENT_COUNT];
}

Image::~Image() {
	if ( data ) {
		delete [] data;
	}
}

unsigned int Image::getWidth() const {
	return width;
}

unsigned int Image::getHeight() const {
	return height;
}

unsigned char *Image::getScanLine(unsigned int line) {
	return data + width * COLOR_COMPONENT_COUNT * line;
}

const unsigned char *Image::getScanLine(unsigned int line) const {
	return data + width * COLOR_COMPONENT_COUNT * line;
}


Color Image::getPixelColor( unsigned int x, unsigned int y ) const {
	const unsigned char *pixel = data + (y * width + x) * COLOR_COMPONENT_COUNT;

	return Color( pixel[0], pixel[1], pixel[2] );
}
void Image::setPixelColor( unsigned int x, unsigned int y, const Color &color ) {
	unsigned char *pixel = data + ( y * width + x ) * COLOR_COMPONENT_COUNT;
	assert( x < width );
	assert( y < height );

	pixel[0] = color.red;
	pixel[1] = color.green;
	pixel[2] = color.blue;
}


void Image::fill( const Color &color ) {
	
	unsigned char *pixel = data;
	for ( unsigned int i = 0; i < width*height; ++i)
	{
	    pixel[0] = color.red;
	    pixel[1] = color.green;
	    pixel[2] = color.blue;

	    pixel += COLOR_COMPONENT_COUNT;
	}
}
