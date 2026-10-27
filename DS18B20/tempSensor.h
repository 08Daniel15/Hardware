#include <iostream>
#include <fstream>

class tempSensor{

public:
	tempSensor(std::string sensorID);
	double readData();

private:
	
	std::string sensID;
	std::string path = "/home/daniel/Documents/git/Hardware/DS18B20/";
	std::string file_name = "testFile.txt";
	std::string filePath = "";
	
	double get_value_from_file();



};
