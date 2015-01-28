int reloadIPin = 5;
int fireButtonPin = 30;
int firePin = 41;
int ammo_vPin = 50;
int clip_v = 6;
const int clip_max = 6;

void setup(){
  Serial.begin(9600);
  pinMode(reloadIPin, INPUT);
  pinMode(fireButtonPin,   INPUT);
  pinMode(firePin,    OUTPUT);
  pinMode(ammo_vPin, OUTPUT);
  
}

void loop(){
  if (digitalRead(fireButtonPin)==LOW){
    Serial.println("Shot");
    digitalWrite(firePin, HIGH);
    delay(1000);
    digitalWrite(firePin, LOW);
   // clip_v--;
  }
  /*if (digitalRead(reloadButtonPin) == HIGH){
    clip_v = clip_max;
  }*/
  //dispAmmo();
}

void dispAmmo(){
  if (clip_v <= 0){
     digitalWrite(ammo_vPin,  HIGH);
  }
  else{
     digitalWrite(ammo_vPin, LOW); 
  } 
}
