constexpr int8_t redled=2;
constexpr int8_t yellowled=3;
constexpr int8_t greenled=4;

enum ledStates : int8_t{
  STOP,
  READY_TO_GO,
  GO,
  READY_TO_STOP
};

ledStates status=STOP;

void setup() {
  Serial.begin(9600);
  pinMode(redled,OUTPUT);
  pinMode(yellowled,OUTPUT);
  pinMode(greenled,OUTPUT);
}

void stop(){
  digitalWrite(redled,HIGH);
  digitalWrite(yellowled,LOW);
  digitalWrite(greenled,LOW);
  delay(4000);
}

void readyToGo(){
  digitalWrite(redled,HIGH);
  digitalWrite(yellowled,HIGH);
  digitalWrite(greenled,LOW);
  delay(1000);
}

void go(){
  digitalWrite(redled,LOW);
  digitalWrite(yellowled,LOW);
  digitalWrite(greenled,HIGH);
  delay(5000);
}

void readyToStop(){
  digitalWrite(redled,LOW);
  digitalWrite(yellowled,HIGH);
  digitalWrite(greenled,HIGH);
  delay(1000);
}

void loop() {
  switch(status){
    case STOP:
      stop();
      status=READY_TO_GO;
    break;

    case READY_TO_GO:
      readyToGo();
      status=GO;
    break;

    case GO:
      go();
      status=READY_TO_STOP;
    break;

    case READY_TO_STOP:
      readyToGo();
      status=STOP;
    break;
  }

}
