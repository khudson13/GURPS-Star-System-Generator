#include "Orbit.h"
#include "DICE.h"



//*********************
// METHOD DEFINITIONS *
//*********************

// CONSTRUCTOR
Orbit::Orbit(double distance)
{
	orbital_distance = distance;
}

// OUTPUTS
int Orbit::count_Inner_Family() { return inner_family; }
int Orbit::count_Middle_Family() { return middle_family.size(); }
int Orbit::count_Outer_Family() { return outer_family; }
int Orbit::count_Moons() { return moons_vec.size(); }
int Orbit::count_Moonlets() { return moonlets; }
double Orbit::get_Distance() { return orbital_distance; }
std::string Orbit::get_Rings() { return rings; }
std::string Orbit::get_Type() { return object_type; }

// INSERTERS
void Orbit::set_Type(std::string type)
{
	object_type = type;
}

// GENERATORS
void Orbit::gen_Asteroid_Belt()
{
	// do nothing for now, reserved for later possible functionality
}

void Orbit::gen_Gas_Giant(double l_min)
{
	int roll{ Dice::roll_D6(3) };
	if (orbital_distance <= (4.85 * sqrt(l_min) + 1))
	{
		roll += 4;
	}
	if (roll >= 3 && roll <= 10)
	{
		object_type = "Small Gas Giant";
	}
	else if (roll >= 11 && roll <= 16)
	{
		object_type = "Medium Gas Giant";
	}
	else if (roll >= 17)
	{
		object_type = "Large Gas Giant";
	}

	gen_Giant_Moons();
}

void Orbit::gen_Giant_Moons()
{
	// inner family
	int roll{ Dice::roll_D6(2) };
	if (orbital_distance < 0.1)
	{
		roll -= 10;
	}
	else if (orbital_distance >= 0.1 && orbital_distance <= 0.5)
	{
		roll -= 8;
	}
	else if (orbital_distance > 0.5 && orbital_distance <= 0.75)
	{
		roll -= 6;
	}
	else if (orbital_distance > 0.75 && orbital_distance <= 1.5)
	{
		roll -= 3;
	}
	if (roll < 0)
	{
		roll = 0;
	}
	inner_family = roll;

	// set rings
	if (inner_family >= 6)
	{
		rings = "Significant";
	}
	if (inner_family >= 10)
	{
		rings = "Spectacular";
	}

	// middle family
	roll = Dice::roll_D6(1);
	if (orbital_distance <= 0.1)
	{
		roll = 0;
	}
	else if (orbital_distance > 0.1 && orbital_distance <= 0.5)
	{
		roll -= 5;
	}
	else if (orbital_distance > 0.5 && orbital_distance <= 0.75)
	{
		roll -= 4;
	}
	else if (orbital_distance > 0.75 && orbital_distance <= 1.5)
	{
		roll -= 1;
	}
	if (!(roll <= 0))
	{
		for (int i{ 0 }; i < roll; ++i)
		{
			Moon* moonptr{ new Moon };
			middle_family.push_back(moonptr);
		}
	}

	// outer family
	roll = Dice::roll_D6(1);
	if (orbital_distance <= 0.5)
	{
		roll = 0;
	}
	else if (orbital_distance > 0.5 && orbital_distance <= 0.75)
	{
		roll -= 5;
	}
	else if (orbital_distance > 0.75 && orbital_distance <= 1.5)
	{
		roll -= 4;
	}
	else if (orbital_distance > 1.5 && orbital_distance <= 3)
	{
		roll -= 1;
	}
	if (roll < 0)
	{
		roll = 0;
	}
	outer_family = roll;
}

void Orbit::gen_Terrestrial_Moons()
{
	int roll{ Dice::roll_D6(1) - 4 };
	if (orbital_distance <= 0.5)
	{
		roll = 0;
	}
	else if (orbital_distance > 0.5 && orbital_distance <= 0.75)
	{
		roll -= 3;
	}
	else if (orbital_distance > 0.75 && orbital_distance <= 1.5)
	{
		roll -= 1;
	}
	if (object_type == "Tiny Terrestrial")
	{
		roll -= 2;
	}
	else if (object_type == "Small Terrestrial")
	{
		roll -= 1;
	}
	else if (object_type == "Large Terrestrial")
	{
		roll += 1;
	}
	if (roll > 0)
	{
		for (int i{ 0 }; i < roll; ++i)
		{
			Moon* new_moon{ new Moon };
			moons_vec.push_back(new_moon);
		}
	}
	else
	{
		roll = Dice::roll_D6(1);
		if (orbital_distance <= 0.5)
		{
			roll = 0;
		}
		else if (orbital_distance > 0.5 && orbital_distance <= 0.75)
		{
			roll -= 3;
		}
		else if (orbital_distance > 0.75 && orbital_distance <= 1.5)
		{
			roll -= 1;
		}
		if (object_type == "Tiny Terrestrial")
		{
			roll -= 2;
		}
		else if (object_type == "Small Terrestrial")
		{
			roll -= 1;
		}
		else if (object_type == "Large Terrestrial")
		{
			roll += 1;
		}
		if (roll > 0)
		{
			moonlets = roll;
		}
	}
}

void Orbit::gen_Terrestrial_Planet()
{

	gen_Terrestrial_Moons();
}