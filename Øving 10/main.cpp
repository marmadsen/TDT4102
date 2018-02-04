#include "Matrix.h"
#include "Vector.h"
#include "Image.h"
#include "Shape.h"
#include "Canvas.h"

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ostream>



using namespace std;

const unsigned int img_width = 255, img_height = 255;


int main() {

	//Test of vector implementation: 1e
	Matrix a(4, 4, 0.0); //for some reason this stopped working now??? Worked before, but now it chrashes
	a.set(0, 0, 1); //suspects it has to do with init of Matrix objects...
	a.set(0, 1, 2);
	a.set(0, 2, 3);
	a.set(0, 3, 4);
	a.set(1, 0, 5);
	a.set(1, 1, 6);
	a.set(1, 2, 7);
	a.set(1, 3, 8);
	a.set(2, 0, 9);
	a.set(2, 1, 0);
	a.set(2, 2, -1);
	a.set(2, 3, -2);
	a.set(3, 0, -3);
	a.set(3, 1, -4);
	a.set(3, 2, -5);
	a.set(3, 3, -6);

	cout << a;

	Vector b = Vector(4);
	b.set(0, 0);
	b.set(1, 1);
	b.set(2, 2);
	b.set(3, 3);

	cout << b;

	Vector c = a*b;
	cout << c;

	//2h, test of image
	Color crayola_fuchsia(193, 84, 193);
	Image filled(255, 255);
	filled.fill(crayola_fuchsia);
	saveImage(filled, "filledImage.bmp");

	

	
	Canvas canvas;

	// Test lines.
	Line line1(0, 0, 100, 50, Color(255, 0, 0));
	Line line2(0, 0, 100, 200, Color(0, 255, 0));

	canvas.addShape(&line1);
	canvas.addShape(&line2);

	//test rectangle
	Rectangle rect(5, 5, 100, 100, Color( 0, 0, 255 ) );
	canvas.addShape( &rect );

	//test of circle
	Circle circle(120, 120, 16, Color(0, 0, 0));
	canvas.addShape(&circle);

	Image img( 255, 255 );
	img.fill( Color( 255, 255, 255 ) );
	canvas.rasterizeTo( img );
	saveImage( img, "test.bmp" );

	//smileyface
	Canvas smiley;

	Circle face(127, 127, 100, Color(0, 0, 0));
	smiley.addShape(&face);

	Circle leftEye(87, 180, 20, Color(0, 0, 0));
	Circle rightEye(167, 180, 20, Color(0, 0, 0));
	smiley.addShape(&leftEye);
	smiley.addShape(&rightEye);

	Line mouthBase(100, 80, 154, 80, Color(0, 0, 0));
	Line leftMouth(80, 100, 100, 80, Color(0, 0, 0));
	Line rightMouth(154, 80, 174, 100, Color(0, 0, 0)); 
	smiley.addShape(&mouthBase);
	smiley.addShape(&leftMouth);
	smiley.addShape(&rightMouth);

	Image img2(255, 255);
	img.fill(Color(255, 255, 255));

	smiley.rasterizeTo(img2);
	saveImage(img2, "smiley.bmp");

	system("pause");


	return 0;
}
