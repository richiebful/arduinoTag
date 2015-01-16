int trigger_i = 22;
int reload_i = 53;
int led_o = 48;

int clip_max = 20;
int clip_v = 20;

int ammo_max = 100;
int ammo_v = 100;

void setup(){
  Serial.begin(9600);
  pinMode(trigger_i, INPUT);
  pinMode(reload_i , INPUT);
  pinMode(led_o    , OUTPUT);
}

void loop(){
   senseFire();
   senseReload();
}

void transmitShot(){
  Serial.println("Shots fired!");
}

void senseFire(){
  int trigger_v = digitalRead(trigger_i);
  if (trigger_v == HIGH){
    transmitShot();
  }  
}

void senseReload(){
  int added;
  if (digitalRead(reload_i) == HIGH){
    Serial.println(ammo_v);
    Serial.println(clip_v);
    if (ammo_v >= 0){
      added = clip_v % clip_max;
      if (ammo_v < added){
        added = ammo_v; 
      }
      ammo_v -= added;
      clip_v += added;
      ammo_v += added % 20;
    }
    else{
       ;//make obnoxious noise 
    }
  } 
}
