#include <string>
#include "Producer.h"
	
//constructors


producer::producer() {
	setName("");
	setAdress("");
};
producer::producer(std::string GivenName, std::string GivenAdress) {
	setName(GivenName);
	setAdress(GivenAdress);
};
	//getters
std::string producer::Adress() {
	return adress;
};
std::string producer::Name() {
	return name;
};
	//setters
void producer::setAdress(std::string newAdress) {
	adress = newAdress;
};
void producer::setName(std::string newName) {
	name = newName;
};

// operators 
bool producer::operator==(const producer& second_produer) const {
	return name == second_produer.name && adress == second_produer.adress;
}
bool producer::operator!=(const producer& second_producer) const
{
	return !(*this == second_producer);
}

