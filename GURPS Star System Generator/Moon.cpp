#include "Moon.h"
#include "DICE.h"

Moon::Moon(std::string parent_type, int orbit_depth, double star_mass, double planet_mass, double system_age,double p_diameter, bool gas_giant)
{
	planet_type = parent_type;
	orbit_position = orbit_depth;
	parent_mass = planet_mass;
	stellar_mass = star_mass;
	age = system_age;
	parent_diameter = p_diameter;
	gas_moon = gas_giant;

	// set size code so we can do this mathematically
	int size_code{ 0 };
	if (parent_type == "Tiny Terrestrial")
	{
		size_code = 1;
	}
	else if (parent_type == "Small Terrestrial")
	{
		size_code = 2;
	}
	else if (parent_type == "Standard Terrestrial")
	{
		size_code = 3;
	}
	else if (parent_type == "Large Terrestrial" || parent_type == "Small Gas Giant" || parent_type == "Medium Gas Giant" || parent_type == "Large Gas Giant")
	{
		size_code = 4;
	}
	int roll{ Dice::roll_D6(3) };
	if (roll <= 11)
	{
		size_difference = 3;
		size_code -= 3;
	}
	else if (roll >= 12 && roll <= 14)
	{
		size_difference = 2;
		size_code -= 2;
	}
	else if (roll >= 15)
	{
		size_difference = 1;
		size_code -= 1;
	}
	if (size_code <= 1)
	{
		size = "Tiny";
	}
	else if (size_code == 2)
	{
		size = "Small";
	}
	else if (size_code == 3)
	{
		size = "Standard";
	}

}

std::string Moon::get_Size() { return size; }
std::string Moon::get_Specific_Type() { return specific_type; }
std::string Moon::get_Atmosphere() { return atmosphere; }
int Moon::get_Axial_Tilt() { return axial_tilt; }
double Moon::get_Atmo_Pressure() { return atmospheric_pressure; }
double Moon::get_Average_Temp() { return average_surface_temperature; }
double Moon::get_Day_Length() { return length_of_day; }
double Moon::get_Density() { return density; }
double Moon::get_Diameter() { return diameter; }
double Moon::get_Gravity() { return gravity; }
std::string Moon::get_Hydrosphere() { return hydrosphere; }
int Moon::get_Hydro_Coverage() { return hydro_coverage; }
double Moon::get_Lunar_Mass() { return lunar_mass; }
double Moon::get_Orbital_Distance() { return orbital_distance ; }
double Moon::get_Orbital_Period() { return orbital_period; }
bool Moon::get_Retrograde() { return retrograde_rotation; }
std::string Moon::get_Tectonics() { return tectonic_activity; }
bool Moon::get_Tidal_Lock() { return tidally_locked; }
std::string Moon::get_Volcanism() { return volcanism; }

void Moon::set_Position(int index) { orbit_position = index; }
void Moon::set_Stellar_Mass(double mass) { stellar_mass = mass; }



void Moon::gen_Moon(double bb_temp)
{
	blackbody_temp = bb_temp;

	// find moon type
	if (size == "Tiny")
	{
		if (blackbody_temp <= 140)
		{
			if (orbit_position == 0 && gas_moon)
			{
				if (Dice::roll_D6(1) <= 3)
				{
					specific_type = "Tiny Sulfur";
				}
			}
			else
			{
				specific_type = "Tiny Ice-ball";
			}
		}
		else if (blackbody_temp > 140)
		{
			specific_type = "Tiny Rock-ball";
		}
	}
	else if (size == "Small")
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
	else if (size == "Standard")
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
			if (stellar_mass <= 0.65)
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
	else if (size == "Large")
	{
		if (blackbody_temp <= 150)
		{
			specific_type = "Large Ice-ball";
		}
		else if (blackbody_temp > 150 && blackbody_temp <= 230)
		{
			if (stellar_mass <= 0.65)
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
	if (size == "Tiny" || specific_type == "Small Hadean (p.76)" || specific_type == "Small Rock-ball" ||
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
	else if (specific_type == "Standard Greenhouse")
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
		specific_type == "Standard Cthonian  (p.76)")
	{
		hydrosphere = "None";
	}
	else if (specific_type == "Small Ice-ball")
	{
		hydrosphere = "Liquid Hydrocarbons " + std::to_string((Dice::roll_D6(1) + 2) * 10) + "% Surface Coverage";
	}
	else if (specific_type == "Standard Ammonia")
	{
		hydrosphere = "Liquid Ammonia ";
		int coverage{ (Dice::roll_D6(2) * 10) };
		if (coverage > 100)
		{
			coverage = 100;
		}
		hydrosphere += std::to_string(coverage) + "% Surface Coverage";
	}
	else if (specific_type == "Standard Ice-ball")
	{
		hydrosphere = "Seasonal Water ";
		int coverage{ (Dice::roll_D6(2) - 10) * 10 };
		if (coverage < 0)
		{
			coverage = 0;
		}
		hydrosphere += std::to_string(coverage) + "% Surface Coverage";
	}
	else if (specific_type == "Standard Ocean" || specific_type == "Standard Garden")
	{
		hydrosphere = "Water Oceans ";
		int coverage{ 0 };
		if (specific_type == "Standard Ocean" || specific_type == "Standard Garden")
		{
			coverage = (Dice::roll_D6(1) + 4) * 10;
		}
		else if (specific_type == "Large Ocean")
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
	else if (specific_type == "Standard Greenhouse")
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
	else if (specific_type == "Standard Ammonia")
	{
		blackbody_correction = 0.84 * (1 + (atmosphere_mass * 0.2));
	}
	else if (specific_type == "Standard Ice-ball")
	{
		blackbody_correction = 0.86 * (1 + (atmosphere_mass * 0.2));
	}
	else if (specific_type == "Standard Ocean"|| specific_type == "Standard Garden")
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
	else if (specific_type == "Standard Greenhouse")
	{
		blackbody_correction = 0.77 * (1 + (atmosphere_mass * 2));
	}
	else if (specific_type == "Standard Cthonian (p.76)")
	{
		blackbody_correction = 0.97;
	}
	//***
	average_surface_temperature = blackbody_temp * blackbody_correction;
	//***

	// find density
	if (specific_type == "Tiny Ice-ball" || specific_type == "Small Hadean (p.76)" || specific_type == "Small Ice-ball" ||
		specific_type == "Standard Hadean (p.76)" || specific_type == "Standard Ammonia")
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
	if (size == "Tiny")
	{
		double minimum_diameter{ sqrt(blackbody_temp / density) * 0.004 };
		double maximum_diameter{ sqrt(blackbody_temp / density) * 0.024 };
		diameter = minimum_diameter + ((Dice::roll_D6(2) - 2) * ((maximum_diameter - minimum_diameter) / 10));
	}
	else if (size == "Small")
	{
		double minimum_diameter{ sqrt(blackbody_temp / density) * 0.024 };
		double maximum_diameter{ sqrt(blackbody_temp / density) * 0.03 };
		diameter = minimum_diameter + ((Dice::roll_D6(2) - 2) * ((maximum_diameter - minimum_diameter) / 10));
	}
	else if (size == "Standard")
	{
		double minimum_diameter{ sqrt(blackbody_temp / density) * 0.03 };
		double maximum_diameter{ sqrt(blackbody_temp / density) * 0.065 };
		diameter = minimum_diameter + ((Dice::roll_D6(2) - 2) * ((maximum_diameter - minimum_diameter) / 10));
	}

	// find gravity
	gravity = density * diameter;

	// find mass
	lunar_mass = density * pow(diameter, 3);

	// find atmospheric pressure
	if (atmosphere == "None")
	{
		// do nothing
	}
	else if (size == "Small")
	{
		atmospheric_pressure = atmosphere_mass * gravity * 10;
	}
	else if (size == "Standard")
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

	// define orbital distance
	if (gas_moon)
	{
		int moon_roll{ Dice::roll_D6(3) + 3 };
		if (moon_roll >= 15)
		{
			moon_roll += Dice::roll_D6(2);
		}
		orbital_distance = static_cast<double>(moon_roll / 2) * (parent_diameter * 7930);
	}
	else
	{
		int moon_roll{ Dice::roll_D6(2) };
		if (size_difference == 2)
		{
			moon_roll += 2;
		}
		else if (size_difference == 1)
		{
			moon_roll += 4;
		}
		orbital_distance = static_cast<double>(moon_roll * 2.5) * (parent_diameter * 7930);
	}

	// define orbital period

	orbital_period = 0.166 * sqrt(pow((orbital_distance / 7930), 3) / (lunar_mass + parent_mass));

	// find tidal braking
	total_tidal_force = (2230000 * parent_mass * diameter) / orbital_distance;
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
		if (size == "Standard")
		{
			day_roll += 10;
		}
		else if (size == "Small")
		{
			day_roll += 14;
		}
		else if (size == "Tiny")
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
	if ((length_of_day / 24) >= orbital_period)
	{
		tidally_locked = true;
	}

	// check for retrograde rotation
	if (Dice::roll_D6(3) > 17)
	{
		retrograde_rotation = true;
	}

	// determine axial tilt
	int axial_roll{ Dice::roll_D6(3) };
	if (axial_roll >= 3 && axial_roll <= 6)
	{
		axial_tilt = Dice::roll_D6(2) - 2;
	}
	else if (axial_roll >= 7 && axial_roll <= 9)
	{
		axial_tilt = 10 + (Dice::roll_D6(2) - 2);
	}
	else if (axial_roll >= 10 && axial_roll <= 12)
	{
		axial_tilt = 20 + (Dice::roll_D6(2) - 2);
	}
	else if (axial_roll >= 13 && axial_roll <= 14)
	{
		axial_tilt = 30 + (Dice::roll_D6(2) - 2);
	}
	else if (axial_roll >= 15 && axial_roll <= 16)
	{
		axial_tilt = 40 + (Dice::roll_D6(2) - 2);
	}
	else if (axial_roll >= 17 && axial_roll <= 18)
	{
		axial_roll = Dice::roll_D6(1);
		if (axial_roll >= 1 && axial_roll <= 2)
		{
			axial_tilt = 50 + (Dice::roll_D6(2) - 2);
		}
		else if (axial_roll >= 3 && axial_roll <= 4)
		{
			axial_tilt = 60 + (Dice::roll_D6(2) - 2);
		}
		else if (axial_roll == 5)
		{
			axial_tilt = 70 + (Dice::roll_D6(2) - 2);
		}
		else if (axial_roll == 6)
		{
			axial_tilt = 80 + (Dice::roll_D6(2) - 2);
		}
	}

	// determine volcanism
	int volcanism_roll{ Dice::roll_D6(3) };
	volcanism_roll += static_cast<int>((gravity / age) * 40);
	if (specific_type == "Tiny Sulfur")
	{
		volcanism_roll += 60;
	}
	else if (planet_type == "Small Gas Giant" || planet_type == "Medium Gas Giant" || planet_type == "Large Gas Giant")
	{
		volcanism_roll += 5;
	}

	if (volcanism_roll <= 16)
	{
		volcanism = "None";
	}
	else if (volcanism_roll >= 17 && volcanism_roll <= 20)
	{
		volcanism = "Light";
	}
	else if (volcanism_roll >= 21 && volcanism_roll <= 26)
	{
		volcanism = "Moderate";
	}
	else if (volcanism_roll >= 27 && volcanism_roll <= 70)
	{
		volcanism = "Heavy";
	}
	else if (volcanism_roll > 70)
	{
		volcanism = "Extreme";
	}

	// determine tectonic activity
	int tectonic_roll{ Dice::roll_D6(3) };

	if (volcanism == "None")
	{
		tectonic_roll -= 8;
	}
	else if (volcanism == "Light")
	{
		tectonic_roll -= 4;
	}
	else if (volcanism == "Heavy")
	{
		tectonic_roll += 4;
	}
	else if (volcanism == "Extreme")
	{
		tectonic_roll += 8;
	}

	if (hydro_coverage == 0)
	{
		tectonic_roll -= 4;
	}
	else if (hydro_coverage < 50)
	{
		tectonic_roll -= 2;
	}

	if (size == "Tiny" || size == "Small")
	{
		tectonic_roll = 0;
	}

	if (tectonic_roll <= 6)
	{
		tectonic_activity = "None";
	}
	else if (tectonic_roll >= 7 && tectonic_roll <= 10)
	{
		tectonic_activity = "Light";
	}
	else if (tectonic_roll >= 11 && tectonic_roll <= 14)
	{
		tectonic_activity = "Moderate";
	}
	else if (tectonic_roll >= 15 && tectonic_roll <= 18)
	{
		tectonic_activity = "Heavy";
	}
	else if (tectonic_roll > 18)
	{
		tectonic_activity = "Extreme";
	}
}