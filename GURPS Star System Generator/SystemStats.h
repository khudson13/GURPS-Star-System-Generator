#pragma once

#include "Star.h"

#include <vector>

// GENERAL DATA ABOUT SOLAR SYSTEM
// VECTORS LISTING STARS, PLANETS, ETC

// contstructor generates number of stars and system age

class SystemStats
{
private:

	std::vector<Star*> star_vec;		// vector of companion stars
	// *** DEFINE VECTOR OF PLANETS HERE ***
	// *** MOON VECTORS ARE STORED WTIH THEIR ASSOCIATED PLANETS ***

	int num_of_stars{ 0 };

	//*****************************************
	// FOR SYSTEMS WITH A PREGENERATED PLANET *
	//*****************************************
	bool pregen_garden_planet{ false };	// is there a pregenerated garden planet?
	double system_age{ 0 };				// age of system

public:

	//***************
	// CONSTRUCTORS *
	//***************

	SystemStats();
	
	//*********************
	// VALUE INPUT FUNCTS *
	//*********************

	void add_Star(Star*);

	//**********************
	// VALUE OUTPUT FUNCTS *
	//**********************
	
	// get age
	double get_Age();

	// return presence of pregenerated garden planet
	bool get_Garden_Planet_Status();

	// return number of stars in system
	int get_Num_of_Stars();

	// return a star
	Star* get_Star(int index);

	// return mass of a given star
	double get_Stellar_Mass(int index);

	//********************
	// SYSTEM GENERATORS *
	// *******************

	// determine number of stars in system
	void set_Num_of_Stars();

	// define age of system
	void define_Age();
};

