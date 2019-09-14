#include <Wire.h>

#define ADDR  8


int rpm = 0;



void setup() {
  Wire.begin(ADDR);                
  Wire.onReceive(recvRPM);
  Wire.onRequest(sendRPM);
}



void loop() {
  delay(100);
}



void recvRPM(int numBytes) {
  byte b0 = Wire.read();
  byte b1 = Wire.read();
  
  rpm = b0 | (b1 << 8);
}

void sendRPM(){
  byte b0 = rpm & 0xFF;
  byte b1 = (rpm >> 8) & 0xFF;

  Wire.write(b0);
  Wire.write(b1);
}
