#include <iostream>
#include <stdio.h>
#include <wiringPi.h>
#include <chrono>
#include <thread>



int test = 1;
std::string mode = "";

int main()
{
	
	std::cout << "Waehle Modus Simulation/Hardware   [s|h]" << std::endl;
	std::cin >> mode;
	std::cout << std::endl;


	std::cout << test << std::endl;
	test = test + 1;

	if(wiringPiSetupGpio() == -1)
	{
		std::cout << "Fehler beim Initialisieren" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "WiringPi erfolgreich initialisiert" << std::endl;

	}


	pinMode(17,OUTPUT);
	
	if(mode == "h")	
	{
		while(1)
		{
			digitalWrite(17,HIGH);
			std::cout << "HIGH" << std::endl;
			//delay(5000);
			std::this_thread::sleep_for(std::chrono::seconds(5));
			digitalWrite(17,LOW);
			std::cout << "LOW" << std::endl;
			//delay(5000);
			std::this_thread::sleep_for(std::chrono::seconds(5));
		}
	}
	else if(mode == "s")
	{
		while(1)
		{
			std::cout << "High" << std::endl;
			//delay(5000);
			std::this_thread::sleep_for(std::chrono::seconds(5));
			std::cout << "Low" << std::endl;
			//delay(5000);
			std::this_thread::sleep_for(std::chrono::seconds(5));
		}
	}
	else
	{
		std::cout << "Nothing to do here" << std::endl;	
	}

	return 0;
}



