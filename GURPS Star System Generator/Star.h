#pragma once

// DESCRIBES A SINGLE STAR

class Star
{
private:
	bool companion{ false };	// does this star orbit a primary?
	Star* primary{ nullptr };	// pointer to primary, if present
	double stellar_mass{ 0 };	// expressed in solar masses

public:
	Star(Star*);	// constructor for a companion star, primaries use the default constructor
	

	double get_Mass();		// output value of stellar_mass
	Star* get_Primary();	// output pointer to primary star or nullptr

	void gen_Mass(bool);	// generate value of stellar_mass (get pregen garden planet status from SystemStats)
};