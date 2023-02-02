#pragma once

#include <string>

class Moon
{
private:
	std::string size{ "" };
	std::string specific_type{ "" };

	// DETAIL DATA
	double age{ 0 };					// age
	std::string atmosphere{ "" };
	std::string hydrosphere{ "" };
	double atmosphere_mass{ 0 };
	double atmospheric_pressure{ 0 };
	double average_surface_temperature{ 0 };
	double blackbody_temp{ 0 };
	double density{ 0 };
	double diameter{ 0 };
	bool gas_moon{ false };
	double gravity{ 0 };
	int hydro_coverage{ 0 };
	double length_of_day{ 0 };
	double lunar_mass{ 0 };
	double orbital_distance{ 0 };		// orbital distance in planetary diameters
	double orbital_period{ 0 };
	double parent_diameter{ 0 };
	double parent_mass{ 0 };			// mass of parent planet
	std::string planet_type{ "" };		// type of parent planet
	int orbit_position{ 0 };			// index in parent's moons vec
	int size_difference{ 0 };			// difference in size between moon and parent
	double stellar_mass{ 0 };			// mass of planet's primary star
	int total_tidal_force{ 0 };
	bool tidally_locked{ false };

public:
	Moon(std::string parent_type, int orbit_position, double star_mass, double planet_mass, double system_age, double p_diameter, bool gas_giant);

	// INSERTS
	void set_Position(int index);
	void set_Stellar_Mass( double mass );

	// OUTPUTS
	std::string get_Atmosphere();
	double get_Atmo_Pressure();
	double get_Average_Temp();
	double get_Day_Length();
	double get_Density();
	double get_Diameter();
	double get_Gravity();
	std::string get_Hydrosphere();
	int get_Hydro_Coverage();
	double get_Lunar_Mass();
	double get_Orbital_Distance();
	double get_Orbital_Period();
	std::string get_Size();
	std::string get_Specific_Type();
	bool get_Tidal_Lock();

	// GENERATOR
	void gen_Moon(double bb_temp);		// create this moon
};