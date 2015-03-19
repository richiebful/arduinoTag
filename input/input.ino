int reloadButtonPin = 2;
int fireButtonPin = 3;
int firePin = 4;
int ammo_vPin = 5;
int clip_v = 6;
int laser = 6;
const int clip_max = 6;

void setup(){
  Serial.begin(9600);
  pinMode(reloadButtonPin, INPUT);
  pinMode(fireButtonPin,   INPUT);
  pinMode(laser, OUTPUT);
  pinMode(firePin,    OUTPUT);
  pinMode(ammo_vPin, OUTPUT);

}

void loop(){
  dispAmmo ();
  
  if (digitalRead(fireButtonPin)== HIGH && clip_v > 0){
    while (digitalRead(fireButtonPin) == HIGH){}
    Serial.println("Shot");
    digitalWrite(firePin, LOW); 
    digitalWrite(laser, HIGH);
    delay(100); 

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
