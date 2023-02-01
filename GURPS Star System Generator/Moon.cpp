#include "Moon.h"
#include "DICE.h"

Moon::Moon(std::string parent_type)
{
	// set size code so we can do this mathematically
	int size_code{ 0 };
	if (parent_type == "Tiny Terrestrial")
	{
		size_code = 1;
	}
	else if (parent_type == "Small Terrestrial")
	{
		size_code = 2;
	}
	else if (parent_type == "Standard Terrestrial")
	{
		size_code = 3;
	}
	else if (parent_type == "Large Terrestrial" || parent_type == "Small Gas Giant" || parent_type == "Medium Gas Giant" || parent_type == "Large Gas Giant")
	{
		size_code = 4;
	}
	int roll{ Dice::roll_D6(3) };
	if (roll <= 11)
	{
		size_code -= 3;
	}
	else if (roll >= 12 && roll <= 14)
	{
		size_code -= 2;
	}
	else if (roll >= 15)
	{
		size_code -= 1;
	}
	if (size_code <= 1)
	{
		size = "Tiny";
	}
	else if (size_code == 2)
	{
		size = "Small";
	}
	else if (size_code == 3)
	{
		size = "Standard";
	}

}

std::string Moon::get_Size() { return size; }