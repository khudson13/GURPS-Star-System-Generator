#pragma once

#include <random>

class System_Stats
{
private:
	int num_of_stars;
	std::random_device rando;  // obtain random number from hardware for rng seed
	

public:

	// return number of stars in system
	int num_Stars();

	//********************
	// SYSTEM GENERATORS *
	// *******************

	// populate system stars
	void gen_Stars();
};

//*********************
// METHOD DEFINITIONS *
//*********************

int System_Stats::num_Stars()
{
	return num_of_stars;
}

void System_Stats::gen_Stars()
{
	int roll_3D6{ 0 }; // result of roll

	std::mt19937 gen(rando()); // seed the generator
	std::uniform_int_distribution<> distr(3, 18); // define the range
	roll_3D6 = distr(gen);
}