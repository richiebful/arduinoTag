int sensorPin = 4;
int healthLevel = 5;

int healthPin = {6, 7, 8, 9, 10);

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
//  for (int i = 0; i < 20; i ++){
//    total += bitStore[i]; 
//  }
//  Serial.println(total/20.0);
//  if (total/20.0 < 2000 && total/20.0 > 1000){
//    shot_f ++;
//  }  
//  else{
//    shot_f = 0; 
//  }
//  if (shot_f > 2){
//    Serial.println("Fire"); 
//  }
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
   if (ledState == LOW){
     ledState = HIGH;
   }else{
   ledState = LOW;
   }

   // set the LED with the ledState of the variable:
   digitalWrite(ledPin, ledState); 
 }
}


