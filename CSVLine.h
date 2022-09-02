#pragma once
#include <string>
#include <vector>
#include <sstream>

class CSVLine
{
public:
	//declare constructor
	CSVLine(std::string line);

	//accessor methods
	inline std::string get_date() { return date; };
	inline std::string get_name() { return name; };
	inline float get_amount() { return amount; };

private:
	std::string date;
	std::string name;
	float amount;
};
