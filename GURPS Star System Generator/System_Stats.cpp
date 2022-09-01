#include "System_Stats.h"

//*********************
// METHOD DEFINITIONS *
//*********************

// get number of stars
int System_Stats::num_Stars()
{
	return num_of_stars;
}

// generate number of stars
void System_Stats::gen_Stars()
{
	int roll_3D6{ 0 }; // result of roll

	// roll 3D6
	std::mt19937 gen(rando()); // seed the generator
	std::uniform_int_distribution<> distr(3, 18); // define the range
	roll_3D6 = distr(gen);

	// interpret roll
	if (roll_3D6 >= 3 && roll_3D6 <= 10)
	{
		set_Stars(1);
	}
	else if (roll_3D6 >= 11 && roll_3D6 <= 15)
	{
		set_Stars(2);
	}
	else if (roll_3D6 >= 16)
	{
		set_Stars(3);
	}
}

// set number of stars
void System_Stats::set_Stars(int x)
{
	num_of_stars = x;
}