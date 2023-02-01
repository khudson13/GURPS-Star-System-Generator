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
double Orbit::get_Distance() { return orbital_distance; }
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
}

void Orbit::gen_Giant_Moons()
{

}

void Orbit::gen_Terrestrial_Moons()
{

}

void Orbit::gen_Terrestrial_Planet()
{

}