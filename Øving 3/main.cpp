
#include <iostream>
#include <math.h>
#include <time.h>
#include <random>
#include <cstdlib>
#include "cannonball.h"
#include "utilities.h"

int main() {
	std::random_device seeder;
	std::default_random_engine generator(seeder());
	char playing = 'y';
	std::cout << "Hei og velkommen til kanonspillet!" << std::endl;
	std::cout << "Du faar 10 forsoek til aa treffe en blink pa 0-1000m avstand." << std::endl;
	do
	{
		int tries = 10;
		bool win = 0;
		int distanceToTarget = modernRandomWithLimits(0, 1000, generator);
		// std::cout << distanceToTarget << std::endl; //test av randomgenerator
		std::cout << "Skriv vinkel paa kanonen og utgangsfart paa kulen:" << std::endl;
		for (int i = 0; i < tries; i++)
		{
			double theta = 0;
			double absVelocity = 0;
			getUserInput(&theta, &absVelocity);
			double velocityX;
			double velocityY;
			getVelocityVector(theta, absVelocity, &velocityX, &velocityY);
			int avvik = targetPractice(distanceToTarget, velocityX, velocityY);
			if (abs(avvik) < 5)
			{
				win = 1;
				break;
			}
			else
			{
				std::cout << "Du bommet med " << avvik << " meter. Du har " << tries - i - 1 << " forsoek igjen." << std::endl;
			}
		}
		if (win)
		{
			std::cout << "Gratulerer du vant!" << std::endl;
		}
		else
		{
			std::cout << "Du tapte, bedre lykke neste gang!" << std::endl;
		}
		std::cout << "Vil du spille igjen? [y/n]";
		std::cin >> playing;

	} while (playing == 'y');

	/*test of functions 3b
	std::cout << acclY() << std::endl;
	std::cout << velY(25, 0) << std::endl;
	std::cout << velY(25, 2.5) << std::endl;
	std::cout << velY(25, 5) << std::endl;
	std::cout << posX(50, 0) << std::endl;
	std::cout << posX(50, 2.5) << std::endl;
	std::cout << posX(50, 5) << std::endl;
	std::cout << posY(25, 0) << std::endl;
	std::cout << posY(25, 2.5) << std::endl;
	std::cout << posY(25, 5) << std::endl;
	return 0;
	*/

	
	//test of functions in assignment 4
	/*
	double theta = 0 ;
	double absVelocity = 0;
	getUserInput(&theta, &absVelocity);
	std::cout << "theta: " << theta << std::endl;
	std::cout << "absVelocity: " << absVelocity << std::endl;
	double velX = getVelocityX(theta, absVelocity);
	double velY = getVelocityY(theta, absVelocity);
	std::cout << "velX: " << velX << std::endl;
	std::cout << "velY: " << velY << std::endl;
	double testX = 0;
	double testY = 0;
	getVelocityVector(theta, absVelocity, &testX, &testY);
	std::cout << "testX: " << testX << "testY: " << testY << std::endl;
	double testDistance = getDistanceTraveled(testX, testY);
	std::cout << "distance: " << testDistance << std::endl;
	std::cout << "flighttime: " << flightTime(testY) << std::endl;
	std::cout << "targetpractise: " << targetPractice(testDistance, testX, testY) << std::endl;
	*/

	
	// 5a 
	/*
	srand(time(NULL)); //seeding randomizer
	for (int i = 0; i < 20; i++)
	{
		int random = randomWithLimits(2, 10);
		std::cout << random << std::endl;
	}
	*/

	/*5d (denne oppgaven sugde.)
	std::random_device seeder;
	std::default_random_engine generator(seeder());
	for (size_t i = 0; i < 20; i++)
	{
		std::cout << modernRandomWithLimits(0, 20, generator) << std::endl;
	}
	*/
}

