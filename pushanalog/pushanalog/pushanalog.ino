constexpr int8_t button=2;
constexpr int8_t led=3;

enum brightness:int8_t{
  ZERO_PERCENT=0,
  TWENTY_PERCENT=1,
  FORTY_PERCENT=2,
  SIXTY_PERCENT=3,
  EIGHTY_PERCENT=4,
  HUNDRED_PERCENT=5
};

brightness status=ZERO_PERCENT;

enum buttonStates:int8_t{
  PRESSED=0,
  RELEASED=1
};

buttonStates buttonStatus=RELEASED;

void setup() {
  Serial.begin(9600);
  pinMode(button,INPUT_PULLUP);
  pinMode(led,OUTPUT);
}

void loop() {
  buttonStatus=(buttonStates)digitalRead(button);

  switch(buttonStatus){
    delay(100);

    case PRESSED:{
      
      if ((brightness)status==ZERO_PERCENT){
        status=TWENTY_PERCENT;
        Serial.println("20%");
        break;
      }

      else if ((brightness)status==TWENTY_PERCENT){
        status=FORTY_PERCENT;
        Serial.println("40%");
      }

      else if ((brightness)status==FORTY_PERCENT){
        status=SIXTY_PERCENT;
        Serial.println("60%");
      }

      else if ((brightness)status==SIXTY_PERCENT){
        status=EIGHTY_PERCENT;
        Serial.println("80%");
      }

      else if ((brightness)status==SIXTY_PERCENT){
        status=HUNDRED_PERCENT;
        Serial.println("100%");
      }

    }
  }

  switch(status){
    case ZERO_PERCENT:{
      analogWrite(led,int(255*0.2));
      break;
    }

    case TWENTY_PERCENT:{
      analogWrite(led,int(255*0.4));
      break;
    }

    case SIXTY_PERCENT:{
      analogWrite(led,int(255*0.6));
      break;
    }

    case EIGHTY_PERCENT:{
      analogWrite(led,int(255*0.8));
      break;
    }

    case HUNDRED_PERCENT:{
      analogWrite(led,255);
      break;
    }
  }
  
}
