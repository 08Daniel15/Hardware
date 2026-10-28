#include <iostream>
#include "tempSensor.h"

tempSensor temp_Sensor1("28-000000bead93" , "raspi");
tempSensor temp_Sensor2("28-000000bf2dlc" , "raspi");
double value = 0.0;

int main() {
	
	std::cout << "nothing to do here" << std::endl;

	tempSens1 = temp_Sensor1.readData();
	tempSens2 = temp_Sensor2.readData();

	std::cout << "tempSens1 = " << tempSens1 << std::endl;
	std::cout << "tempSens2 = " << tempSens2 << std::endl;

	return 0;
}




