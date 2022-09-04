#include "Star.h"
#include "Dice.h"

//*********************
// METHOD DEFINITIONS *
//*********************

Star::Star(Star* prim)
{
	primary = prim;
}

double Star::get_Mass()
{
	return stellar_mass;
}

Star* Star::get_Primary()
{
	return primary;
}

//*************************
// STELLAR MASS GENERATOR *
//*************************

void Star::gen_Mass(bool garden_planet_present)
{
	if (!garden_planet_present && get_Primary() == nullptr) // standard primary star mass generator
	{
		int first_roll{ Dice::roll_D6(3) };	// store first dice output
		int second_roll{ Dice::roll_D6(3) }; // store second dice output

		// evaluate mass value
		switch (first_roll){
			case (3)	:
				if (second_roll >= 3 && second_roll <= 10)
				{
					stellar_mass = 2;
				}
				else
				{
					stellar_mass = 1.9;
				}
				break;
			case (4)	:
				if (second_roll >= 3 && second_roll <= 8)
				{
					stellar_mass = 1.8;
				}
				else if (second_roll >= 9 && second_roll <= 11)
				{
					stellar_mass = 1.7;
				}
				else
				{
					stellar_mass = 1.6;
				}
				break;
			case (5)	:
				if (second_roll >= 3 && second_roll <= 7)
				{
					stellar_mass = 1.5;
				}
				else if (second_roll >= 8 && second_roll <= 10)
				{
					stellar_mass = 1.45;
				}
				else if (second_roll >= 11 && second_roll <= 12)
				{
					stellar_mass = 1.4;
				}
				else
				{
					stellar_mass = 1.35;
				}
				break;
			case (6)	:
				if (second_roll >= 3 && second_roll <= 7)
				{
					stellar_mass = 1.3;
				}
				else if (second_roll >= 8 && second_roll <= 9)
				{
					stellar_mass = 1.25;
				}
				else if (second_roll == 10)
				{
					stellar_mass = 1.2;
				}
				else if (second_roll >= 11 && second_roll <= 12)
				{
					stellar_mass = 1.15;
				}
				else
				{
					stellar_mass = 1.1;
				}
				break;
			case (7)	:
				if (second_roll >= 3 && second_roll <= 7)
				{
					stellar_mass = 1.05;
				}
				else if (second_roll >= 8 && second_roll <= 9)
				{
					stellar_mass = 1;
				}
				else if (second_roll == 10)
				{
					stellar_mass = 0.95;
				}
				else if (second_roll >= 11 && second_roll <= 12)
				{
					stellar_mass = 0.9;
				}
				else
				{
					stellar_mass = 0.85;
				}
				break;
			case (8)	:
				if (second_roll >= 3 && second_roll <= 7)
				{
					stellar_mass = 0.8;
				}
				else if (second_roll >= 8 && second_roll <= 9)
				{
					stellar_mass = 0.75;
				}
				else if (second_roll == 10)
				{
					stellar_mass = 0.7;
				}
				else if (second_roll >= 11 && second_roll <= 12)
				{
					stellar_mass = 0.65;
				}
				else
				{
					stellar_mass = 0.6;
				}
				break;
			case (9)	:
				if (second_roll >= 3 && second_roll <= 8)
				{
					stellar_mass = 0.55;
				}
				else if (second_roll >= 9 && second_roll <= 11)
				{
					stellar_mass = 0.5;
				}
				else
				{
					stellar_mass = 0.45;
				}
				break;
			case (10)	:
				if (second_roll >= 3 && second_roll <= 8)
				{
					stellar_mass = 0.4;
				}
				else if (second_roll >= 9 && second_roll <= 11)
				{
					stellar_mass = 0.35;
				}
				else
				{
					stellar_mass = 0.3;
				}
				break;
			case (11)	:
				stellar_mass = 0.25;
				break;
			case (12)	:
				stellar_mass = 0.2;
				break;
			case (13)	:
				stellar_mass = 0.15;
				break;
			default		:
				stellar_mass = 0.1;
		}
	}

	else if (get_Primary != nullptr)	// companion mass generator
	{

	}

	else // special mass generator guarantees favorable environment for garden planet
	{

	}
}