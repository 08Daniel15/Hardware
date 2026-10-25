# DS18B20


## Anschluss
Der DS18B20 wird mit 3,3V betrieben. 
- PIN-1 3,3V
- PIN-6 GND
- PIN-7 1-Wire 
Zwischen der Datenleitung und SPannungsversorgung und Datenleitung geschaltet werden.




## Raspberry Pi Einstellungen
Um 1-Wire nutzen zu koennen muss zunaechst 1-Wire aktiviert werden.
Ob die Einstellung bereits getaetigt ist kann wie folgt geprueft werden.  
>ls -l /sys/bus/w1/devices  
Sollte 1-Wire noch nicht aktiviert sein, kann dies wie folgt aktiviert werden.  
>sudo nanao boot/firmware/config.txt  
Dort die folgende Zeile hinzufuegen:  
>dtoverlay=w1-gpio  

Anschliessend muss der Pi neu gestartet werden. 

Nun kann erneut ueberprueft werden. 
Der Sensorwert kann direkt aus der Datei gelesen werden
> cat /sys/bus/w1/devices/28-xxxxxxxxxxxx/w1_slave

Als naechstes kann es sein, dass der w1-Bus mit dem GPIO verbunden werden muss.
Zudem ermoeglicht es Linux die Datenleitung ueber den GPIO anzusteuern und auszulesen.
Dies macht der folgende Befehl.  
> sudo modprobe w1-gpio  
Anschliessend muss der Treiber fuer den Sensor geladen werden. 
Die geschieht durch:  
> sudo modprobe w1-therm


Das 1-Wire Protokoll wird ueber den GPIO4 betrieben.
