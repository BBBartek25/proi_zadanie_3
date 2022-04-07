#include <string>
#include <ctime>
#include "Product.h"
#include "Producer.h"
#include "Ingredient.h"
#include <vector>

//constructors
product::product() {
	std::tm NoTime;
	producer none;
	mass = 0;
	name = "";
	food_producer = none;
	number = 0;
	expDate = NoTime;
	ingredients = {};
}
product::product(int nMass, std::string nName, producer nProducer, int nNumber, std::tm nDate, std::vector<ingredient> nIngredients) {
	setMass(nMass);
	setName(nName);
	setProducer(nProducer);
	setNumber(nNumber);
	setExpDate(nDate);
	setIngredients(nIngredients);
}

//getters
int product::Mass() {
	return mass;
}
std::string product::Name() {
	return name;
}
producer product::Producer() {
	return food_producer;
}
int product::Number() {
	return number;
}
std::tm product::ExpDate() {
	return expDate;
}
std::vector<ingredient> product::Ingredients() {
	return ingredients;
}

//setters
void product::setMass(int nMass) {
	mass = nMass;
}
void product::setName(std::string nName) {
	name = nName;
}
void product::setProducer(producer nProducer) {
	food_producer = nProducer;
}
void product::setNumber(int nNumber) {
	number = nNumber;
}
void product::setExpDate(std::tm nDate) {
	expDate = nDate;
}
void product::setIngredients(std::vector<ingredient>nIngredients) {
	ingredients = nIngredients;
}

//others
void product::addIngredient(ingredient nIngredient) {
	ingredients.push_back(nIngredient);
}

