#include <iostream>
#include <fstream>

class tempSensor{

public:
	tempSensor(std::string sensorID, std::string target);
	double readData();

private:
	
	std::string sensID;
	std::string path = "";
	std::string file_name = "w1_slave.txt";
	std::string filePath = "";
	
	double get_value_from_file();



};
