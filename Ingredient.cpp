#include <string>
#include "Ingredient.h"


//constructors
ingredient::ingredient() {
	setName("");
	setMass(0);
	setPercentage(0);
};
ingredient::ingredient(std::string nName, int nMass, double nPercentage) {
	setName(nName);
	setMass(nMass);
	setPercentage(nPercentage);
};

//getters
std::string ingredient::Name() const {
	return name;
};
int ingredient::Mass() const {
	return mass;
};
double ingredient::Percentage() {
	return percentage;
};
	
//setters
void ingredient::setName(std::string nName) {
	name = nName;
};
void ingredient::setMass(int nMass) {
	mass = nMass;
};
void ingredient::setPercentage(double nPercentage) {
	percentage = nPercentage;
};

//operators
bool ingredient::operator==(const ingredient& second_ingredient) const
{
	return name == second_ingredient.name && mass == second_ingredient.mass;
}
bool ingredient::operator!=(const ingredient& second_argument) const
{
	return !(*this == second_argument);
}
bool ingredient::operator<(const ingredient& second_product) const {
	return (mass < second_product.mass);
}
//bool ingredient::operator<(const ingredient& second_product) const {
//	return (name < second_product.name);
//}
bool ingredient::operator>(const ingredient& second_product) const {
	return (mass > second_product.mass);
}
//bool ingredient::operator>(const ingredient& second_product) const {
//	return (name > second_product.name);
//}
bool ingredient::operator>=(const ingredient& second_product) const {
	return (mass >= second_product.mass);
}
//bool ingredient::operator>=(const ingredient& second_product) const {
//	return (name >= second_product.name);
//}
bool ingredient::operator<=(const ingredient& second_product) const {
	return (mass <= second_product.mass);
}
//bool ingredient::operator<=(const ingredient& second_product) const {
//	return (name <= second_product.name);
//}


