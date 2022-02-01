const int LED1 = 15;
const int ldr = 22;
int val;
void setup() {
  pinMode (LED1,OUTPUT);
  pinMode (ldr,INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
val = digitalRead(ldr);
if(val ==1)
{
  digitalWrite(LED1,HIGH);
  Serial.println("LED1 ON");
  delay(500);
}
else
{
  digitalWrite(LED1,LOW);
  Serial.println("LED1 OFF");
  delay(500);
  // put your main code here, to run repeatedly:
}
}

