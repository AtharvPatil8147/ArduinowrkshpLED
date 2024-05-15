void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(4,OUTPUT);
  delay(50);
  digitalWrite(4,LOW);
  delay(50);
  digitalWrite(2,OUTPUT);
  delay(50);
  digitalWrite(2,LOW);
  delay(50);
  digitalWrite(3,OUTPUT);
  delay(50);
  digitalWrite(3,LOW);
  delay(50);
}