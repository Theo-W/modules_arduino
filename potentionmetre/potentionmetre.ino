const int polar = 0;

void setup() {
  // Initialisation de la communication avec le moniteur sur la broche 40
  Serial.begin(9600);

  //initialisation de la proche A0 en entré
  pinMode(polar,INPUT);

}

void loop() {
  // Acquisition de la valeur du potentionmètre
  int valeur_polar = analogRead(polar);

  //Affichage de la valeur sur le moniteur série
  Serial.println(valeur_polar);

  //Temporisation
  delay(500);

}
