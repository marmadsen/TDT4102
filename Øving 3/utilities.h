#pragma once
//#include <cstdlib> //disse to er super viktig!
#include <random> //... og jeg aner ikke hvorfor

//random numbers in the interval between and including lower and upper
int randomWithLimits(int lower, int upper);


//more modern randomizer
//random numbers in the interval between and including lower and upper
int modernRandomWithLimits(int min, int max, std::default_random_engine& generator);
