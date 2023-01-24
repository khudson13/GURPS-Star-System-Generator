#include "SystemStats.h"
#include <iostream>
#include "Dice.h"

//*********************
// METHOD DEFINITIONS *
//*********************

//***************
// CONSTRUCTORS *
//***************
StarSystemStats::StarSystemStats()
{
	char response{ ' ' }; // store user's yes/no
	std::cout << "Does this system include a pregenerated garden world? (y/n): ";
	std::cin >> response;
	// ADD ERROR HANDLING AND CLEAR THE STREAM
	if (response == 'y' || response == 'Y')
	{
		pregen_garden_planet = true;
	}
	
	// run generator functs
	StarSystemStats::set_Num_of_Stars();
	StarSystemStats::define_Age();
}

//****************
// INPUT METHODS *
//****************

// add a new star
void StarSystemStats::add_Star(Star* primary)
{
	Star* starptr1{ new Star(primary, this) };	// instantiate new star
	starptr1->define_System_Pointer(this);	// tell star who it belongs to
	star_vec.push_back(starptr1);			// add star to owner system star vector
}

//*****************
// OUTPUT METHODS *
//*****************

double StarSystemStats::get_Age(){ return StarSystemStats::system_age; }
bool StarSystemStats::get_Garden_Planet_Status(){ return pregen_garden_planet; }
int StarSystemStats::get_Num_of_Stars(){ return num_of_stars; }
Star* StarSystemStats::get_Star(int index) { return star_vec[index]; }
double StarSystemStats::get_Stellar_Mass(int index) { return star_vec[index]->get_Mass(); }

//*********************
// DEFINITION METHODS *
//*********************

// define system age
void StarSystemStats::define_Age()
{
	int roll_result{ 0 };// random number for selecting the following values
	double base_age{ 0 };// randomly selected value for equation
	double step_A{ 0 };	// randomly selected value for equation
	double step_B{ 0 };	// randomly selected value for equation

	// age range if garden planet present
	if (get_Garden_Planet_Status())
	{
		roll_result = Dice::roll_D6(3) + 2;
	}
	// age range if garden planet not yet decided
	else
	{
		roll_result = Dice::roll_D6(3);
	}

	// GENERATE AGE USING TABLE AND EQUATION GURPS SPACE P. 102

	// Extreme Population I (newborns)
	if (roll_result == 3)
	{
		base_age = 0;
		step_A = 0;
		step_B = 0;
	}
	// Young Population I
	else if (roll_result >= 4 && roll_result <= 6)
	{
		base_age = 0.1;
		step_A = 0.3;
		step_B = 0.05;
	}
	// Intermediate Population I
	else if (roll_result >= 7 && roll_result <= 10)
	{
		base_age = 2;
		step_A = 0.6;
		step_B = 0.1;
	}
	// Old Population I
	else if (roll_result >= 11 && roll_result <= 14)
	{
		base_age = 5.6;
		step_A = 0.6;
		step_B = 0.1;
	}
	// Intermediate Population II
	else if (roll_result >= 15 && roll_result <= 17)
	{
		base_age = 8;
		step_A = 0.6;
		step_B = 0.1;
	}
	// Extreme Population II (Ancient)
	else if (roll_result == 18)
	{
		base_age = 10;
		step_A = 0.6;
		step_B = 0.1;
	}
	else
	{
		// SET ERROR STATE
	}

	// CALCULATE AND SET SYSTEM AGE
	system_age = base_age + ((Dice::roll_D6(1) - 1) * step_A) + ((Dice::roll_D6(1) - 1) * step_B);
}

// generate number of stars
void StarSystemStats::set_Num_of_Stars()
{
	int roll_3D6{ Dice::roll_D6(3) }; // result of roll

	// interpret roll
	if (roll_3D6 >= 3 && roll_3D6 <= 10)
	{
		num_of_stars = 1;
	}
	else if (roll_3D6 >= 11 && roll_3D6 <= 15)
	{
		num_of_stars = 2;
	}
	else if (roll_3D6 >= 16)
	{
		num_of_stars = 3;
	}
}