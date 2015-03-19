int reloadButtonPin = 53;
int fireButtonPin = 46;
int firePin = 43;
int ammo_vPin = 50;
int clip_v = 6;
const int clip_max = 6;

void setup(){
  Serial.begin(9600);
  pinMode(reloadButtonPin, INPUT);
  pinMode(fireButtonPin,   INPUT);
  pinMode(firePin,    OUTPUT);
  pinMode(ammo_vPin, OUTPUT);

}

void loop(){
  dispAmmo ();

  if (digitalRead(fireButtonPin)== HIGH && clip_v > 0){
    while (digitalRead(fireButtonPin) == HIGH){}
    Serial.println("Shot");
    digitalWrite(firePin, LOW);
     delay(100);
    digitalWrite(firePin, HIGH);
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
