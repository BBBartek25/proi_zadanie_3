#include <string>
#include <ctime>
#include "Producer.cpp"
#include "Ingredient.cpp"
#include <vector>
class product {
	int mass;
	std::string name;
	producer food_producer;
	int number;
	std::tm expDate;
	std::vector<ingredient> ingredients;
public:
	int Mass() {
		return mass;
	}
	std::string Name() {
		return name;
	}
	producer Producer() {
		return food_producer;
	}
	int Number() {
		return number;
	}
	std::tm ExpDate() {
		return expDate;
	}
	std::vector<ingredient> Ingredients() {
		return ingredients;
	}
	void setMass(int nMass) {
		mass = nMass;
	}
	void setName(std::string nName) {
		name = nName;
	}
	void setProducer(producer nProducer) {
		food_producer = nProducer;
	}
	void setNumber(int nNumber) {
		number = nNumber;
	}

};

