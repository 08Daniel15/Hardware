#include <iostream>
#include <stdio.h>
#include <wiringPi.h>
#include <chrono>
#include <thread>



// Pin 12 und 18 sind ein PWM Kanal



int test = 1;
std::string mode = "";
int pwm = 0;

//pinMode (18,PWM_OUTPUT) ;

int main()
{
	//pinMode(18,PWM_OUTPUT);	
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

	pinMode(18,PWM_OUTPUT);
	pinMode(17,OUTPUT);
	
	if(mode == "h")	
	{
		pwm = 200;
		while(1)
		{
			//digitalWrite(17,HIGH);
			//std::cout << "HIGH" << std::endl;
			//delay(5000);
			//std::this_thread::sleep_for(std::chrono::seconds(5));
			//digitalWrite(17,LOW);
			//std::cout << "LOW" << std::endl;
			//delay(5000);
			std::this_thread::sleep_for(std::chrono::seconds(3));
			pwm = pwm + 200;

			pwmWrite(12,pwm);
			std::cout << "PWM = " <<  pwm << std::endl;

			if(pwm >1024)
			{
				pwm = 0;
			}
			else if(pwm <0)
			{
				pwm = 0;
			}
			else
			{
				pwm = pwm;
			}


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
