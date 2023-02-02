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
double Orbit::get_Atmo_Pressure() { return atmospheric_pressure; }
int Orbit::get_Average_Surface_Temp() { return average_surface_temperature; }
double Orbit::get_Diameter() { return diameter; }
double Orbit::get_Distance() { return orbital_distance; }
double Orbit::get_Gravity() { return gravity; }
std::string Orbit::get_Hydrosphere() { return hydrosphere; }
double Orbit::get_Day_Length() { return length_of_day; }
double Orbit::get_Mass() { return planetary_mass; }
double Orbit::get_Orbital_Period() { return orbital_period; }
bool Orbit::get_Tidal_Lock() { return tidally_locked; }
std::string Orbit::get_Rings() { return rings; }
std::string Orbit::get_Type() { return object_type; }
std::string Orbit::get_Specific_Type() { return specific_type; }

Moon* Orbit::get_Gas_Moon(int index) { return middle_family[index]; }
Moon* Orbit::get_Terrestrial_Moon(int index) { return moons_vec[index]; }

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

	int size_roll{ Dice::roll_D6(3) };
	if (size_roll <= 8)
	{
		if (object_type == "Small Gas Giant")
		{
			planetary_mass = 10;
			density = 0.42;
		}
		else if (object_type == "Medium Gas Giant")
		{
			planetary_mass = 100;
			density = 0.18;
		}
		else if (object_type == "Large Gas Giant")
		{
			planetary_mass = 600;
			density = 0.31;
		}
	}
	else if (size_roll >= 9 && size_roll <= 10)
	{
		if (object_type == "Small Gas Giant")
		{
			planetary_mass = 15;
			density = 0.26;
		}
		else if (object_type == "Medium Gas Giant")
		{
			planetary_mass = 150;
			density = 0.19;
		}
		else if (object_type == "Large Gas Giant")
		{
			planetary_mass = 800;
			density = 0.356;
		}
	}
	else if (size_roll == 11)
	{
		if (object_type == "Small Gas Giant")
		{
			planetary_mass = 20;
			density = 0.22;
		}
		else if (object_type == "Medium Gas Giant")
		{
			planetary_mass = 200;
			density = 0.2;
		}
		else if (object_type == "Large Gas Giant")
		{
			planetary_mass = 1000;
			density = 0.4;
		}
	}
	else if (size_roll == 12)
	{
		if (object_type == "Small Gas Giant")
		{
			planetary_mass = 30;
			density = 0.19;
		}
		else if (object_type == "Medium Gas Giant")
		{
			planetary_mass = 250;
			density = 0.22;
		}
		else if (object_type == "Large Gas Giant")
		{
			planetary_mass = 1500;
			density = 0.6;
		}
	}
	else if (size_roll == 13)
	{
		if (object_type == "Small Gas Giant")
		{
			planetary_mass = 40;
			density = 0.17;
		}
		else if (object_type == "Medium Gas Giant")
		{
			planetary_mass = 300;
			density = 0.24;
		}
		else if (object_type == "Large Gas Giant")
		{
			planetary_mass = 2000;
			density = 0.8;
		}
	}
	else if (size_roll == 14)
	{
		if (object_type == "Small Gas Giant")
		{
			planetary_mass = 50;
			density = 0.17;
		}
		else if (object_type == "Medium Gas Giant")
		{
			planetary_mass = 350;
			density = 0.25;
		}
		else if (object_type == "Large Gas Giant")
		{
			planetary_mass = 2500;
			density = 1;
		}
	}
	else if (size_roll == 15)
	{
		if (object_type == "Small Gas Giant")
		{
			planetary_mass = 60;
			density = 0.17;
		}
		else if (object_type == "Medium Gas Giant")
		{
			planetary_mass = 400;
			density = 0.26;
		}
		else if (object_type == "Large Gas Giant")
		{
			planetary_mass = 3000;
			density = 1.2;
		}
	}
	else if (size_roll == 16)
	{
		if (object_type == "Small Gas Giant")
		{
			planetary_mass = 70;
			density = 0.17;
		}
		else if (object_type == "Medium Gas Giant")
		{
			planetary_mass = 450;
			density = 0.27;
		}
		else if (object_type == "Large Gas Giant")
		{
			planetary_mass = 3500;
			density = 1.4;
		}
	}
	else if (size_roll >= 17)
	{
		if (object_type == "Small Gas Giant")
		{
			planetary_mass = 80;
			density = 0.17;
		}
		else if (object_type == "Medium Gas Giant")
		{
			planetary_mass = 500;
			density = 0.29;
		}
		else if (object_type == "Large Gas Giant")
		{
			planetary_mass = 4000;
			density = 1.6;
		}
	}

	diameter = cbrt(planetary_mass / density);
	
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
			Moon* moonptr{ new Moon(this->get_Type(), middle_family.size(), parent_mass, planetary_mass, age, diameter, true)};
			middle_family.push_back(moonptr);
			moonptr->gen_Moon(blackbody_temp);
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
	// modify based on proximity to star
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
	// modify based on planet size
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
	// if it's a large moon
	if (roll > 0)
	{
		for (int i{ 0 }; i < roll; ++i)
		{
			Moon* new_moon{ new Moon(this->get_Type(), moons_vec.size(), parent_mass, planetary_mass, age, diameter, false)};
			moons_vec.push_back(new_moon);
			new_moon->gen_Moon(blackbody_temp);
		}
	}
	// no large moon, check for moonlets
	else
	{
		roll = Dice::roll_D6(1);
		// modify based on proximity to star
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
		// modify based on planet size
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
	if (object_type == "Tiny Terrestrial" || specific_type == "Small Hadean (p.76)" || specific_type == "Small Rock-ball" ||
		specific_type == "Standard Hadean (p.76)" || specific_type == "Standard Cthonian (p.76)" || specific_type == "Large Cthonian (p.76)")
	{
		atmosphere = "None";
	}
	else if (specific_type == "Small Ice-ball")
	{
		atmosphere = "Nitrogen, Methane, ";
		if (Dice::roll_D6(3) <= 15)
		{
			atmosphere += "Suffocating and Mildly Toxic";
		}
		else
		{
			atmosphere += "Suffocating and Highly Toxic";
		}
	}
	else if (specific_type == "Standard Ammonia")
	{
		atmosphere = "Nitrogen, Ammonia, and Methane. Suffocating, Lethally Toxic, and Corrosive";
	}
	else if (specific_type == "Standard Ice-ball")
	{
		atmosphere = "Nitrogen and Carbon Dioxide. Suffocating";
		if (Dice::roll_D6(3) > 12)
		{
			atmosphere += " and Mildly Toxic";
		}
	}
	else if (specific_type == "Standard Ocean")
	{
		atmosphere = "Nitrogen and Carbon Dioxide. Suffocating";
		if (Dice::roll_D6(3) > 12)
		{
			atmosphere += " and Mildly Toxic";
		}
	}
	else if (specific_type == "Standard Garden")
	{
		atmosphere = "Nitrogen and Oxygen";
		if (Dice::roll_D6(3) >= 12)
		{
			int contaminant_roll{ Dice::roll_D6(3) };
			switch (contaminant_roll)
			{
			case (3)	:
			case (4)	:
				atmosphere += " plus Chlorine Gas";
				break;
			case (5)	:
			case (6)	:
				atmosphere += " plus Sulfure Compounds";
				break;
			case (7)	:
				atmosphere += " plus Nitrogen Compounds";
				break;
			case (8)	:
			case (9)	:
				atmosphere += " plus Organic Toxins";
				break;
			case (10)	:
			case (11)	:
				atmosphere += " but Low Oxygen";
				break;
			case (12)	:
			case (13)	:
				atmosphere += " plus Pollutants";
				break;
			case (14)	:
				atmosphere += " plus High Carbon Dioxide";
				break;
			case (15)	:
			case (16)	:
				atmosphere += " but Dangerously High Oxygen";
				break;
			case (17)	:
			case (18)	:
				atmosphere += " pluss Excessive Inert Gasses (nitrogen narcosis risk)";
				break;
			}
			atmosphere += " (p.80)";
		}
	}
	else if (specific_type == "Standard Greenhouse")
	{
		atmosphere = "Dense Carbon Dioxide or Highly Humid Nitrogen Based. Suffocating, Lethally Toxic, Corrosive";
	}
	else if (specific_type == "Large Ammonia")
	{
		atmosphere = "Helium, Ammonia, and Methane. Suffocating, Lethally Toxic, and Corrosive";
	}
	else if (specific_type == "Large Ice-ball")
	{
		atmosphere = "Helium, Nitroge, Volcanic Toxins. Suffocating, Highly Toxic";
	}
	else if (specific_type == "Large Ocean")
	{
		atmosphere = "Helium, Nitrogen, Volcanic Toxins. Suffocating, Highly Toxic";
	}
	else if (specific_type == "Large Garden")
	{
		atmosphere = "Nitrogen, Oxygen, Noble Gases";
		if (Dice::roll_D6(3) >= 12)
		{
			int contaminant_roll{ Dice::roll_D6(3) };
			switch (contaminant_roll)
			{
			case (3):
			case (4):
				atmosphere += " plus Chlorine Gas";
				break;
			case (5):
			case (6):
				atmosphere += " plus Sulfure Compounds";
				break;
			case (7):
				atmosphere += " plus Nitrogen Compounds";
				break;
			case (8):
			case (9):
				atmosphere += " plus Organic Toxins";
				break;
			case (10):
			case (11):
				atmosphere += " but Low Oxygen";
				break;
			case (12):
			case (13):
				atmosphere += " plus Pollutants";
				break;
			case (14):
				atmosphere += " plus High Carbon Dioxide";
				break;
			case (15):
			case (16):
				atmosphere += " but Dangerously High Oxygen";
				break;
			case (17):
			case (18):
				atmosphere += " pluss Excessive Inert Gasses (nitrogen narcosis risk)";
				break;
			}
			atmosphere += " (p.80)";
		}
	}
	else if (specific_type == "Large Greenhouse")
	{
		atmosphere = "Dense Carbon Dioxide or Highly Humid Nitrogen Based. Suffocating, Lethally Toxic, Corrosive";
	}

	// find atmospheric mass
	if (atmosphere != "None")
	{
		atmosphere_mass = Dice::roll_D6(3) / 10;
	}

	// find hydrosphere
	if (specific_type == "Tiny Rock-ball" || specific_type == "Tiny Ice-ball" || specific_type == "Small Rock-ball" ||
		specific_type == "Small Hadean (p.76)" || specific_type == "Standard Hadean (p.76)" || 
		specific_type == "Standard Cthonian  (p.76)" || specific_type == "Large Cthonian (p.76)")
	{
		hydrosphere = "None";
	}
	else if (specific_type == "Small Ice-ball")
	{
		hydrosphere = "Liquid Hydrocarbons " + std::to_string((Dice::roll_D6(1) + 2) * 10) + "% Surface Coverage";
	}
	else if (specific_type == "Standard Ammonia" || specific_type == "Large Ammonia")
	{
		hydrosphere = "Liquid Ammonia ";
		int coverage{ (Dice::roll_D6(2) * 10) };
		if (coverage > 100)
		{
			coverage = 100;
		}
		hydrosphere += std::to_string(coverage) + "% Surface Coverage";
	}
	else if (specific_type == "Standard Ice-ball" || specific_type == "Large Ice-ball")
	{
		hydrosphere = "Seasonal Water ";
		int coverage{ (Dice::roll_D6(2) - 10) * 10 };
		if (coverage < 0)
		{
			coverage = 0;
		}
		hydrosphere += std::to_string(coverage) + "% Surface Coverage";
	}
	else if (specific_type == "Standard Ocean" || specific_type == "Standard Garden" ||
		specific_type == "Large Ocean" || specific_type == "Large Garden")
	{
		hydrosphere = "Water Oceans ";
		int coverage{ 0 };
		if (specific_type == "Standard Ocean" || specific_type == "Standard Garden")
		{
			coverage = (Dice::roll_D6(1) + 4) * 10;
		}
		else if (specific_type == "Large Ocean" || specific_type == "Large Garden")
		{
			coverage = (Dice::roll_D6(1) + 6) * 10;
			if (coverage > 100)
			{
				coverage = 100;
			}
		}
		hydrosphere += std::to_string(coverage) + "% Surface Coverage";
		hydro_coverage = coverage;
	}
	else if (specific_type == "Standard Greenhouse" || specific_type == "Large Greenhouse")
	{
		hydrosphere = "Highly Acidic Water ";
		int coverage{ (Dice::roll_D6(2) - 7) * 10 };
		if (coverage < 0)
		{
			coverage = 0;
		}
		hydrosphere += std::to_string(coverage) + "% Surface Coverage";
	}

	// define climate
	double blackbody_correction{ 0 };
	if (specific_type == "Tiny Ice-ball")
	{
		blackbody_correction = 0.86;
	}
	else if (specific_type == "Tiny Rock-ball")
	{
		blackbody_correction = 0.97;
	}
	else if (specific_type == "Small Hadean (p.76)")
	{
		blackbody_correction = 0.67;
	}
	else if (specific_type == "Small Ice-ball")
	{
		blackbody_correction = 0.93 * (1 + (atmosphere_mass * 0.1));
	}
	else if (specific_type == "Small Rock-ball")
	{
		blackbody_correction = 0.96;
	}
	else if (specific_type == "Standard Hadean (p.76)")
	{
		blackbody_correction = 0.67;
	}
	else if (specific_type == "Standard Ammonia" || specific_type == "Large Ammonia")
	{
		blackbody_correction = 0.84 * (1 + (atmosphere_mass * 0.2));
	}
	else if (specific_type == "Standard Ice-ball" || specific_type == "Large Ice-ball")
	{
		blackbody_correction = 0.86 * (1 + (atmosphere_mass * 0.2));
	}
	else if (specific_type == "Standard Ocean" || specific_type == "Large Ocean" ||
		specific_type == "Standard Garden" || specific_type == "Large Garden")
	{
		if (hydro_coverage < 20)
		{
			blackbody_correction = 0.95 * (1 + (atmosphere_mass * 0.16));
		}
		else if (hydro_coverage > 20 && hydro_coverage <= 50)
		{
			blackbody_correction = 0.92 * (1 + (atmosphere_mass * 0.16));
		}
		else if (hydro_coverage > 50 && hydro_coverage <= 90)
		{
			blackbody_correction = 0.88 * (1 + (atmosphere_mass * 0.16));
		}
		else if (hydro_coverage > 90)
		{
			blackbody_correction = 0.84 * (1 + (atmosphere_mass * 0.16));
		}
	}
	else if (specific_type == "Standard Greenhouse" || specific_type == "Large Greenhouse")
	{
		blackbody_correction = 0.77 * (1 + (atmosphere_mass * 2));
	}
	else if (specific_type == "Standard Cthonian (p.76)" || specific_type == "Large Cthonian (p.76)")
	{
		blackbody_correction = 0.97;
	}
	//***
	average_surface_temperature = blackbody_temp * blackbody_correction;
	//***

	// find density
	if (specific_type == "Tiny Ice-ball" || specific_type == "Small Hadean (p.76)" || specific_type == "Small Ice-ball" ||
		specific_type == "Standard Hadean (p.76)" || specific_type == "Standard Ammonia" || specific_type == "Large Ammonia")
	{
		int density_roll{ Dice::roll_D6(3) };
		if (density_roll >= 3 && density_roll <= 6)
		{
			density = 0.3;
		}
		else if (density_roll >= 7 && density_roll <= 10)
		{
			density = 0.4;
		}
		else if (density_roll >= 11 && density_roll <= 14)
		{
			density = 0.5;
		}
		else if (density_roll >= 15 && density_roll <= 17)
		{
			density = 0.7;
		}
		else if (density_roll == 18)
		{
			density = 0.7;
		}
	}
	else if (specific_type == "Tiny Rock-ball" || specific_type == "Small Rock-ball")
	{
		int density_roll{ Dice::roll_D6(3) };
		if (density_roll >= 3 && density_roll <= 6)
		{
			density = 0.6;
		}
		else if (density_roll >= 7 && density_roll <= 10)
		{
			density = 0.7;
		}
		else if (density_roll >= 11 && density_roll <= 14)
		{
			density = 0.8;
		}
		else if (density_roll >= 15 && density_roll <= 17)
		{
			density = 0.9;
		}
		else if (density_roll == 18)
		{
			density = 1;
		}
	}
	else
	{
		int density_roll{ Dice::roll_D6(3) };
		if (density_roll >= 3 && density_roll <= 6)
		{
			density = 0.8;
		}
		else if (density_roll >= 7 && density_roll <= 10)
		{
			density = 0.9;
		}
		else if (density_roll >= 11 && density_roll <= 14)
		{
			density = 1;
		}
		else if (density_roll >= 15 && density_roll <= 17)
		{
			density = 1.1;
		}
		else if (density_roll == 18)
		{
			density = 1.2;
		}
	}

	// find diameter
	if (object_type == "Tiny Terrestrial")
	{
		double minimum_diameter{ sqrt(blackbody_temp / density) * 0.004 };
		double maximum_diameter{ sqrt(blackbody_temp / density) * 0.024 };
		diameter = minimum_diameter + ((Dice::roll_D6(2) - 2) * ((maximum_diameter - minimum_diameter) / 10));
	}
	else if (object_type == "Small Terrestrial")
	{
		double minimum_diameter{ sqrt(blackbody_temp / density) * 0.024 };
		double maximum_diameter{ sqrt(blackbody_temp / density) * 0.03 };
		diameter = minimum_diameter + ((Dice::roll_D6(2) - 2) * ((maximum_diameter - minimum_diameter) / 10));
	}
	else if (object_type == "Standard Terrestrial")
	{
		double minimum_diameter{ sqrt(blackbody_temp / density) * 0.03 };
		double maximum_diameter{ sqrt(blackbody_temp / density) * 0.065 };
		diameter = minimum_diameter + ((Dice::roll_D6(2) - 2) * ((maximum_diameter - minimum_diameter) / 10));
	}
	else if (object_type == "Large Terrestrial")
	{
		double minimum_diameter{ sqrt(blackbody_temp / density) * 0.065 };
		double maximum_diameter{ sqrt(blackbody_temp / density) * 0.091 };
		diameter = minimum_diameter + ((Dice::roll_D6(2) - 2) * ((maximum_diameter - minimum_diameter) / 10));
	}

	// find gravity
	gravity = density * diameter;

	// find mass
	planetary_mass = density * pow(diameter, 3);

	// find atmospheric pressure
	if (atmosphere == "None")
	{
		// do nothing
	}
	else if (object_type == "Small Terrestrial")
	{
		atmospheric_pressure = atmosphere_mass * gravity * 10;
	}
	else if (object_type == "Standard Terrestrial")
	{
		if (specific_type == "Standard Greenhouse")
		{
			atmospheric_pressure = atmosphere_mass * gravity * 100;
		}
		else
		{
			atmospheric_pressure = atmosphere_mass * gravity;
		}
	}
	else if (object_type == "Large Terrestrial")
	{
		if (specific_type == "Large Greenhouse")
		{
			atmospheric_pressure = atmosphere_mass * gravity * 500;
		}
		else
		{
			atmospheric_pressure = atmosphere_mass * gravity * 5;
		}
	}

	// define orbital period
	orbital_period = sqrt(pow(orbital_distance, 3) / parent_mass);

	gen_Terrestrial_Moons();

	// find tidal braking
	// from moons
	for (int i{ 0 }; i < moons_vec.size(); ++i)
	{
		total_tidal_force += (2230000 * moons_vec[i]->get_Lunar_Mass() * diameter) / pow(((moons_vec[i]->get_Orbital_Distance()/ planetary_mass) * 7930), 3);
	}
	// from star
	total_tidal_force += (0.46 * parent_mass * diameter) / pow(orbital_distance, 3);
	// final
	total_tidal_force = (total_tidal_force * age) / planetary_mass;
	// check for tidal lock
	if (total_tidal_force >= 50)
	{
		tidally_locked = true;
	}

	// find length of day
	int day_roll{ Dice::roll_D6(3) };
	int temp{ 0 };
	if (day_roll >= 16)
	{
		temp = day_roll;
		day_roll = -1; // slow orbit
	}
	else // modify by planet type
	{
		if (object_type == "Small Gas Giant" || object_type == "Large Terrestrial")
		{
			day_roll += 6;
		}
		else if (object_type == "Standard Terrestrial")
		{
			day_roll += 10;
		}
		else if (object_type == "Small Terrestrial")
		{
			day_roll += 14;
		}
		else if (object_type == "Tiny Terrestrial")
		{
			day_roll += 18;
		}
	}

	if (day_roll == -1 || day_roll > 36)
	{
		int slow_roll{ Dice::roll_D6(2) };
		if (slow_roll <= 6)
		{
			if (day_roll == -1)
			{
				day_roll = temp;
			}
			else
			{
				// keep original roll
			}
		}
		else if (slow_roll == 7)
		{
			day_roll = (Dice::roll_D6(1) * 2) * 24;
		}
		else if (slow_roll == 8)
		{
			day_roll = (Dice::roll_D6(1) * 5) * 24;
		}
		else if (slow_roll == 9)
		{
			day_roll = (Dice::roll_D6(1) * 10) * 24;
		}
		else if (slow_roll == 10)
		{
			day_roll = (Dice::roll_D6(1) * 20) * 24;
		}
		else if (slow_roll == 11)
		{
			day_roll = (Dice::roll_D6(1) * 50) * 24;
		}
		else if (slow_roll == 12)
		{
			day_roll = (Dice::roll_D6(1) * 100) * 24;
		}
	}

	length_of_day = day_roll + total_tidal_force;
	if (((length_of_day / 24) / 365) >= orbital_period)
	{
		tidally_locked = true;
	}
}