#include "Orbit.h"
#include "DICE.h"



//*********************
// METHOD DEFINITIONS *
//*********************

// CONSTRUCTOR
Orbit::Orbit(double distance, double parent_luminosity, double mass, double system_age)
{
	age = system_age;
	parent_mass = mass;
	orbital_distance = distance;
	blackbody_temp = 278 * pow(parent_luminosity, 1 / 4) / sqrt(orbital_distance);
}

// OUTPUTS
int Orbit::count_Inner_Family() { return inner_family; }
int Orbit::count_Middle_Family() { return middle_family.size(); }
int Orbit::count_Outer_Family() { return outer_family; }
int Orbit::count_Moons() { return moons_vec.size(); }
int Orbit::count_Moonlets() { return moonlets; }
std::string Orbit::get_Atmosphere() { return atmosphere; }
double Orbit::get_Distance() { return orbital_distance; }
std::string Orbit::get_Rings() { return rings; }
std::string Orbit::get_Type() { return object_type; }
std::string Orbit::get_Specific_Type() { return specific_type; }

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
			Moon* moonptr{ new Moon(this->get_Type())};
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
			Moon* new_moon{ new Moon(this->get_Type())};
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
	// find world type
	if (object_type == "Tiny Terrestrial")
	{
		if (blackbody_temp <= 140)
		{
			specific_type = "Tiny Ice-ball";
		}
		else if (blackbody_temp > 140)
		{
			specific_type = "Tiny Rock-ball";
		}
	}
	else if (object_type == "Small Terrestrial")
	{
		if (blackbody_temp <= 80)
		{
			specific_type = "Small Hadean (p.76)";
		}
		else if (blackbody_temp > 80 && blackbody_temp <= 140)
		{
			specific_type = "Small Ice-ball";
		}
		else if (blackbody_temp > 140)
		{
			specific_type = "Small Rock-ball";
		}
	}
	else if (object_type == "Standard Terrestrial")
	{
		if (blackbody_temp <= 80)
		{
			specific_type = "Standard Hadean (p.76)";
		}
		else if (blackbody_temp > 80 && blackbody_temp <= 150)
		{
			specific_type = "Standard Ice-ball";
		}
		else if (blackbody_temp > 150 && blackbody_temp <= 230)
		{
			if (parent_mass <= 0.65)
			{
				specific_type = "Standard Ammonia";
			}
			else
			{
				specific_type = "Standard Ice-ball";
			}
		}
		else if (blackbody_temp > 230 && blackbody_temp <= 240)
		{
			specific_type = "Standard Ice-ball";
		}
		else if (blackbody_temp > 240 && blackbody_temp <= 320)
		{
			int garden_chance{ Dice::roll_D6(3) };
			int garden_mod(static_cast<int>(age / 0.5));
			if (garden_mod > 10)
			{
				garden_mod = 10;
			}
			garden_chance += garden_mod;
			if (garden_chance >= 18)
			{
				specific_type = "Standard Garden";
			}
			else
			{
				specific_type = "Standard Ocean";
			}
		}
		else if (blackbody_temp > 320 && blackbody_temp <= 500)
		{
			specific_type = "Standard Greenhouse";
		}
		else if (blackbody_temp > 500)
		{
			specific_type = "Standard Cthonian (p.76)";
		}
	}
	else if (object_type == "Large Terrestrial")
	{
		if (blackbody_temp <= 150)
		{
			specific_type = "Large Ice-ball";
		}
		else if (blackbody_temp > 150 && blackbody_temp <= 230)
		{
			if (parent_mass <= 0.65)
			{
				specific_type = "Large Ammonia";
			}
			else
			{
				specific_type = "Large Ice-ball";
			}
		}
		else if (blackbody_temp > 230 && blackbody_temp <= 240)
		{
			specific_type = "Large Ice-ball";
		}
		else if (blackbody_temp > 240 && blackbody_temp <= 320)
		{
			int garden_chance{ Dice::roll_D6(3) };
			int garden_mod(static_cast<int>(age / 0.5));
			if (garden_mod > 5)
			{
				garden_mod = 5;
			}
			garden_chance += garden_mod;
			if (garden_chance >= 18)
			{
				specific_type = "Large Garden";
			}
			else
			{
				specific_type = "Large Ocean";
			}
		}
		else if (blackbody_temp > 320 && blackbody_temp <= 500)
		{
			specific_type = "Large Greenhouse";
		}
		else if (blackbody_temp > 500)
		{
			specific_type = "Large Cthonian";
		}
	}

	// find atmosphere
	if (object_type == "Tiny Terrestrial" || specific_type == "Small Hadean" || specific_type == "Small Rock-ball" ||
		specific_type == "Standard Cthonian" || specific_type == "Large Cthonian")
	{
		atmosphere = "None";
	}

	gen_Terrestrial_Moons();
}