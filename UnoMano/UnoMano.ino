//includes
#include <Wire.h>

void setup() {
    Wire.begin();
    Serial.begin(9600);
}

void loop() {
    int inputs;

    //address port B
    Wire.beginTransmission(0x20);
    Wire.write(0x13);
    Wire.endTransmission();
    
    //request one byte from 0x20
    Wire.requestFrom(0x20, 1);
       
    String x = String(Wire.read(),BIN);
    Serial.println(x);
    for(int i = 0; i < x.length();i++){
      //DO A THING TO THE BYTE
    }

    

 
}
