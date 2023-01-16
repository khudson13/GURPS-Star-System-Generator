#include "Star.h"
#include "Dice.h"

//*********************
// METHOD DEFINITIONS *
//*********************

// CONSTRUCTOR for companiohn
Star::Star(Star* prim)
{
	primary = prim;
}

// OUTPUT METHODS
double Star::get_G_Span() { return g_span; }
bool Star::get_Has_Companion(){ return has_companion; }
bool Star::get_Is_Companion() { return companion; }
double Star::get_L_Max() { return l_max; }
double Star::get_L_Min() { return l_min; }
double Star::get_Mass(){ return stellar_mass; }
double Star::get_M_Span() { return m_span; }
int Star::get_Num_Of_Companions() { return num_of_companions; }
Star* Star::get_Primary(){ return primary; }
std::string Star::get_Spectral_Type() { return spectral_type; }
double Star::get_S_Span() { return s_span; }
int Star::get_Temp() { return temp; }


// GENERATORS AND MISC
void Star::gen_Characteristics()
{
	if (stellar_mass == 0.10)
	{
		spectral_type = "M7";
		temp = 3100;
		l_min = 0.0012;
		l_max = -1;
		m_span = -1;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.15)
	{
		spectral_type = "M6";
		temp = 3200;
		l_min = 0.0036;
		l_max = -1;
		m_span = -1;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.20)
	{
		spectral_type = "M5";
		temp = 3200;
		l_min = 0.0079;
		l_max = -1;
		m_span = -1;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.25)
	{
		spectral_type = "M4";
		temp = 3300;
		l_min = 0.015;
		l_max = -1;
		m_span = -1;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.30)
	{
		spectral_type = "M4";
		temp = 3300;
		l_min = 0.024;
		l_max = -1;
		m_span = -1;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.35)
	{
		spectral_type = "M3";
		temp = 3400;
		l_min = 0.037;
		l_max = -1;
		m_span = -1;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.40)
	{
		spectral_type = "M2";
		temp = 3500;
		l_min = 0.054;
		l_max = -1;
		m_span = -1;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.45)
	{
		spectral_type = "M1";
		temp = 3600;
		l_min = 0.07;
		l_max = 0.08;
		m_span = 70;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.50)
	{
		spectral_type = "M0";
		temp = 3800;
		l_min = 0.09;
		l_max = 0.11;
		m_span = 59;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.55)
	{
		spectral_type = "K8";
		temp = 4000;
		l_min = 0.11;
		l_max = 0.15;
		m_span = 50;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.60)
	{
		spectral_type = "K6";
		temp = 4200;
		l_min = 0.13;
		l_max = 0.20;
		m_span = 42;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.65)
	{
		spectral_type = "K5";
		temp = 4400;
		l_min = 0.15;
		l_max = 0.25;
		m_span = 37;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.70)
	{
		spectral_type = "K4";
		temp = 4600;
		l_min = 0.19;
		l_max = 0.35;
		m_span = 30;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.75)
	{
		spectral_type = "K2";
		temp = 4900;
		l_min = 0.23;
		l_max = 0.48;
		m_span = 24;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.80)
	{
		spectral_type = "K0";
		temp = 5200;
		l_min = 0.28;
		l_max = 0.65;
		m_span = 20;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.85)
	{
		spectral_type = "G8";
		temp = 5400;
		l_min = 0.36;
		l_max = 0.84;
		m_span = 17;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.90)
	{
		spectral_type = "G6";
		temp = 5500;
		l_min = 0.45;
		l_max = 1.0;
		m_span = 14;
		s_span = -1;
		g_span = -1;
	}
	else if (stellar_mass == 0.95)
	{
		spectral_type = "G4";
		temp = 5700;
		l_min = 0.56;
		l_max = 1.3;
		m_span = 12;
		s_span = 1.8;
		g_span = 1.1;
	}
	else if (stellar_mass == 1.00)
	{
		spectral_type = "G2";
		temp = 5800;
		l_min = 0.68;
		l_max = 1.6;
		m_span = 10;
		s_span = 1.6;
		g_span = 1.0;
	}
	else if (stellar_mass == 1.05)
	{
		spectral_type = "G1";
		temp = 5900;
		l_min = 0.87;
		l_max = 1.9;
		m_span = 8.8;
		s_span = 1.4;
		g_span = 0.8;
	}
	else if (stellar_mass == 1.10)
	{
		spectral_type = "G0";
		temp = 6000;
		l_min = 1.1;
		l_max = 2.2;
		m_span = 7.7;
		s_span = 1.2;
		g_span = 0.7;
	}
	else if (stellar_mass == 1.15)
	{
		spectral_type = "F9";
		temp = 6100;
		l_min = 1.4;
		l_max = 2.6;
		m_span = 6.7;
		s_span = 1.0;
		g_span = 0.6;
	}
	else if (stellar_mass == 1.20)
	{
		spectral_type = "F8";
		temp = 6300;
		l_min = 1.7;
		l_max = 3.0;
		m_span = 5.9;
		s_span = 0.9;
		g_span = 0.6;
	}
	else if (stellar_mass == 1.25)
	{
		spectral_type = "F7";
		temp = 6400;
		l_min = 2.1;
		l_max = 3.5;
		m_span = 5.2;
		s_span = 0.8;
		g_span = 0.5;
	}
	else if (stellar_mass == 1.30)
	{
		spectral_type = "F6";
		temp = 6500;
		l_min = 2.5;
		l_max = 3.9;
		m_span = 4.6;
		s_span = 0.7;
		g_span = 0.4;
	}
	else if (stellar_mass == 1.35)
	{
		spectral_type = "F5";
		temp = 6600;
		l_min = 3.1;
		l_max = 4.5;
		m_span = 4.1;
		s_span = 0.6;
		g_span = 0.4;
	}
	else if (stellar_mass == 1.40)
	{
		spectral_type = "F4";
		temp = 6700;
		l_min = 3.7;
		l_max = 5.1;
		m_span = 3.7;
		s_span = 0.6;
		g_span = 0.4;
	}
	else if (stellar_mass == 1.45)
	{
		spectral_type = "F3";
		temp = 6900;
		l_min = 4.3;
		l_max = 5.7;
		m_span = 3.3;
		s_span = 0.5;
		g_span = 0.3;
	}
	else if (stellar_mass == 1.50)
	{
		spectral_type = "F2";
		temp = 7000;
		l_min = 5.1;
		l_max = 6.5;
		m_span = 3.0;
		s_span = 0.5;
		g_span = 0.3;
	}
	else if (stellar_mass == 1.60)
	{
		spectral_type = "F0";
		temp = 7300;
		l_min = 6.7;
		l_max = 8.2;
		m_span = 2.5;
		s_span = 0.4;
		g_span = 0.2;
	}
	else if (stellar_mass == 1.70)
	{
		spectral_type = "A9";
		temp = 7500;
		l_min = 8.6;
		l_max = 10;
		m_span = 2.1;
		s_span = 0.3;
		g_span = 0.2;
	}
	else if (stellar_mass == 1.80)
	{
		spectral_type = "A7";
		temp = 7800;
		l_min = 11;
		l_max = 13;
		m_span = 1.8;
		s_span = 0.3;
		g_span = 0.2;
	}
	else if (stellar_mass == 1.90)
	{
		spectral_type = "A6";
		temp = 8000;
		l_min = 13;
		l_max = 16;
		m_span = 1.5;
		s_span = 0.2;
		g_span = 0.1;
	}
	else if (stellar_mass == 2.00)
	{
		spectral_type = "A5";
		temp = 8200;
		l_min = 16;
		l_max = 20;
		m_span = 1.3;
		s_span = 0.2;
		g_span = 0.1;
	}
	else
	{
		// SOMETHING WENT WRONG
	}
}

void Star::gen_Mass(bool garden_planet_present)
{
	if (!garden_planet_present && get_Primary() == nullptr) // standard primary star mass generator
	{
		int first_roll{ Dice::roll_D6(3) };	// store first dice output
		int second_roll{ Dice::roll_D6(3) }; // store second dice output

		// evaluate mass value
		switch (first_roll){
			case (3)	:
				if (second_roll >= 3 && second_roll <= 10)
				{
					stellar_mass = 2;
				}
				else
				{
					stellar_mass = 1.9;
				}
				break;
			case (4)	:
				if (second_roll >= 3 && second_roll <= 8)
				{
					stellar_mass = 1.8;
				}
				else if (second_roll >= 9 && second_roll <= 11)
				{
					stellar_mass = 1.7;
				}
				else
				{
					stellar_mass = 1.6;
				}
				break;
			case (5)	:
				if (second_roll >= 3 && second_roll <= 7)
				{
					stellar_mass = 1.5;
				}
				else if (second_roll >= 8 && second_roll <= 10)
				{
					stellar_mass = 1.45;
				}
				else if (second_roll >= 11 && second_roll <= 12)
				{
					stellar_mass = 1.4;
				}
				else
				{
					stellar_mass = 1.35;
				}
				break;
			case (6)	:
				if (second_roll >= 3 && second_roll <= 7)
				{
					stellar_mass = 1.3;
				}
				else if (second_roll >= 8 && second_roll <= 9)
				{
					stellar_mass = 1.25;
				}
				else if (second_roll == 10)
				{
					stellar_mass = 1.2;
				}
				else if (second_roll >= 11 && second_roll <= 12)
				{
					stellar_mass = 1.15;
				}
				else
				{
					stellar_mass = 1.1;
				}
				break;
			case (7)	:
				if (second_roll >= 3 && second_roll <= 7)
				{
					stellar_mass = 1.05;
				}
				else if (second_roll >= 8 && second_roll <= 9)
				{
					stellar_mass = 1;
				}
				else if (second_roll == 10)
				{
					stellar_mass = 0.95;
				}
				else if (second_roll >= 11 && second_roll <= 12)
				{
					stellar_mass = 0.9;
				}
				else
				{
					stellar_mass = 0.85;
				}
				break;
			case (8)	:
				if (second_roll >= 3 && second_roll <= 7)
				{
					stellar_mass = 0.8;
				}
				else if (second_roll >= 8 && second_roll <= 9)
				{
					stellar_mass = 0.75;
				}
				else if (second_roll == 10)
				{
					stellar_mass = 0.7;
				}
				else if (second_roll >= 11 && second_roll <= 12)
				{
					stellar_mass = 0.65;
				}
				else
				{
					stellar_mass = 0.6;
				}
				break;
			case (9)	:
				if (second_roll >= 3 && second_roll <= 8)
				{
					stellar_mass = 0.55;
				}
				else if (second_roll >= 9 && second_roll <= 11)
				{
					stellar_mass = 0.5;
				}
				else
				{
					stellar_mass = 0.45;
				}
				break;
			case (10)	:
				if (second_roll >= 3 && second_roll <= 8)
				{
					stellar_mass = 0.4;
				}
				else if (second_roll >= 9 && second_roll <= 11)
				{
					stellar_mass = 0.35;
				}
				else
				{
					stellar_mass = 0.3;
				}
				break;
			case (11)	:
				stellar_mass = 0.25;
				break;
			case (12)	:
				stellar_mass = 0.2;
				break;
			case (13)	:
				stellar_mass = 0.15;
				break;
			default		:
				stellar_mass = 0.1;
		}
	}

	else if (get_Primary() != nullptr && !garden_planet_present)	// companion mass generator
	{	
		int difference_roll{ Dice::roll_D6(1) - 1 };	// value to establish difference between primary and secondary
		int steps_down{ 0 };							// how many steps down mass chart (pg. 101 GURPS Space) from primary star mass
		double companion_mass;							// companion mass accumulator and final value

		if (difference_roll == 0) // same mass
		{
			stellar_mass = get_Primary()->stellar_mass;
		}
		else
		{
			steps_down = Dice::roll_D6(difference_roll);

			// calculate companion mass
			companion_mass = get_Primary()->get_Mass();
			for (int i{ 0 }; i < steps_down; ++i)
			{
				if (companion_mass >= 1.6)
				{
					companion_mass -= 0.1;
				}
				else if (companion_mass > 0.1)
				{
					companion_mass -= 0.05;
				}
			}

			stellar_mass = companion_mass;
		}
	}

	else // GARDEN PLANET NEEDED: special mass generator guarantees favorable environment for garden planet
	{

	}
}