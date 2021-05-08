#include <Servo.h>
Servo monServo;


 void setup() {
  monServo.attach(2);
  Serial.begin(9600);
 }

void loop(){
  int val=analogRead(potar);
  int angle = map(val, 0, 1023, 0, 180);

  monServo.write(angle);
}
