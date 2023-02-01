#pragma once

#include <string>

class Moon
{
private:
	std::string size{ "" };

public:
	Moon();

	// OUTPUTS
	std::string get_Size();
};