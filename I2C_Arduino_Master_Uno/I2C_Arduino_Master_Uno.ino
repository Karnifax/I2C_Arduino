#include <Wire.h>



int rpm = 1000;



void setup() {
  Wire.begin();
  Serial.begin(9600);
}



void loop() {
  Serial.println(rpm);
  sendRPM(8);
  Serial.println(rpm);
  delay(500);
  requestRPM(8);
  Serial.println(rpm);
  delay(500);
  ++rpm;
}



int requestRPM(int device){
  Wire.requestFrom(device, 2);

  byte b0 = Wire.read();
  byte b1 = Wire.read();

  rpm = b0 | (b1 << 8);
}

void sendRPM(int device){
  byte b0 = rpm & 0xFF;
  byte b1 = (rpm >> 8) & 0xFF;

  Wire.beginTransmission(device);
  Wire.write(b0);
  Wire.write(b1);
  Wire.endTransmission();
}
