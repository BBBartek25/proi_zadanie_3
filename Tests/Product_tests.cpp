#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Product.h"
#include "../Ingredient.h"
#include "../Producer.h"
#include <string>
#include <vector>
#include <stdexcept>

TEST_CASE("checking class Producer", "[producer]") {
	producer producer1;
	producer producer2("producent2", "ul. Losowa 12");
	producer producer2v2("producent2", "ul. Losowa 12");

	CHECK(producer1.Name() == "");
	CHECK(producer1.Adress() == "");
	CHECK(producer2.Name() == "producent2");
	CHECK(producer2.Adress() == "ul. Losowa 12");
	CHECK(producer2 == producer2v2);
	CHECK(producer1 != producer2);

	SECTION("setting atributes of producers") {
		int a = 25;
		producer1.setName("producent1");
		producer1.setAdress("ul. Mila 5");
		CHECK(producer1.Name() == "producent1");
		CHECK(producer1.Adress() == "ul. Mila 5");
		producer2.setAdress("ul. Kolorowa 5");
		producer2.setName("color");
		CHECK(producer2.Name() == "color");
		CHECK(producer2.Adress() == "ul. Kolorowa 5");
	}
};


TEST_CASE("checking class Ingredient", "[ingredient") {

	ingredient tea;
	ingredient eggs("eggs", 50, 0);
	ingredient tomatoe("tomatoe", 25, 0);
	ingredient beans("beans", 25, 0);
	ingredient ham("ham", 20, 0);
	ingredient ham2("ham", 20, 0);
	CHECK(eggs.Name() == "eggs");
	CHECK(tomatoe.Mass() == 25);
	CHECK(beans.Percentage() == 0);
	CHECK(tea.Name() == "");
	CHECK(tea.Mass() == 0);
	CHECK(tea.Percentage() == 0);
	SECTION("checking changing and comparing ingredients") {
		ham.setPercentage(25);
		CHECK(ham.Percentage() == 25);
		beans.setMass(12);
		CHECK(beans.Mass() == 12);
		CHECK(ham.Name() == "ham");
		CHECK(eggs > tomatoe);
		CHECK(tea < beans);
		CHECK(ham <= tomatoe);
		CHECK(ham == ham2);
		CHECK(ham != beans);
	}
};


TEST_CASE("checking class Product", "[product]")
{
	producer none;
	producer producer1;
	ingredient eggs("eggs", 50, 0);
	ingredient tomatoe("tomatoe", 26, 0);
	ingredient beans("beans", 24, 0);
	ingredient ham("ham", 20, 0);
	ingredient cheese;
	ingredient sauce;
	std::vector<ingredient> empty;
	std::vector<ingredient> random = { tomatoe, eggs, beans };
	std::vector<ingredient> randomRising = { beans, tomatoe, eggs };
	std::vector<ingredient> random1 = { tomatoe, beans, ham };
	std::vector<ingredient> random2 = { tomatoe, eggs, beans, ham };
	product product1;
	product product2(25, "ketchup", producer1, 23456, random);
	product product3(0, "spaghetti", none, 1234, random2);

	CHECK(product1.Name() == "");
	CHECK(product1.Mass() == 0);
	CHECK(product1.Producer() == none);
	CHECK(product1.Number() == 0);
	CHECK(product1.Ingredients() == empty);
	product1.setIngredients(random1);
	CHECK(product1.Ingredients() == random1);
	CHECK(product2.Name() == "ketchup");
	CHECK(product2.Mass() == 100);
	CHECK(product2.Producer() == producer1);
	CHECK(product2.Number() == 23456);
	CHECK(product2.Ingredients() == random );
	product2.sortByMass();
	CHECK(product2.Ingredients() == randomRising);
	CHECK(product1 < product2);
	CHECK(product3 > product1);
	


	SECTION("creating product and changing its data") {
		CHECK(product2.findIngredient(ham) == false);
		CHECK(product2.findIngredient(tomatoe) == true);
		product2.addIngredient(cheese);
		CHECK(product2.findIngredient(cheese) == true);
		CHECK(product2.findIngredient(beans) == true);
		product2.removeIngredient(beans);
		CHECK(product2.findIngredient(beans) == false);
		product2.removeIngredient(sauce);
		CHECK(product2.findIngredient(sauce) == false);
	}
};

