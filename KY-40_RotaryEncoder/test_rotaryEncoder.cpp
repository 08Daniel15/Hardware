#include <iostream>
#include "wiringPi.h"


 //        WiringPi // PhysPin - BCM -  Belegung
                    // 02      -         5V
const int CLC = 0;  // 11      - 17      GPIO
const int DT  = 2;  // 13      - 27      GPIO
const int SW  = 3;  // 15      - 22      GPIO

//int wiringPiSetupGpio(void);
//wiringPiSetupPinType(CLC);

// actualValues 
int int_clc = 0;
int int_dt = 0;
//int int_sw = 0;
int value = 0;
int increments = 0;

// oldValues
int int_clc_old = 0;
int int_dt_old = 0;
//int int_sw_old = 0;
int value_old = 0;


int main(void){

	std::cout << "Hallo Welt" << std::endl;
	if(wiringPiSetup() == -1){
		std::cout << "Initialisierung fehlgeschlagen" << std::endl;
		return 1;
	}

	// Pins Initialisieren
	pinMode(0,INPUT);
	pullUpDnControl(0 , PUD_DOWN);
	pinMode(2 , INPUT);
	pullUpDnControl(2,PUD_DOWN);
	//pinMode(3 , INPUT);
	//pullUpDnControl(3,PUD_DOWN);

	while(TRUE){
		//pinMode(0,INPUT);
		//pullUpDnControl(0,PUD_DOWN);
		int_clc = digitalRead(0);
		int_dt =  digitalRead(2);
		//int_sw =  digitalRead(3);

		value =int(int_clc << 1) ;
		value =int( value | int_dt);
		
		
		switch(value_old){
			
			case 0:
				//std::cout <<  "case = 0" << std::endl;
				if(value  == 2){increments = increments + 1;}	
				else if(value == 1){increments = increments -1;}
				else{increments = increments;}
				break;
			case 1:
				//std::cout << "case = 1" << std::endl;
				if(value == 0){increments = increments + 1;}
				else if(value == 3){increments = increments - 1;}
				else{increments = increments;}
				break;
			case 2:
				//std::cout << "case = 2"<< std::endl;
				if(value == 3){increments = increments + 1;}
				else if(value == 0){increments = increments - 1;}
				else{increments = increments;}
				break;
			case 3:
				//std::cout << "case = 3" << std::endl;
				if(value == 1){increments = increments + 1;}
				else if(value == 2){increments = increments -1;}
				else{increments = increments;}
				break;
			default:
				std::cout << "Default " << std::endl;
				std::cout << "Default Routine" << std::endl;
		}




		if(value != value_old){
			std::cout << int_clc << int_dt << "  value:  " << value <<  "   oldValue:  " << value_old << "  increments: " << increments <<  std::endl;
		}


		value_old = value;

						
	}


	return 0;
}

