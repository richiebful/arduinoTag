

/*
void binary(unsigned char * data, boolean * out){
    int i, j;
    unsigned char convTable[] = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, 
      {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'a', 10}, {'b', 11}, {'c', 12},
      {'d', 13}, {'e', 14}, {'f', 15}, {'g', 16}, {'h', 17}, {'i', 18}, {'j', 19},
      {'k', 20}, {'l', 21}, {'m', 22}, {'n', 23}, {'o', 24}, {'p', 25}, {'q', 26},
      {'r', 27}, {'s', 28}, {'t', 29}, {'u', 30}, {'v', 31}, {'w', 32}, {'x', 33},
      {'y', 34}, {'z', 35}};
   
    unsigned *char ciphertext = malloc(8*sizeof(char));
    int ctIndex = 0;
    for (i = 0; i < sizeof(data)/sizeof(char); i++){
      char datum = data[i];
      
      //entry = convTable[i];
      char entry[2];
      memcpy(entry, convTable[i], sizeof(entry));
      
      for (j = 0; j < sizeof(data)/sizeof(char); j++){
         if (datum == entry[0]){
             ciphertext[ctIndex] = entry[1];
             ctIndex++;
         }
      }
    }
}
*/

/*Input Digital Pin Nos.*/
int triggerButton = 2;
int reloadButton = 3;

/*Input Analogue Pin Nos.*/
int lGunDetector = 0;
int rGunDetector = 1;
int frontDetector = 2;
int backDetector = 3;

/*Output Pin Nos.*/
int irLaser = 12;
int visibleLaser = 13;

/*Input Values 
   *Analogue*/
int rDetector_v, lDetector_v, fDetector_v, bDetector_v;
  /*Digital*/
int trigger_v, reload_v;

void setup(){
  pinMode(irLaser,       OUTPUT);
  pinMode(visibleLaser,  OUTPUT);
  pinMode(triggerButton, INPUT);
  pinMode(reloadButton,  INPUT);
}

void loop(){
  /*Set analogue input values*/
  lDetector_v = analogRead(lGunDetector);
  rDetector_v = analogRead(rGunDetector);
  fDetector_v = analogRead(frontDetector);
  bDetector_v = analogRead(backDetector);
  
  /*Set digital input values*/
  trigger_v = digitalRead(triggerButton);
  reload_v = digitalRead(reloadButton);
}

