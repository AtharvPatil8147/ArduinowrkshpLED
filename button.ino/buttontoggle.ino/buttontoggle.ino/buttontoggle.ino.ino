constexpr int8_t button=2;
constexpr int8_t led=3;

enum pushButtonStates: int8_t{
  PRESSED=0,
  RELEASED=1
  // TOGGLE=0
};

pushButtonStates pushButtonStatus=RELEASED;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(button,INPUT_PULLUP);
}

void loop() {
  pushButtonStatus=digitalRead(button);
  delay(100);
  switch(pushButtonStatus){
    case RELEASED:
        Serial.println("RELEASED");
    break;

    case PRESSED:
        Serial.println("PRESSESD");
        digitalWrite(led,!digitalRead(led));
    break;

  }

}
