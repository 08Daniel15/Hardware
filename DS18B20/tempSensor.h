#include <iostream>
#include <fstream>

class tempSensor{

public:
	tempSensor(std::string sensorID);
	double readData();

private:
	
	std::string sensID;
	std::string path = "/sys/bus/w1/devices/28-000000bead93/";
	std::string file_name = "w1_slave";
	std::string filePath = "";
	
	double get_value_from_file();



};
