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
	double orbital_distance{ 0 };			// average distance from star

	// moons for gas giants
	int inner_family{ 0 };
	std::vector<Moon*> middle_family;
	int outer_family{ 0 };
	std::string rings{ "Insignificant" };

	// moons for terrestrial planets
	int moonlets{ 0 };
	std::vector<Moon*> moons_vec;

public:
	Orbit(double distance);

	// INSERTERS
	void set_Type(std::string);

	// OUTPUTS
	int count_Inner_Family();		// output number of inner family moonlets
	int count_Middle_Family();		// output number of middle family moons
	int count_Outer_Family();		// output number of outer family moonlets
	int count_Moons();				// output number of terrestrial planet's moons
	int count_Moonlets();			// output number of terrestrial planet's moonlets
	double get_Distance();			// output orbital distance
	std::string get_Rings();		// output gas giant rings
	std::string get_Type();			// output type of body

	// GENERATORS
	void gen_Asteroid_Belt();
	void gen_Gas_Giant(double l_min);
	void gen_Giant_Moons();
	void gen_Terrestrial_Moons();
	void gen_Terrestrial_Planet();
};