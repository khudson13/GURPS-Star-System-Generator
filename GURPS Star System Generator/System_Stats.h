#pragma once

#include <random>

class System_Stats
{
private:
	int num_of_stars;
	std::random_device rando;  // obtain random number from hardware for rng seed
	
	// set number of stars in system
	void set_Stars(int);

public:
	
	// return number of stars in system
	int num_Stars();

	//********************
	// SYSTEM GENERATORS *
	// *******************

	// populate system stars
	void gen_Stars();
};

