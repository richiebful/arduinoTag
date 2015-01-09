int trigger_i = 22;
int led_o = 48;

void setup(){
   pinMode(trigger_i, INPUT);
   pinMode(led_o    , OUTPUT);
}

void loop(){
   if (digitalRead(trigger_i) == HIGH){
     for (int i; i < 10; i ++){
      digitalWrite(led_o, HIGH);
      delayMicroseconds(13);
      digitalWrite(led_o, LOW);
      delayMicroseconds(13);
     }
   }
}
