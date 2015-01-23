int reloadIPin = 5;
int fireIPin = 6;
int firePin = 7;
int clip_v = 6;
const int clip_max = 6;

void setup(){
  Serial.begin(9600);
  pinMode(reloadIPin, INPUT);
  pinMode(fireIPin,   INPUT);
  pinMode(firePin,    OUTPUT);
}

void loop(){
  if (digitalRead(fireButtonPin)==HIGH && clip_v > 0){
    digitalWrite(firePin, HIGH);
    delay(500);
    digitalWrite(firePin, LOW);
    clip_v--;
  }
  if (digitalRead(reloadButtonPin) == HIGH){
    clip_v = clip_max;
  }
}
