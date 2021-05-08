//on importe les librairie
#include <Wire.h>
#include "DFRobot_RGBLCD.h"


//on défini le variable
int r,g,b;
const int polar = 0;
DFRobot_RGBLCD lcd(0,0);

void setup() {
  // Initialisation de la communication avec le moniteur sur la broche 40
  Serial.begin(9600);
  
  // initialisation de l'écrant LCD
  lcd.init();

  // affichange 
  r = 255; //valeur canal Rouge 
  g = 150; //valeur canal vert
  b = 200; //valeur canal Bleu

  //on défini LDC
  lcd.setRGB(r, g, b);
  lcd.setCursor(0,0);
  
}

void loop() {
   lcd.clear();
  
   // Acquisition de la valeur du potentionmètre
   int valeur_polar = analogRead(polar);

   //Affichage de la valeur sur l'écran LCD
   lcd.println(valeur_polar);

   //on met un delait
   delay(500);
}
