#include "DICE.h"

// IMPLEMENTATION OF STATIC DICE CLASS

int Dice::roll_D6(int num_of_rolls)
{
	int roll_value{ 0 }; // cumulative value of roll

	static std::random_device rando;  // obtain random number from hardware for rng seed
	std::mt19937 gen(rando()); // seed the generator
	std::uniform_int_distribution<> distr(1, 6); // define the range
	
	// roll them bones
	for (int i{ 0 }; i < num_of_rolls; ++i)
	{
		roll_value += distr(gen);
	}

	return roll_value;
}