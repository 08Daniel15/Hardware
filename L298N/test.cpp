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

	return 0;
}



