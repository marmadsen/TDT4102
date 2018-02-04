#include "cannonball.h"
#include <iostream>
#include <math.h>

// acceleration in Y-direction (up/down)
double acclY() {
	double accY = -9.81;
	return accY;
}


//velocity in Y-direction
double velY(double initVelocity, double time) {
	double accY = acclY();
	double velY = initVelocity + accY * time;
	return velY;
}

//x-position, x_0 = 0, antar null luftmotstand
double posX(double initVelocity, double time) {
	double xPosition = initVelocity * time;
	return xPosition;
}

//y-position y_0 = 0
double posY(double initVelocity, double time) {
	double accY = acclY();
	double yPosition = initVelocity * time + (accY * time * time) / 2.0;
	return yPosition;
}

//prints the time, time is in seconds
void printTime(double time) {
	int hours = time / 3600;
	time -= hours * 3600;
	int minutes = time / 60;
	time -= minutes * 60;
	std::cout << hours << " hour(s), " << minutes << " minute(s), and " << time << " second(s)" << std::endl;
}

//returns the flighttime in seconds
double flightTime(double initVelocity) {
	double accY = acclY();
	double time = (2 * initVelocity) / (-accY);
	return time;
}

//4a
void getUserInput(double *theta, double *absVelocity) {
	std::cout << "Skriv vinkel i grader paa kanonen: ";
	std::cin >> *theta;
	std::cout << "Skriv fart paa kanonkulen: ";
	std::cin >> *absVelocity;
}

double getVelocityX(double theta, double absVelocity) {
	double thetaRad = theta * (3.141592 / 180.0);
	double speedX = absVelocity * cos(thetaRad);
	return speedX;
}

double getVelocityY(double theta, double absVelocity) {
	double thetaRad = theta * (3.141592 / 180.0);
	double speedY = absVelocity * sin(thetaRad);
	return speedY;
}

void getVelocityVector(double theta, double absVelocity,
	double *velocityX, double *velocityY) {
	*velocityX = getVelocityX(theta, absVelocity);
	*velocityY = getVelocityY(theta, absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY) {
	double timeOfImpact = flightTime(velocityY);
	double distanceTraveled = posX(velocityX, timeOfImpact);
	return distanceTraveled;
}

double targetPractice(double distanceToTarget,
	double velocityX,
	double velocityY) {
	double actualDistance = getDistanceTraveled(velocityX, velocityY);
	return (distanceToTarget - actualDistance);
}

