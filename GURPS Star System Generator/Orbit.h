#pragma once

#include <string>
#include <vector>

#include "Moon.h"

// DESCRIBE THE CONTENTS OF A SINGLE ORBIG
// with pointers to its moons if it's a planet

class Orbit
{
private:

	std::string object_type{ "" };			// what's in this orbit?
	std::string specific_type{ "" };		// the final type output
	double orbital_distance{ 0 };			// average distance from star

	// moons for gas giants
	int inner_family{ 0 };
	std::vector<Moon*> middle_family;
	int outer_family{ 0 };
	std::string rings{ "Insignificant" };

	// moons for terrestrial planets
	int moonlets{ 0 };
	std::vector<Moon*> moons_vec;

	// detail data
	double age{ 0 };						// age of system
	std::string atmosphere{ "" };			// type of atmosphere
	double atmospheric_pressure{ 0 };		// atmospheric pressure
	int average_surface_temperature{ 0 };	// average temp in Kelvin
	double atmosphere_mass{ 0 };			// mass of atmosphere
	double blackbody_temp{ 0 };				// inscrutable astronomical number needed for other calculations
	double density{ 0 };					// planet density in Earth densities
	double diameter{ 0 };					// diameter expressed in meters
	double gravity{ 0 };					// gravity in Gs
	std::string hydrosphere{ "" };			// liquid coverage
	double hydro_coverage{ 0 };				// surface coverage
	double orbital_period{ 0 };				// orbital period in years
	double planetary_mass{ 0 };				// mass of planet
	double parent_mass{ 0 };				// mass of parent star

public:
	Orbit(double distance, double parent_luminosity, double parent_mass, double age);

	// INSERTERS
	void set_Type(std::string);

	// OUTPUTS
	int count_Inner_Family();		// output number of inner family moonlets
	int count_Middle_Family();		// output number of middle family moons
	int count_Outer_Family();		// output number of outer family moonlets
	int count_Moons();				// output number of terrestrial planet's moons
	int count_Moonlets();			// output number of terrestrial planet's moonlets
	std::string get_Atmosphere();	// output atmosphere type
	double get_Atmo_Pressure();		// output atmospheric pressure in Earth atmospheres
	int get_Average_Surface_Temp();	// output surface temp
	double get_Diameter();			// output planet diameter
	double get_Distance();			// output orbital distance
	double get_Gravity();			// output gravity
	std::string get_Hydrosphere();	// output hydrosphere
	double get_Mass();				// output mass
	double get_Orbital_Period();	// output orbital period
	std::string get_Rings();		// output gas giant rings
	std::string get_Type();			// output type of body
	std::string get_Specific_Type();// output specific type

	// GENERATORS
	void gen_Asteroid_Belt();
	void gen_Gas_Giant(double l_min);
	void gen_Giant_Moons();
	void gen_Terrestrial_Moons();
	void gen_Terrestrial_Planet();
};