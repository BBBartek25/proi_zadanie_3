#pragma once
#ifndef PROI_ZADANIE_3_INGREDIENT_H
#define PROI_ZADANIE_3_INGREDIENT_H
#include <string>


class ingredient {
	std::string name;
public:
	double percentage;
	int mass;

	//constructors
	ingredient();
	ingredient(std::string nName, int nMass, double nPercentage);

	//getters
	std::string Name() const;
	int Mass() const;
	double Percentage();
	
	//setters
	void setName(std::string nName);
	void setMass(int nMass);
	void setPercentage(double nPercentage);
	bool operator==(const ingredient& second_ingredient) const;
	bool operator!=(const ingredient& second_ingredient) const;
	bool operator<(const ingredient& second_product) const;
	bool operator>(const ingredient& second_product) const;
	bool operator>=(const ingredient& second_product) const;
	bool operator<=(const ingredient& second_product) const;
};
#endif