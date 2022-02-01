const int LED1 = 22;

void setup() {
  pinMode (LED1,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(LED1,HIGH);
  Serial.println("LED1 ON");
  delay(2000);
  digitalWrite(LED1,LOW);
  Serial.println("LED1 OFF");
  delay(2000);
  // put your main code here, to run repeatedly:

}
