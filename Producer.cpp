#include <string>

class producer {
	std::string name;
	std::string adress;
public:
	producer() {
		setName("");
		setAdress("");
	}
	producer(std::string GivenName, std::string GivenAdress) {
		setName(GivenName);
		setAdress(GivenAdress);
	}
	std::string Adress() {
		return adress;
	}
	std::string Name() {
		return name;
	}
	void setAdress(std::string newAdress) {
		adress = newAdress;
	}
	void setName(std::string newName) {
		name = newName;
	}
};