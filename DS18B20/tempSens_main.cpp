#include <iostream>
#include "tempSensor.h"

tempSensor sensor1("12345678");	
double value = 0.0;

int main() {
	
	std::cout << "nothing to do here" << std::endl;

	value = sensor1.readData();

	std::cout << "value = " << value << std::endl;

	return 0;
}




