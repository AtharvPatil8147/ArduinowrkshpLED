constexpr int8_t pushButtonPin = 2;
constexpr int8_t ledPin = 3;
int count = 0;

bool stateChanged;
uint32_t prevTimeStamp = 0;

enum pushButtonStates : int8_t {
  PRESSED = 0,
  RELEASED = 1
};

volatile pushButtonStates pushButtonStatus = RELEASED;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(pushButtonPin, INPUT_PULLUP);
  attachInterrupt(0, updateState, CHANGE);
}

void updateState() {
  
  uint32_t currentTime = millis();
  pushButtonStates currentStatus = (pushButtonStates)digitalRead(pushButtonPin);
  
  //2 things
  if(currentStatus != pushButtonStatus && (currentTime - prevTimeStamp) > 20){
    pushButtonStatus = (pushButtonStates)digitalRead(pushButtonPin);
    prevTimeStamp = currentTime;
    stateChanged = true;
  }
}

void loop() {
 if (stateChanged){
  stateChanged = false;
    switch(pushButtonStatus) {
    case PRESSED:
    digitalWrite(ledPin, HIGH);
    Serial.println(++count);
    break;

    case RELEASED:
    digitalWrite(ledPin, LOW);
    break;
    }
 }
}
