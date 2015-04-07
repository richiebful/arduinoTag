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

LiquidCrystal lcd(6, 7, 5, 4, 3, 2);
byte ammo[8] = {
	0b00100,
	0b00100,
	0b01110,
	0b01110,
	0b01110,
	0b01110,
	0b01110,
	0b01110
};
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

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
  
  lcd.begin(16, 2);
  lcd.createChar(1, heart);
  lcd.createChar(0, ammo);
}

void loop(){
  dispAmmo();
  dispLife();
  unsigned int    total = 0;
  long            datum;
  
  datum = pulseIn(sensorPin, LOW, 1000);
  
  if (life_v <= 0){
    life_v = 5; 
  }  
  
  if (datum > 100) {
    Serial.println("Shot");
    life_v--;
    delay(500);
  } 
  
  if (digitalRead(fireButtonPin)== HIGH && clip_v > 0){
    Serial.println("Pushed in");
    while (digitalRead(fireButtonPin) == HIGH){}
    Serial.println("Fire Button");
    digitalWrite(firePin, LOW); 
    digitalWrite(laser, HIGH);
    delay(100); 
    digitalWrite(firePin, HIGH);
    digitalWrite(laser, LOW);
    clip_v--;
  }
  
  Serial.println("Ammo");
  Serial.println(clip_v);
  Serial.println("Health");
  Serial.println(life_v);
  
  if (digitalRead(reloadButtonPin) == HIGH){
    while (digitalRead(reloadButtonPin) == HIGH){}
    clip_v = clip_max;
  }
}
   

void dispAmmo(){
  lcd.setCursor(0,1);
  for (int i = 0; i < ammo_v; i++){
    lcd.write((byte) 0);
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
