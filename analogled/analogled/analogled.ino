constexpr int8_t ledPin=3;
int i;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0;i<256;i++)
  {
    analogWrite(ledPin,i);
    delay(1);
  }
    
  for(i;i>=0;i--)
  {
    analogWrite(ledPin,i);
    delay(1);
  }
}
