#pragma once
#ifndef PROI_ZADANIE_3_PRODUCT_H
#define PROI_ZADANIE_3_PRODUCT_H
//#include <ctime>
#include "Producer.h"
#include "Ingredient.h"
#include <string>
#include <vector>

class product {
	int mass;
	std::string name;
	producer foodProducer;
	int number;
	//std::tm expDate;
	std::vector<ingredient> ingredients;
public:
	
	//constructors
	product();
	product(int nMass, std::string nName, producer nProducer, int nNumber, std::vector<ingredient> nIngredients);
	
	//getters
	int Mass();
	std::string Name();
	producer Producer();
	int Number();
	std::vector<ingredient> Ingredients();
	
	//setters
	void setMass(int nMass);
	void setName(std::string nName);
	void setProducer(producer nProducer);
	void setNumber(int nNumber);
	void setIngredients(std::vector<ingredient>nIngredients);
	
	//other
	void addIngredient(ingredient nIngredient);
	void removeIngredient(ingredient rIngredient);
	bool findIngredient (const ingredient nIngredient) const;
	void updateMass();
	void updatePercentage();
	std::string listIngredients();
	void sortByMass();
	int countFromValue(int x);
	//operators
	bool operator==(const product& second_product) const;
	bool operator!=(const product& second_product) const;
	bool operator<(const product& second_product) const;
	bool operator>(const product& second_product) const;
	bool operator>=(const product& second_product) const;
	bool operator<=(const product& second_product) const;
	friend std::ostream& operator<<(std::ostream& os, product& prod);
};

#endif