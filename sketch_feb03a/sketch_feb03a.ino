#include <Wire.h>
#include "DFRobot_RGBLCD.h"

int r,g,b;
int compteur = 0;
int compteur2 = 0;
DFRobot_RGBLCD lcd(16,2);

void setup() {
  // initialisation de l'écrant LCD
  lcd.init();

  // affichange 
  r = 255; //valeur canal Rouge 
  g = 150; //valeur canal vert
  b = 200; //valeur canal Bleu

}

void loop() {
    lcd.clear();
    // on agremente notre variable
    for(compteur = 1; compteur<= 20 ; compteur ++){
      //on met une condition pour afficher la dizaines a gauche
      if (compteur<10){
        lcd.setCursor(5, 1);
      }else{
        lcd.setCursor(4 , 1);
      }
      // on affiche le compteur
      lcd.print(compteur);
      // on met un temps de l'attence
      delay(500);
    }
  
}
