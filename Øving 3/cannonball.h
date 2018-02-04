#pragma once

// acceleration in Y-direction (up/down)
double acclY();

//velocity in Y-direction
double velY(double initVelocity, double time);

//x-position
double posX(double initVelocity, double time);

//y-position
double posY(double initVelocity, double time);

//prints the time
void printTime(double time);

//returns the flighttime in seconds
double flightTime(double initVelocity);

// Ber brukeren om to tall, en vinkel, og en fart.
// Disse verdiene skal lagres i minnet som pekerne
// theta og absVelocity peker paa.
void getUserInput(double *theta, double *absVelocity);

// Returnerer henholdsvis farten i X-, og Y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

// Dekomponerer farten gitt av absVelocity, i X- og Y-komponentene
// gitt vinkelen theta. Disse komponentene lagres i minnet.
void getVelocityVector(double theta, double absVelocity,
	double *velocityX, double *velocityY);

// Returnerer horisontal distanse kulen flyr
double getDistanceTraveled(double velocityX, double velocityY);

// takes in a target distance, initial x- and y- pos
//returns the difference
double targetPractice(double distanceToTarget,
	double velocityX,
	double velocityY);
