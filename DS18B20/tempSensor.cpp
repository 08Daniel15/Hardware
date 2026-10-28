#include "tempSensor.h"

tempSensor::tempSensor(std::string sensorID, std::string target){
	sensID = sensorID;
	
    std::cout << "Sensor target mode =  " << target << std::endl;

    if(target == "raspi"){
        filePath = "/sys/bus/w1/devices/" + sensorID + "/" + "w1_slave";
 
        std::cout << filePath << std::endl;
    }
    else if (target == "simulation"){
        path = "/";
        filePath = path + file_name;
    }
    else{
        std::cout << "no valid target" << std::endl;
    }

    std::cout << "Sensor ID = " << sensID << "   File path = " << filePath << std::endl;

}


double tempSensor::get_value_from_file(){

	std::string myString = "";
    std::string str_wert = "";
    int temp = -999;
    int stelle = 0;
    float wert = 0.0;

    std::cout << filePath << std::endl;

	std::ifstream mein_file(filePath);
    

    if (mein_file.is_open()) {
       // 2. Zeile für Zeile lesen, solange Text vorhanden ist
        while (std::getline(mein_file, myString)) {

            if (myString.find("t") != std::string::npos){

                
                stelle = myString.find("t=");                   // Index an welcher Stelle "t" steht
                str_wert = myString.substr(stelle + 2 );        // Index + die beiden character Stellen (t=)
                
                wert = std::stod(str_wert) / 1000;
                
            }
            
        }
        mein_file.close();

    }    
    else{
        std::cout << "Datei konnte nicht gelesen werden" << std::endl;
        wert = -999;
    }

	return wert;
}

double tempSensor::readData(){

	double testvariable = 0.0;

	testvariable = get_value_from_file();

	return testvariable;

}

