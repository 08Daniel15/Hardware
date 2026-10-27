#include "tempSensor.h"

tempSensor::tempSensor(std::string sensorID){
	sensID = sensorID;
	std::cout << sensID << std::endl;
}


double tempSensor::get_value_from_file(){
	std::cout << "nothing to do in get_value_from_file" << std::endl;
	std::string myString = "";
	std::ifstream mein_file(filePath);
	int temp = -999;
    int stelle = 0;
    std::string str_wert = "";
    float wert = 0.0;

    if (mein_file.is_open()) {
       // 2. Zeile für Zeile lesen, solange Text vorhanden ist
        while (std::getline(mein_file, myString)) {

            if (myString.find("t") != std::string::npos){

                //std::cout << myString << std::endl;
                stelle = myString.find("t=");
                //std::cout << "Stelle = " << stelle << std::endl;
                str_wert = myString.substr(stelle + 2 );
                //std::cout << "str_wert = " << str_wert << std::endl;
                wert = std::stod(str_wert) / 1000;
                std::cout << "wert = " << wert << std::endl;
            }
            
        }
        mein_file.close();

    }    
    else{
        std::cout << "Datei konnte nicht gelesen werden" << std::endl;
    }

	return wert;
}

double tempSensor::readData(){
	std::cout << "Welcome to first method" << std::endl;

	double testvariable = 0.0;

	filePath = path + file_name;

	std::cout << "File path = " << filePath << std::endl;

	testvariable = get_value_from_file();

	return testvariable;

}

