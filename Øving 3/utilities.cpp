#include "utilities.h"
#include <cstdlib>
#include <random>


int randomWithLimits(int lower, int upper) {
	int random = rand() % (upper - lower + 1);
	random += lower;
	return random;
}


int modernRandomWithLimits(int lower, int upper, std::default_random_engine& generator) {
	std::uniform_int_distribution<int> uniform(lower, upper);
	int random_integer = uniform(generator);
	return random_integer;
}
