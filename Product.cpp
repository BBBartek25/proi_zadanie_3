#include "Product.h"
#include "Producer.h"
#include "Ingredient.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

//constructors
product::product() {
	std::vector<ingredient> a;
	producer none;
	setMass(0);
	setName("");
	setProducer(none);
	setNumber(0);
	setIngredients(a);
}

product::product(int nMass, std::string nName, producer nProducer, int nNumber, std::vector<ingredient> nIngredients) {
	setIngredients(nIngredients);
	setName(nName);
	setProducer(nProducer);
	setNumber(nNumber);
	updateMass();
	updatePercentage();
}

//getters
int product::Mass() {
	return mass;
}
std::string product::Name() {
	return name;
}
producer product::Producer() {
	return foodProducer;
}
int product::Number() {
	return number;
}
//std::tm product::ExpDate() {
//	return expDate;
//}
std::vector<ingredient> product::Ingredients() {
	return ingredients;
}

//setters
void product::setMass(int nMass) {
	mass = nMass;
};

void product::setName(std::string nName) {
	name = nName;
};

void product::setProducer(producer nProducer) {
	foodProducer = nProducer;
};

void product::setNumber(int nNumber) {
	number = nNumber;
};

void product::setIngredients(std::vector<ingredient>nIngredients) {
	ingredients = nIngredients;
	updateMass();
};

//others

bool product::findIngredient( const ingredient nIngredient) const {
	return(find(ingredients.begin(), ingredients.end(), nIngredient) != ingredients.end());
};

void product::addIngredient(ingredient nIngredient) {
	if (findIngredient(nIngredient) == false)
		ingredients.push_back(nIngredient);
	updateMass();
	updatePercentage();
};
void product::removeIngredient(ingredient rIngredient) {
	if (findIngredient(rIngredient)) {
		ingredients.erase(remove(ingredients.begin(), ingredients.end(), rIngredient), ingredients.end());
	};
}
void product::updateMass() {
	int x = 0;
	for (ingredient y : Ingredients())
		x += y.Mass();
	setMass(x);
};

void product::updatePercentage() {
	updateMass();
	for (auto &ing : this->ingredients) {
		double y;
		double a = Mass();
		double b = ing.Mass();
		y = ((b / a) * 100);
		ing.setPercentage(y);
	}
};

std::string product::listIngredients() {
	std::string x;
	updatePercentage();
	for (auto &ing : this->ingredients) {
		x += ing.Name();
		x += "			";
		x += std::to_string(ing.Mass());
		x += "			";
		x += std::to_string(ing.Percentage());
		x += "%";
		x += "\n";
	};
	return x;
};

void product::sortByMass() {
	std::sort(ingredients.begin(), ingredients.end());
}

int product::countFromValue(int x) {
	int num = std::count_if(ingredients.begin(), ingredients.end(), [x](ingredient ing)->bool {return ing.Mass() > x; });
	return num;
}

std::ostream& operator<<(std::ostream& os, product& prod) {
	os << prod.Name() << "\nMass: " << prod.Mass() << "\nProduced by: "
		<< prod.Producer().Name() << "	" << prod.Producer().Adress()
		<< "\nNumber: " << prod.Number() << "\nIngredients: \n"<< prod.listIngredients();
	return os;
}

bool product::operator==(const product& second_product) const{
	return name == second_product.name && mass == second_product.mass
		&& foodProducer == second_product.foodProducer && number == second_product.number
		&& ingredients == second_product.ingredients;
}
bool product::operator!=(const product& second_product) const {
	return !(*this == second_product);
}
bool product::operator<(const product& second_product) const {
	return (mass < second_product.mass);
}
bool product::operator>(const product& second_product) const {
	return (mass > second_product.mass);
}
bool product::operator>=(const product& second_product) const {
	return (mass >= second_product.mass);
}
bool product::operator<=(const product& second_product) const {
	return (mass <= second_product.mass);
}
