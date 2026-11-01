#include <iostream>
#include <stdio.h>
#include <wiringPi.h>

int test = 1;


int main()
{
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
	
	while(1)
	{
		digitalWrite(17,HIGH);
		std::cout << "HIGH" << std::endl;
		delay(5000);
		digitalWrite(17,LOW);
		std::cout << "LOW" << std::endl;
		delay(5000);
	}

	return 0;
}



