
unsigned long   previousMillis;
unsigned long   blinkInterval = 500;
int reloadButtonPin = 53;
int fireButtonPin = 52;
int firePin = 51;
int ammo_vPin = 50;
int laser = 49;
int ledPins[4] = {23,24,25,26};
int sensorPin = 22;

int life_v = 4;
int clip_v = 6;
const int clip_max = 6;

void
setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(reloadButtonPin, INPUT);
  pinMode(fireButtonPin,   INPUT);
  pinMode(laser, OUTPUT);
  pinMode(firePin,    OUTPUT);
  pinMode(ammo_vPin, OUTPUT);
  for (int i = 0; i < 4; i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop(){
  dispAmmo();
  dispLife();
  unsigned int    total = 0;
  long            datum;
  
  
  for (int i = 0; i < 7; i++) {
	datum = pulseIn(sensorPin, LOW);
	total += datum;
  }
  
  if (life_v <= 0){
    life_v = 5; 
  }  
  
  if (total / 7.0 > 100) {
      Serial.println("Shot");
      life_v--;
      delay(500);
  } 
  
  if (digitalRead(fireButtonPin)== HIGH && clip_v > 0){
    while (digitalRead(fireButtonPin) == HIGH){}
    Serial.println("Shot");
    digitalWrite(firePin, LOW); 
    digitalWrite(laser, HIGH);
    //delay(100); 
    digitalWrite(firePin, HIGH);
    digitalWrite(laser, LOW);
    clip_v--;
  }
  
  Serial.println(clip_v);
  
  if (digitalRead(reloadButtonPin) == HIGH){
    while (digitalRead(reloadButtonPin) == HIGH){}
    clip_v = clip_max;
  }
}
   

void dispAmmo(){
  if (clip_v <= 0){
     digitalWrite(ammo_vPin,  HIGH);
  }
  else{
     digitalWrite(ammo_vPin, LOW); 
  } 
  
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
