#include "SystemStats.h"
#include <iostream>
#include "Dice.h"

//*********************
// METHOD DEFINITIONS *
//*********************

//***************
// CONSTRUCTORS *
//***************
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
	
	// run generator functs
	SystemStats::set_Num_of_Stars();
	SystemStats::define_Age();
}

//****************
// INPUT METHODS *
//****************

// add a new star
void SystemStats::add_Star(Star primary)
{
	star_vec.push_back(new Star(primary));
}

//*****************
// OUTPUT METHODS *
//*****************

double SystemStats::get_Age(){ return SystemStats::system_age; }
bool SystemStats::get_Garden_Planet_Status(){ return pregen_garden_planet; }
int SystemStats::get_Num_of_Stars(){ return num_of_stars; }
Star SystemStats::get_Star(int index) { return star_vec[index]; }
double SystemStats::get_Stellar_Mass(int index) { return star_vec[index].get_Mass(); }

//*********************
// DEFINITION METHODS *
//*********************

// define system age
void SystemStats::define_Age()
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
void SystemStats::set_Num_of_Stars()
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