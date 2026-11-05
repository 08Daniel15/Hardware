
#include <iostream>
#include <wiringPi.h>
#include <chrono>
#include <thread>

// GPIO-Belegung (BCM)
#define ENA 18
#define IN1 23
#define IN2 24

int main()
{
    // WiringPi initialisieren
    if (wiringPiSetupGpio() == -1)
    {
        std::cout << "Fehler beim Initialisieren!" << std::endl;
        return 1;
    }

    std::cout << "WiringPi erfolgreich initialisiert" << std::endl;

    // PWM konfigurieren
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(1024);
    pwmSetClock(32);

    // GPIO konfigurieren
    pinMode(ENA, PWM_OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    // Drehrichtung festlegen
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    int pwm = 0;

    // Motor starten und Geschwindigkeit erhöhen
    while (true)
    {
        // PWM-Signal ausgeben
        pwmWrite(ENA, pwm);

        std::cout << "PWM = " << pwm
                  << " / 1023" << std::endl;

        // 3 Sekunden warten
        std::this_thread::sleep_for(
            std::chrono::seconds(3)
        );

        // PWM um 256 erhöhen
        pwm += 256;

        // Bei maximalem Wert wieder auf 0 setzen
        if (pwm > 1023)
        {
            pwm = 0;
        }
    }

    return 0;
}

