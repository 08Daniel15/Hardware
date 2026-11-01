# L298N

Wiring pi Repository klonen.  
> git clone https://github.com/WiringPi/WiringPi.git  
Anschließend in das Repository wechseln
> WiringPi  
Den Code compilieren und Bibliothek installieren  
> ./build  
Pruefen ob die Installation funktioniert hat  
> gpio -v  
Die Bibliothek wird hier Lokal installiert.  
> /usr/local/lib/libwiringPi.so  



Im Code wird die Funktionalitaet wie folgt eingebunden
> #include <stdio.h>  
> #include <wiringPi.h>   
  





Wenn Code die WiringPi Bibliothek enthaelt muss wie folgt compiliert werden
> g++ test.cpp -o test -lwiringPi

