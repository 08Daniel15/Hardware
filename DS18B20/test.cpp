#include <iostream>
#include <fstream>

std::string myString = "Halli Hallo";

int main(){

    std::cout << "Hallo Welt" << std::endl;
    std::cout << "myString = " << myString << std::endl;
    
    myString = "";

    std::ifstream mein_file("testFile.txt");
    
    int temp = -999;
    int stelle = 0;
    std::string str_wert = "";
    float wert = 0.0;
    
    if (mein_file.is_open()) {
       // 2. Zeile für Zeile lesen, solange Text vorhanden ist
        while (std::getline(mein_file, myString)) {

            if (myString.find("t") != std::string::npos){

                std::cout << myString << std::endl;
                stelle = myString.find("t=");
                std::cout << "Stelle = " << stelle << std::endl;
                str_wert = myString.substr(stelle + 2 );
                std::cout << "str_wert = " << str_wert << std::endl;
                wert = std::stod(str_wert) / 1000;
                std::cout << "wert = " << wert << std::endl;
            }
            
        }
        mein_file.close();

    }    
    else{
        std::cout << "Datei konnte nicht gelesen werden" << std::endl;
    }
        
    
    
    
    return 0;


}