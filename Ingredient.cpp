#include <string>
#include "Ingredient.h"


//constructors
ingredient::ingredient() {
	setName("");
	setPercentage(0);
}
ingredient::ingredient(std::string nName, int nPercentage) {
	setName(nName);
	setPercentage(nPercentage);
}

//getters
std::string ingredient::Name() {
	return name;
}
int ingredient::Percentage() {
	return percentage;
}
	
//setters
void ingredient::setName(std::string nName) {
	name = nName;
}
void ingredient::setPercentage(int nPercentage) {
	percentage = nPercentage;
}
