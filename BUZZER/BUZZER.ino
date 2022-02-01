const int BUZZER= 22;

void setup() {
  pinMode (BUZZER,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(BUZZER,HIGH);
  Serial.println("BUZZER ON");
  delay(2000);
  digitalWrite(BUZZER,LOW);
  Serial.println("BUZZER OFF");
  delay(2000);
  // put your main code here, to run repeatedly:

}
