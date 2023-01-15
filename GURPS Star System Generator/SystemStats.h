#pragma once

#include <vector>

// GENERAL DATA ABOUT SOLAR SYSTEM
// VECTORS LISTING STARS, PLANETS, ETC

class SystemStats
{
private:
	int num_of_stars{ 0 };
	// *** DEFINE VECTOR OF STARS HERE ***
	// *** DEFINE VECTOR OF PLANETS HERE ***
	// *** MOON VECTORS ARE STORED WTIH THEIR ASSOCIATED PLANETS ***

	//*****************************************
	// FOR SYSTEMS WITH A PREGENERATED PLANET *
	//*****************************************
	bool pregen_garden_planet{ false };	// is there a pregenerated garden planet?
	float system_age{ 0 };				// age of system
	
	// set number of stars in system
	void set_Stars(int);

public:

	//***************
	// CONSTRUCTORS *
	//***************

	SystemStats();
	
	//**********************
	// VALUE OUTPUT FUNCTS *
	//**********************
	
	// get age
	float get_Age();

	// return number of stars in system
	int get_Num_of_Stars();

	// return presence of pregenerated garden planet
	bool get_Garden_Planet_Status();

	//********************
	// SYSTEM GENERATORS *
	// *******************

	// populate system stars
	void set_Num_of_Stars();

	// define age of system
	void define_Age();
};

