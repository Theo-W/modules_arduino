#include <SPI.h>
#include <RFID.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
Servo monServo;

RFID rfid(SS_PIN,RST_PIN);
int serNum[5];
int cards[][5] = {{109, 147, 141, 171, 216}};
bool access = false;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.init();

  monServo.attach(2);
}

void loop() {
  if (rfid.isCard()){
    
    if ( rfid.readCardSerial()) {
      Serial.print(rfid.serNum[5]);

      for(int x = 0; x < sizeof(cards); x++){
              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
                  if(rfid.serNum[i] != cards[x][i]) {
                      access = false;
                      break;
                  } else {
                      access = true;
                  }
              }
         if(access) break;
      }
    } 
    
    if (access) {
      Serial.println("tu as la bonne carte");
      int angle = map(0, 0103/2);
      monServo.write(angle);
    } else {
      Serial.println("la carte est pas bonne");
      int angle = map(0, 0, 0, 0, 0);
    }
  }
}
