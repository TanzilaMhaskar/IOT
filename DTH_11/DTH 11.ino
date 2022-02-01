
#include "DHT.h"

#define DHTPIN 23     // Digital pin connected to the DHT sensor


#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
const int gled = 15;
const int bled = 16;
const int rled = 17;

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT11"));
  pinMode(gled,OUTPUT);
  pinMode(bled,OUTPUT);
  pinMode(rled,OUTPUT);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

 

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  //Serial.print(f);
  
  if(t >= 20 && t <= 30)
  {
    digitalWrite (gled,1);
    Serial.println( "\n GREEN LED IS ON  Temperature(20 to 30)\n");
  }
  else if (t >= 31 && t <= 40)
  {
   digitalWrite (bled,1); 
   Serial.println( "\nBLUE LED IS ON  Temperature(31 to 40)\n") ;
  }
  else if (t >= 41 && t <= 50)
  {
   digitalWrite (rled,1); 
   Serial.println( "\nRED LED IS ON Temperature(41 to 50)\n") ;
  }

}
