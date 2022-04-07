#pragma once
#include <string>
#include <ctime>
#include "Producer.h"
#include "Ingredient.h"
#include <vector>

class product {
	int mass;
	std::string name;
	producer food_producer;
	int number;
	std::tm expDate;
	std::vector<ingredient> ingredients;
public:
	
	//constructors
	product();
	product(int nMass, std::string nName, producer nProducer, int nNumber, std::tm nDate, std::vector<ingredient> nIngredients);
	
	//getters
	int Mass();
	std::string Name();
	producer Producer();
	int Number();
	std::tm ExpDate();
	std::vector<ingredient> Ingredients();
	
	//setters
	void setMass(int nMass);
	void setName(std::string nName);
	void setProducer(producer nProducer);
	void setNumber(int nNumber);
	void setExpDate(std::tm nDate);
	void setIngredients(std::vector<ingredient>nIngredients);
	void addIngredient(ingredient nIngredient);
};

