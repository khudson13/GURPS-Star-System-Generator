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

//********************
// PERSONAL INCLUDES *
//********************

#include "SystemStats.h"
#include "Star.h"
#include "Planet.h"


int main()
{
    StarSystemStats NewSystem; // instantiate system
    std::ofstream System_Out("C:/Users/Kenda/Desktop/System_Data.txt");

    // GENERATE STAR(S)
    for (int i{ 0 }; i < NewSystem.get_Num_of_Stars(); ++i)
    {
        if (i == 0)
        {
            NewSystem.add_Star(nullptr); // add primary star
            NewSystem.get_Star(i)->gen_Mass(NewSystem.get_Garden_Planet_Status());
            NewSystem.get_Star(i)->gen_Characteristics();
            NewSystem.get_Star(i)->define_Life_Phase();
        }
        else
        {
            NewSystem.add_Star(NewSystem.get_Star(0));  // add first or second companion
            NewSystem.get_Star(i)->gen_Mass(NewSystem.get_Garden_Planet_Status());
            NewSystem.get_Star(i)->gen_Characteristics();
            NewSystem.get_Star(i)->define_Life_Phase();
        }
    }

    // OUTPUT RESULTS
    System_Out << "Num of Stars: " << NewSystem.get_Num_of_Stars() << std::endl;
    System_Out << "System Age: " << NewSystem.get_Age() << std::endl << std::endl;

    for (int i{ 0 }; i < NewSystem.get_Num_of_Stars(); ++i)
    {
        System_Out << "Star #: " << i + 1 << std::endl;
        System_Out << "Mass: " << NewSystem.get_Star(i)->get_Mass() << std::endl;
        System_Out << "Spectral Type: " << NewSystem.get_Star(i)->get_Spectral_Type() << std::endl;
        System_Out << "Temperature: " << NewSystem.get_Star(i)->get_Temp() << std::endl;
        System_Out << "Life Phase: " << NewSystem.get_Star(i)->get_Life_Stage() << std::endl;

        System_Out << std::endl;
    }

    System_Out.close();
}