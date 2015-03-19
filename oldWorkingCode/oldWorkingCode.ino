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
      Serial.println(datum);
      total += datum;
    }

    if (life_v <= 0){
      life_v = 5;
    }

    if (total / 7.0 > 100) {
      Serial.println("Shot");
	    life_v--;
      dispLife();
      delay(500);
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
