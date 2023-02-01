#pragma once

#include <string>

class Moon
{
private:
	std::string size{ "" };

public:
	Moon(std::string parent_type);

	// OUTPUTS
	std::string get_Size();
};