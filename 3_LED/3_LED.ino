
const int LED1 = 22;
const int LED2 = 15;
const int LED3 = 17;
void setup() 
{
  pinMode (LED1,OUTPUT);
  pinMode (LED2,OUTPUT);
  pinMode (LED3,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() 
{
  digitalWrite(LED1,HIGH);
  Serial.println("LED1 ON");
  delay(2000);
  digitalWrite(LED1,LOW);
  Serial.println("LED1 OFF");
  delay(2000);
  
  digitalWrite(LED2,HIGH); 
  Serial.println("LED2 ON");
  delay(2000);
  digitalWrite(LED2,LOW);
  Serial.println("LED2 OFF");
  delay(2000);

  digitalWrite(LED3,HIGH); 
  Serial.println("LED3 ON");
  delay(2000);
  digitalWrite(LED3,LOW);
  Serial.println("LED3 OFF");
  delay(2000); 
}
