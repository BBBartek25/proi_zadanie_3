#include <string>


class ingredient {
	std::string name;
	int percentage;
public:
	std::string Name() {
		return name;
	}
	int Percentage() {
		return percentage;
	}
	void setName(std::string nName) {
		name = nName;
	}
	void setPercentage(int nPercentage) {
		percentage = nPercentage;
	}
};