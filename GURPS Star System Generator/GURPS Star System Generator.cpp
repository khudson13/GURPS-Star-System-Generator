// GURPS Star System Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Plan to handle each selestial object as its own class, including a class to handle the general characteristics of the system as
a whole.
*/

//********************
// STANDARD INCLUDES *
//********************
#include <iostream>

//********************
// PERSONAL INCLUDES *
//********************

#include "SystemStats.h"
#include "Star.h"
#include "Planet.h"


int main()
{
    SystemStats NewSystem; // instantiate system

    // GENERATE STAR(S)
    for (int i{ 0 }; i < NewSystem.get_Num_of_Stars(); ++i)
    {
        if (i == 0)
        {
            NewSystem.add_Star(nullptr); // add primary star
        }
        else
        {
            NewSystem.add_Star(NewSystem.get_Star(0));  // add first or second companion
        }
    }
}