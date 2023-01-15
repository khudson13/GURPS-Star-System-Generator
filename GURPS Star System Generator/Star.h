#pragma once

#include <string>
#include <vector>

// DESCRIBES A SINGLE STAR

class Star
{
private:
	bool has_companion{ false };		// does this star have a companion
	int num_of_companions{ 0 };			// number of companions this star has
	// VECTOR OF COMPANION STARS
	bool companion{ false };			// does this star orbit a primary?
	Star* primary{ nullptr };			// pointer to primary, if present
	float stellar_mass{ 0 };			// expressed in solar masses
	std::string spectral_type{ "" };	// spectral type of star in main sequence e.g. G2
	int temp{ 0 };						// surface temperature in kelvins
	float l_max{ 0 };					// maximum luminosity in main sequence
	float l_min{ 0 };					// minimum luminosity in main sequence
	float m_span{ 0 };					// duration of main sequence in billions of years
	float s_span{ 0 };					// duration of sub-giant phase in billions of years
	float g_span{ 0 };					// duration of giant phase in billions of years

public:
	//**************
	// CONSTRUCTOR *
	//**************

	Star(Star*);	// nullptr for primary stars, pointer to primary for companions
	
	//*******************
	// OUTPUT FUNCTIONS *
	//*******************

	bool get_Has_Companion();		// does this star have a companion?
	int get_Num_Of_Companions();	// output number of companions
	bool get_Is_Companion();		// is this star a companion?
	float get_L_Max();				// output l_max
	float get_L_Min();				// output l-min
	float get_M_Span();				// output phase lifespans
	float get_S_Span();				
	float get_G_Span();
	float get_Mass();				// output value of stellar_mass
	Star* get_Primary();			// output pointer to primary star or nullptr
	std::string get_Spectral_Type();// output spectral type
	int get_Temp();					// output temp in kelvins
	

	//*************
	// GENERATORS *
	//*************

	void gen_Characteristics();	// generate a range of characteristics based on mass
	void gen_Mass(bool);		// generate value of stellar_mass (get pregen garden planet status from SystemStats)
};