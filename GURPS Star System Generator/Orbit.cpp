#include "Orbit.h"


//*********************
// METHOD DEFINITIONS *
//*********************

// CONSTRUCTOR
Orbit::Orbit(double distance)
{
	orbital_distance = distance;
}

// OUTPUTS
double Orbit::get_Distance() { return orbital_distance; }
std::string Orbit::get_Type() { return object_type; }

// INSERTERS
void Orbit::set_Type(std::string type)
{
	object_type = type;
}