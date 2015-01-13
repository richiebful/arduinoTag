int sensorPin = 4;
int healthLevel = 5;
int blinkState = LOW;
int blinkPin = 11;

int healthPin[5] = {6, 7, 8, 9, 10};

unsigned long previousMillis;
unsigned long blinkInterval = 500;

void setup(){
   Serial.begin(9600);
   pinMode(sensorPin, INPUT);
}

void loop(){
  int bitStore[20];
  unsigned int total = 0;
  int datum;
  dispHealth();
  for (int i = 0; i < 7; i++){
    datum = pulseIn(sensorPin, LOW);
    total += datum;
 }
  if (total/7.0 < 200){
    for (int i = 0; i < 10; i ++){
      blinkLed();
      healthLevel -= 1;
    }
  }
}

void dispHealth(){
  for (int i = 0; i < healthLevel; i++){
    digitalWrite(healthPin[i], HIGH);
  }
  for (int i = healthLevel; i < 5; i++){
    digitalWrite(healthPin[i], LOW);
  }
}

void blinkLed(){
 unsigned long currentMillis = millis();
 
 if(currentMillis - previousMillis > blinkInterval) {
    // save the last time you blinked the LED 
   previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
   if (blinkState == LOW){
     blinkState = HIGH;
   }else{
   blinkState = LOW;
   }

   // set the LED with the ledState of the variable:
   digitalWrite(blinkPin, blinkState); 
 }
}


