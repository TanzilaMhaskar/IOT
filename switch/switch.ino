const int buzz = 15;
const int sw = 22;
int val;
void setup() {
  pinMode (buzz,OUTPUT);
  pinMode (sw,INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
val = digitalRead(sw);
if(val ==1)
{
  digitalWrite(buzz,1);
  Serial.println("Buzzer on for 5 sec");
  delay(5000);
}
else
{
  digitalWrite(buzz,0);
  Serial.println("Buzzer off");
  delay(500);
  // put your main code here, to run repeatedly:
}
}

