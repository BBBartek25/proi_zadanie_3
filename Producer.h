#pragma once
#include <string>

class producer {
	std::string name;
	std::string adress;
public:
	
	//constructors
	producer();
	producer(std::string GivenName, std::string GivenAdress);
	
	//getters
	std::string Adress();
	std::string Name();
	
	//setters
	void setAdress(std::string newAdress);
	void setName(std::string newName);
};