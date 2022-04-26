#include "Ingredient.h"
#include "Producer.h"
#include "Product.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


void readFromFile(std::string fileName) {
	std::ifstream infile("plik.txt");
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		std::string name, producerName, ingredientName, producerAdress;
		int mass, number, ingredientMass;
		if (!(iss >> number >> name >> mass >> producerName >> producerAdress >> ingredientName >> ingredientMass))
			break;
		product p;
		p.setName(name);
		p.setMass(mass);
		p.setNumber(number);
		producer prod;
		prod.setName(producerName);
		prod.setAdress(producerAdress);
		p.setProducer(prod);
		ingredient ing;
		ing.setName(ingredientName);
		ing.setMass(ingredientMass);
		p.addIngredient(ing);
		std::cout << p << std::endl;

	}
}
int main() {

	readFromFile("plik.txt");
	producer producer1("drutex sp z o.o.", "ul.zamkowa, warszawa");
	ingredient bia³ko("bia³ko", 25, 0);
	ingredient wêglowodany("wêglowodany", 12, 0);
	ingredient przecier("przecier", 24, 0);
	std::vector<ingredient> random = {  wêglowodany, bia³ko, przecier };
	product product1(0, "product 1", producer1, 23456, random);
	product1.sortByMass();
	std::cout << product1 << std::endl;
	std::cout << product1.countFromValue(20) << std::endl;

	ingredient eggs("eggs", 50, 0);
	ingredient tomatoe("tomatoe", 25, 0);
	ingredient beens("beens", 25, 0);
	ingredient ham("ham", 20, 0);
	std::vector<ingredient> empty;
	std::vector<ingredient> random2 = { tomatoe, eggs, beens };
	product product2(25, "ketchup", producer1, 23456, random2);
	product2.updatePercentage();
	std::cout << product2 << std::endl;
	return 0;

}
