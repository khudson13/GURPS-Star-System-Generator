#include "System_Stats.h"

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