int trigger_i = 22;
int led_o = 48;

int clip_max = 20
int clip_v = 20;

int ammo_max = 100;
int ammo_l = 100;

void setup(){
   pinMode(trigger_i, INPUT);
   pinMode(led_o    , OUTPUT);
}

void loop(){
   senseFire();
   senseReload();
}

void senseFire(){
  while (trigger_i == HIGH){;}
  
}
