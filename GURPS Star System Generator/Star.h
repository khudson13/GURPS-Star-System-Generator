#pragma once

#include <string>
#include <vector>

class StarSystemStats;	// including "SystemStats.h" creates a weird circular dependence, this seems to be better

// DESCRIBES A SINGLE STAR

class Star
{
private:

	int name{ 0 };										// numbered, to remember which companion it is (0 == primary)
	StarSystemStats* star_system_pointer{ nullptr };	// pointer to star system object
	std::vector<Star*> companion_vec;					// vector of companion stars

	bool has_companion{ false };		// does this star have a companion
	int num_of_companions{ 0 };			// number of companions this star has
	bool companion{ false };			// does this star orbit a primary?
	double orbital_radius{ 0 };			// orbital radius if companion
	std::string separation{ 0 };
	double eccentricity{ 0 };			// orbital eccentricity if companion
	std::string life_stage{ "" };		// life phase, main sequence, etc
	double luminosity{ 0 };				// brightness of star
	Star* primary{ nullptr };			// pointer to primary, if present
	double stellar_mass{ 0 };			// expressed in solar masses
	double stellar_radius{ 0 };			// radius of star
	std::string spectral_type{ "" };	// spectral type of star in main sequence e.g. G2
	int temp{ 0 };						// surface temperature in kelvins
	double l_max{ 0 };					// maximum luminosity in main sequence ** -1 if not applicable **
	double l_min{ 0 };					// minimum luminosity in main sequence
	double m_span{ 0 };					// duration of main sequence in billions of years ** -1 if not applicable **
	double s_span{ 0 };					// duration of sub-giant phase in billions of years ** -1 if not applicable **
	double g_span{ 0 };					// duration of giant phase in billions of years ** -1 if not applicable **

public:
	//**************
	// CONSTRUCTOR *
	//**************

	Star(Star*, StarSystemStats*, int);	// nullptr for primary stars, pointer to primary for companions
	
	//*******************
	// OUTPUT FUNCTIONS *
	//*******************

	bool get_Has_Companion();		// does this star have a companion?
	int get_Num_Of_Companions();	// output number of companions
	bool get_Is_Companion();		// is this star a companion?
	double get_Orbital_Radius();	// return orbital radius
	std::string get_Separation();	// degree of separation from primary if companion
	double get_Eccentricity();		// output eccentricity
	std::string get_Life_Stage();	// output life phase
	double get_Luminosity();		// output luminosity
	double get_L_Max();				// output l_max
	double get_L_Min();				// output l-min
	double get_M_Span();			// output phase lifespans
	double get_S_Span();				
	double get_G_Span();
	double get_Mass();				// output value of stellar_mass
	Star* get_Primary();			// output pointer to primary star or nullptr
	double get_Radius();			// output radius
	std::string get_Spectral_Type();// output spectral type
	int get_Temp();					// output temp in kelvins


	//*************
	// GENERATORS *
	//*************

	void gen_Characteristics();						// generate a range of characteristics based on mass
	void define_Life_Phase();						// define life phase based on age and mass
	void define_Orbital_Radius();					// find radius of companion orbit around primary
	void define_System_Pointer(StarSystemStats*);	// set pointer to home system
	void gen_Mass(bool garden_planet_present);		// generate value of stellar_mass (get pregen garden planet status from SystemStats)
};