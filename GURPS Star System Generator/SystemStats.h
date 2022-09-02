#pragma once

#include "DICE.h"

class SystemStats
{
private:
	int num_of_stars;
	
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

