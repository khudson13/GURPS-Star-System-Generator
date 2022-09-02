#pragma once
#include <random>

class Dice
{
private:
	static std::random_device rando;  // obtain random number from hardware for rng seed
	

public:

	// roll a six sided die x times
	static int roll_D6(int);
};

