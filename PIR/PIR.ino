#include "ThingSpeak.h"
#include "WiFi.h"

//-------Enter your WiFi Details------//
char ssid[] = "AIM";  //SSID
char pass[] = "husna8412";  //Password
//-----------------------------------//

//-------------ThingSpeak Details-----------------//
unsigned long myChannelField = 1646364; 
const int ChannelField1= 1;
const int ChannelField2= 2;
const char * myWriteAPIKey = "LI5XLSQSCF8OGSZ2"; //Your Write API Key
//-----------------------------------------------//
int led = 22; 
int PIR = 23; 
int pirState = LOW; // we start, assuming no motion detected
int val = 0; // variable for reading the pin status
int count =0;
int led_status =0;
WiFiClient client;
void setup() {
pinMode(led, OUTPUT); // declare LED as output
pinMode(PIR, INPUT); // declare sensor as input
Serial.begin(115200);
WiFi.mode(WIFI_STA);
ThingSpeak.begin(client);
}
void loop(){
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
val = digitalRead(PIR); // read input value
if (val == HIGH) 
{ 
digitalWrite(led, HIGH); // turn LED ON
if (pirState == LOW) {
Serial.println("Motion detected!");
count ++;
led_status=1;
pirState = HIGH;
}
} else {
digitalWrite(led, LOW); // turn LED OFF
if (pirState == HIGH){
Serial.println("Motion ended!");
led_status=0;
pirState = LOW;
}
}

ThingSpeak.writeField(myChannelField,ChannelField1,count, myWriteAPIKey);
ThingSpeak.writeField(myChannelField,ChannelField2,led_status, myWriteAPIKey);
}
