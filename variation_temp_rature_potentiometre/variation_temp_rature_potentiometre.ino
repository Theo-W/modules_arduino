// on importe les librairie
#include <Wire.h>
#include "DFRobot_RGBLCD.h"

//on defini les variable 
DFRobot_RGBLCD lcd(16,2);
int r,g,b;
const int polar = 0; 

void setup() {
  // initialisation de l'écrant LCD
  lcd.init();

  // Initialisation de la communication avec le moniteur sur la broche 40
  Serial.begin(9600);
  //initialisation de la proche A0 en entré
  pinMode(polar,INPUT);

  // affichange 
  r = 255; //valeur canal Rouge 
  g = 150; //valeur canal vert
  b = 200; //valeur canal Bleu

  // on affiche les élements statiques
  lcd.setCursor(0,0);
  lcd.print("TEMP:");
  lcd.setCursor(0,1);
  lcd.print("CONSIGNE:");
  lcd.setCursor(11, 1);
  lcd.print("C");

}

void loop() {
    // on defini la valeur max et min
    int valeur_polar = map(analogRead(polar), 0, 1024, 1, 26);
    
    // on lui dit que au dessus de 10 on decale l'unite a gauche
    if (valeur_polar <10){
       lcd.setCursor(9, 1);
       lcd.print(" ");
       lcd.setCursor(10,1);
    }else {
       lcd.setCursor(9, 1);
    }
    
    // on affiche la valeur
    lcd.print(valeur_polar);
    // on donner un delais de 100 ms
    delay(100);

}
