#include "SystemStats.h"
#include <iostream>
#include "Dice.h"

//*********************
// METHOD DEFINITIONS *
//*********************

SystemStats::SystemStats()
{
	char response{ ' ' }; // store user's yes/no
	std::cout << "Does this system include a pregenerated garden world? (y/n): ";
	std::cin >> response;
	// ADD ERROR HANDLING AND CLEAR THE STREAM
	if (response == 'y' || response == 'Y')
	{
		pregen_garden_planet = true;
	}
}

// get number of stars
int SystemStats::Get_Num_Stars()
{
	return num_of_stars;
}

// get status of pregen garden planet
bool SystemStats::get_Garden_Planet_Status()
{
	return pregen_garden_planet;
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