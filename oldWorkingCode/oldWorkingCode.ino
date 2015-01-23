int             sensorPin = 4;
int             ledPins[4] = {5,6,7,8};
int             life_v = 4;
unsigned long   previousMillis;
unsigned long   blinkInterval = 500;

void
setup()
{
    Serial.begin(9600);
    pinMode(sensorPin, INPUT);
    for (int i = 0; i < 4; i++){
      pinMode(ledPins[i], OUTPUT);
    }
    
    dispLife();
}

void
loop()
{
    unsigned int    total = 0;
    long            datum;
    
    
    for (int i = 0; i < 7; i++) {
	datum = pulseIn(sensorPin, LOW);
        //Serial.println(datum);
	total += datum;
    }
    
    if (life_v <= 0){
     life_v = 4; 
    }  
    
    if (total / 7.0 < 500) {
        Serial.println("Shot");
	life_v--;
        dispLife();
        delay(500);
    }
    // for (int i = 0; i < 20; i ++){
    // total += bitStore[i];
    // }
    // Serial.println(total/20.0);
    // if (total/20.0 < 2000 && total/20.0 > 1000){
    // shot_f ++;
    // }
    // else{
    // shot_f = 0;
    // }
    // if (shot_f > 2){
    // Serial.println("Fire");
    // }
}

void dispLife(){
  for (int i = 0; i < life_v; i++){
    digitalWrite(ledPins[i], HIGH); 
  }
  for (int j = life_v; j < 4; j++){
    digitalWrite(ledPins[j], LOW); 
  }
}

/*
 * void blinkLed(){ unsigned long currentMillis = millis();
 * if(currentMillis - previousMillis > blinkInterval) { // save the last
 * time you blinked the LED previousMillis = currentMillis; // if the LED
 * is off turn it on and vice-versa: if (ledState == LOW){ ledState =
 * HIGH; }else{ ledState = LOW; } // set the LED with the ledState of the
 * variable: digitalWrite(ledPin, ledState); } }
 */
