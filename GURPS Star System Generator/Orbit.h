#pragma once

#include <string>

// DESCRIBE THE CONTENTS OF A SINGLE ORBIG
// with pointers to its moons if it's a planet

class Orbit
{
private:

	std::string object_type{ "" };			// what's in this orbit?
	double orbital_distance{ 0 };			// average distance from star

public:
	Orbit(double distance);

	// INSERTERS
	void set_Type(std::string);

	// OUTPUTS
	double get_Distance();
};