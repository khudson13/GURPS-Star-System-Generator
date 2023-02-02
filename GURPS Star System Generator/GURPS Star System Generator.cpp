// GURPS Star System Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Plan to handle each selestial object as its own class, including a class to handle the general characteristics of the system as
a whole.

Currently this always creates the same filename. Probably best to let the user enter one to avoid overwrites.
*/

//********************
// STANDARD INCLUDES *
//********************
#include <fstream>
#include <iostream>
#include <string>

//********************
// PERSONAL INCLUDES *
//********************

#include "SystemStats.h"
#include "Star.h"
#include "Orbit.h"


int main()
{
    StarSystemStats NewSystem; // instantiate system
    std::ofstream System_Out("C:/Users/Kenda/Desktop/System_Data.txt");

    // GENERATE STAR(S)
    for (int i{ 0 }; i < NewSystem.get_Num_of_Stars(); ++i)
    {
        if (i == 0)
        {
            NewSystem.add_Star(nullptr, i); // add primary star
            NewSystem.get_Star(i)->gen_Mass(NewSystem.get_Garden_Planet_Status());
            NewSystem.get_Star(i)->gen_Characteristics();
            NewSystem.get_Star(i)->define_Life_Phase();
        }
        else
        {
            NewSystem.add_Star(NewSystem.get_Star(0), i);  // add first or second companion
            NewSystem.get_Star(i)->gen_Mass(NewSystem.get_Garden_Planet_Status());
            NewSystem.get_Star(i)->gen_Characteristics();
            NewSystem.get_Star(i)->define_Life_Phase();
            NewSystem.get_Star(i)->define_Orbital_Radius();
        }
    }

    // GENERATE ORBITS
    for (int i{ 0 }; i < NewSystem.get_Num_of_Stars(); ++i)
    {
        NewSystem.get_Star(i)->populate_Orbits();
    }


    // OUTPUT RESULTS
    System_Out << "Num of Stars: " << NewSystem.get_Num_of_Stars() << std::endl;
    System_Out << "System Age: " << NewSystem.get_Age() << " billion years" << std::endl << std::endl;

    for (int i{ 0 }; i < NewSystem.get_Num_of_Stars(); ++i)
    {
        System_Out << "Star #: " << i + 1 << std::endl;
        System_Out << "Mass: " << NewSystem.get_Star(i)->get_Mass() << std::endl;
        System_Out << "Spectral Type: " << NewSystem.get_Star(i)->get_Spectral_Type() << std::endl;
        System_Out << "Temperature: " << NewSystem.get_Star(i)->get_Temp() << std::endl;
        System_Out << "Life Phase: " << NewSystem.get_Star(i)->get_Life_Stage() << std::endl;
        System_Out << "Luminosity: " << NewSystem.get_Star(i)->get_Luminosity() << std::endl;
        System_Out << "Radius: " << NewSystem.get_Star(i)->get_Radius() << " AU" << std::endl;
        System_Out << "Orbital Period: " << NewSystem.get_Star(i)->get_Orbital_Period() << " years" << std::endl;
        if (NewSystem.get_Star(i)->get_Is_Companion())
        {
            System_Out << "Separation from primary: " << NewSystem.get_Star(i)->get_Separation() << std::endl;
            System_Out << "Average Orbital Radius: " << NewSystem.get_Star(i)->get_Orbital_Radius() << std::endl;
            System_Out << "Max Orbital Eccentricity: " << NewSystem.get_Star(i)->get_Eccentricity_Max() << std::endl;
            System_Out << "Min Orbital Eccentricity: " << NewSystem.get_Star(i)->get_Eccentricity_Min() << std::endl;
        }

        System_Out << "Gas Giant Distribution: " << NewSystem.get_Star(i)->get_Giant_Spacing() << std::endl;

        // OUTPUT ORBITS
        System_Out << "ORBITING OBJECTS: " << NewSystem.get_Star(i)->get_Num_of_Orbits() << std::endl;
        int orbit_number{ 1 };  // counting outward from star
        for (int ii{ 0 }; ii < NewSystem.get_Star(i)->get_Num_of_Orbits(); ++ii)
        {
            if (NewSystem.get_Star(i)->get_Orbit(ii)->get_Type() != "")
            {
                System_Out << "Orbit " << orbit_number << ": " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Type();
                System_Out << "  Distance: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Distance() << " AU" << std::endl;
                ++orbit_number;
            }
        }

        System_Out << std::endl << std::endl;
    }

    // OUTPUT ORBITAL OBJECT DETAILS
    System_Out << std::endl << std::endl << "*** ORBITAL BODY DETAILS ***" << std::endl << std::endl;
    for (int i{ 0 }; i < NewSystem.get_Num_of_Stars(); ++i)
    {
        System_Out << "Star: " << i + 1 << std::endl << std::endl;
        for (int ii{ 0 }; ii < NewSystem.get_Star(i)->get_Num_of_Orbits(); ++ii)
        {
            System_Out << "Orbit " << ii + 1 << ": " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Type() << std::endl;
            if (NewSystem.get_Star(i)->get_Orbit(ii)->get_Specific_Type() != "")
            {
                System_Out << "Orbit " << ii + 1 << ": " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Specific_Type() << std::endl;
            }
            System_Out << "  Distance: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Distance() << " AU" << std::endl;
            std::string planet_type{ NewSystem.get_Star(i)->get_Orbit(ii)->get_Type() };
            if (planet_type == "Small Gas Giant" || planet_type == "Medium Gas Giant" || planet_type == "Large Gas Giant")
            {
                System_Out << "  Diameter: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Diameter() << std::endl;
                System_Out << "  Rings: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Rings() << std::endl;
                System_Out << "  Inner Family: " << NewSystem.get_Star(i)->get_Orbit(ii)->count_Inner_Family() << " moonlets" << std::endl;
                System_Out << "  Middle Family: " << NewSystem.get_Star(i)->get_Orbit(ii)->count_Middle_Family() << " moons" << std::endl;
                System_Out << "  Outer Family: " << NewSystem.get_Star(i)->get_Orbit(ii)->count_Outer_Family() << " moonlets" << std::endl;
                // output moons
                if (NewSystem.get_Star(i)->get_Orbit(ii)->count_Middle_Family() > 0)
                {
                    System_Out << "  Moons: " << NewSystem.get_Star(i)->get_Orbit(ii)->count_Middle_Family() << std::endl;
                    System_Out << "* MOON DETAILS *" << std::endl << std::endl;
                    for (int iii{ 0 }; iii < NewSystem.get_Star(i)->get_Orbit(ii)->count_Middle_Family(); ++iii)
                    {
                        System_Out << "Size " << ": " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Gas_Moon(iii)->get_Size() << std::endl;
                        System_Out << "Type " << ": " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Gas_Moon(iii)->get_Specific_Type() << std::endl;
                        System_Out << "Orbital Distance " << ": " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Gas_Moon(iii)->get_Orbital_Distance() << " miles" << std::endl;
                        System_Out << "  Atmosphere: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Gas_Moon(iii)->get_Atmosphere() << std::endl;
                        System_Out << "  Atmospheric Pressure: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Gas_Moon(iii)->get_Atmo_Pressure() << " atmospheres" << std::endl;
                        System_Out << "  Hydrosphere: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Gas_Moon(iii)->get_Hydrosphere() << std::endl;
                        double temp_fahrenheit{ ((static_cast<double>(NewSystem.get_Star(i)->get_Orbit(ii)->get_Gas_Moon(iii)->get_Average_Temp()) - 273.15) * 9 / 5) + 32 };
                        temp_fahrenheit *= 100;
                        temp_fahrenheit = static_cast<double>((static_cast<int>(temp_fahrenheit))) / 100;
                        System_Out << "  Average Surface Temp: " << temp_fahrenheit << " degrees Fahrenheit" << std::endl;
                        System_Out << "  Diameter: " << (NewSystem.get_Star(i)->get_Orbit(ii)->get_Gas_Moon(iii)->get_Diameter()) * 7930 << " miles" << std::endl;
                        System_Out << "  Gravity: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Gas_Moon(iii)->get_Gravity() << " Gs" << std::endl;
                        System_Out << "  Mass: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Gas_Moon(iii)->get_Lunar_Mass() << " Earths" << std::endl;
                        System_Out << "  Orbital Period: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Gas_Moon(iii)->get_Orbital_Period() << " days" << std::endl;
                        System_Out << std::endl;
                    }
                    System_Out << "* END MOONS *" << std::endl << std::endl;
                }
            }
            if (planet_type == "Tiny Terrestrial" || planet_type == "Small Terrestrial" || planet_type == "Standard Terrestrial" || planet_type == "Large Terrestrial")
            {
                System_Out << "  Atmosphere: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Atmosphere() << std::endl;
                System_Out << "  Atmospheric Pressure: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Atmo_Pressure() << " atmospheres" << std::endl;
                System_Out << "  Hydrosphere: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Hydrosphere() << std::endl;
                double temp_fahrenheit{ ((static_cast<double>(NewSystem.get_Star(i)->get_Orbit(ii)->get_Average_Surface_Temp()) - 273.15) * 9/5) + 32};
                temp_fahrenheit *= 100;
                temp_fahrenheit = static_cast<double>((static_cast<int>(temp_fahrenheit))) / 100;
                System_Out << "  Average Surface Temp: " << temp_fahrenheit << " degrees Fahrenheit" << std::endl;
                System_Out << "  Diameter: " << (NewSystem.get_Star(i)->get_Orbit(ii)->get_Diameter()) * 7930 << " miles" << std::endl;
                System_Out << "  Gravity: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Gravity() << " Gs" << std::endl;
                System_Out << "  Mass: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Mass() << " Earths" << std::endl;
                System_Out << "  Orbital Period: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Orbital_Period() << " years" << std::endl;
                // output moons
                if (NewSystem.get_Star(i)->get_Orbit(ii)->count_Moons() > 0)
                {
                    System_Out << "  Moons: " << NewSystem.get_Star(i)->get_Orbit(ii)->count_Moons() << std::endl;
                    System_Out << "* MOON DETAILS *" << std::endl << std::endl;
                    for (int iii{ 0 }; iii < NewSystem.get_Star(i)->get_Orbit(ii)->count_Moons(); ++iii)
                    {
                        System_Out << "Size " << ": " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Terrestrial_Moon(iii)->get_Size() << std::endl;
                        System_Out << "Type " << ": " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Terrestrial_Moon(iii)->get_Specific_Type() << std::endl;
                        System_Out << "Orbital Distance " << ": " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Terrestrial_Moon(iii)->get_Orbital_Distance() << " miles" << std::endl;
                        System_Out << "  Atmosphere: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Terrestrial_Moon(iii)->get_Atmosphere() << std::endl;
                        System_Out << "  Atmospheric Pressure: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Terrestrial_Moon(iii)->get_Atmo_Pressure() << " atmospheres" << std::endl;
                        System_Out << "  Hydrosphere: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Terrestrial_Moon(iii)->get_Hydrosphere() << std::endl;
                        double temp_fahrenheit{ ((static_cast<double>(NewSystem.get_Star(i)->get_Orbit(ii)->get_Terrestrial_Moon(iii)->get_Average_Temp()) - 273.15) * 9 / 5) + 32 };
                        temp_fahrenheit *= 100;
                        temp_fahrenheit = static_cast<double>((static_cast<int>(temp_fahrenheit))) / 100;
                        System_Out << "  Average Surface Temp: " << temp_fahrenheit << " degrees Fahrenheit" << std::endl;
                        System_Out << "  Diameter: " << (NewSystem.get_Star(i)->get_Orbit(ii)->get_Terrestrial_Moon(iii)->get_Diameter()) * 7930 << " miles" << std::endl;
                        System_Out << "  Gravity: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Terrestrial_Moon(iii)->get_Gravity() << " Gs" << std::endl;
                        System_Out << "  Mass: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Terrestrial_Moon(iii)->get_Lunar_Mass() << " Earths" << std::endl;
                        System_Out << "  Orbital Period: " << NewSystem.get_Star(i)->get_Orbit(ii)->get_Terrestrial_Moon(iii)->get_Orbital_Period() << " days" << std::endl;
                        System_Out << std::endl;
                    }
                    System_Out << "* END MOONS *" << std::endl << std::endl;
                }
                else if (NewSystem.get_Star(i)->get_Orbit(ii)->count_Moonlets() > 0)
                {
                    System_Out << "  Moonlets: " << NewSystem.get_Star(i)->get_Orbit(ii)->count_Moonlets() << std::endl;
                }
            }
            System_Out << std::endl;
        }

        System_Out << std::endl << std::endl;

    }

    System_Out << std::endl;

    System_Out.close();
}