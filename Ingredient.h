#pragma once
#include <string>


class ingredient {
	std::string name;
	int percentage;
public:
	//constructors
	ingredient();
	ingredient(std::string nName, int nPercentage);

	//getters
	std::string Name();
	int Percentage();
	
	//setters
	void setName(std::string nName);
	void setPercentage(int nPercentage);
};