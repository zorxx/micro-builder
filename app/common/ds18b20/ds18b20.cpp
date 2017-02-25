#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // start serial port
  Serial.begin(115200);
  // Start up the library
  sensors.begin();
}

void loop(void)
{ 
  // 9 bit resolution by default 
  // Note the programmer is responsible for the right delay
  // we could do something usefull here instead of the delay
  int resolution = 9;
  delay(750/ (1 << (12-resolution)));
  sensors.requestTemperatures();
  
  // get temperature
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print(", ");
  Serial.print(sensors.getTempCByIndex(1));
  Serial.println("");  
}
