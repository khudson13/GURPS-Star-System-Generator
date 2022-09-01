#pragma once
class System_Stats
{
private:
	int num_of_stars;

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