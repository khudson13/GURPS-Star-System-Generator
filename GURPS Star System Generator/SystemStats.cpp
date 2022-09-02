#include "SystemStats.h"

//*********************
// METHOD DEFINITIONS *
//*********************

// get number of stars
int SystemStats::num_Stars()
{
	return num_of_stars;
}

// generate number of stars
void SystemStats::gen_Stars()
{
	int roll_3D6{ 0 }; // result of roll

	// roll 3D6
	
	
	roll_3D6 = Dice::roll_D6(3);

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
void SystemStats::set_Stars(int x)
{
	num_of_stars = x;
}