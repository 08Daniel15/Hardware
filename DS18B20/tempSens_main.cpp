#include <iostream>
#include "tempSensor.h"


tempSensor temp_Sensor1("28-000000bead93" , "raspi");
tempSensor temp_Sensor2("28-000000bf2d1c" , "raspi");

double tempSens1 = 0.0;
double tempSens2 = 0.0;


int main() {
	
	std::cout << "########### Start main() ############" << std::endl;

	while(true){
		tempSens1 = temp_Sensor1.readData();
		std::cout << "tempSens1 = " << tempSens1 << std::endl;
	
		tempSens2 = temp_Sensor2.readData();
		std::cout << "tempSens2 = " << tempSens2 << std::endl;
	}
	return 0;
}




