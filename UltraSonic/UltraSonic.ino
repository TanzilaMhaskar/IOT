
#include "ThingSpeak.h"
#include "WiFi.h"

//-------Enter your WiFi Details------//
char ssid[] = "AIM";  //SSID
char pass[] = "husna8412";  //Password
//-----------------------------------//

//-------------ThingSpeak Details-----------------//
unsigned long myChannelField = 1644807; 
const int ChannelField= 3; 
const char * myWriteAPIKey = "H9JCORYB52VXT07I"; //Your Write API Key
//-----------------------------------------------//
 
const int trigger = 22;
const int echo = 23;
long T;
float distanceCM;
WiFiClient client;

void setup() {
Serial.begin(115200);
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
WiFi.mode(WIFI_STA);
ThingSpeak.begin(client);

}

void loop() 
{
  //-----------------WiFi Setup-------------------//
  if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("Attempting to Connect to SSID: ");
    Serial.println(ssid);
  
  while(WiFi.status()!= WL_CONNECTED)
  {
    WiFi.begin(ssid,pass);
    Serial.print(".");
    delay(5000);
  }
  Serial.println("\nConnected.");
  }
  digitalWrite(trigger,LOW);
  delay(1);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  T = pulseIn(echo,HIGH);
  distanceCM = (T * 0.034)/2;
  Serial.print("\nDistance in cm: ");
  Serial.print(distanceCM);
  Serial.print("\nT=");
  Serial.print(T);
 
  ThingSpeak.writeField(myChannelField,ChannelField,distanceCM, myWriteAPIKey);
  delay(1000);
}
