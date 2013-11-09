//includes
#include <Wire.h>
#include "UnoJoy.h"

void setup() {
    setupUnoJoy();

    Wire.begin();
    Serial.begin(9600);
}

void loop() {
    //address port B
    Wire.beginTransmission(0x20);
    Wire.write(0x13);
    Wire.endTransmission();
    
    //request one byte from 0x20
    Wire.requestFrom(0x20, 1);
       
    int inputs = Wire.read();

    int pin[8];

    for (int i = 0; i < 8; i++) {
        pin[i] = !(inputs & pow(2, i));   
    }

    dataForController_t bin = getBlankDataForController();

    bin.triangleOn = pin[0];
    bin.circleOn = pin[1];
    bin.squareOn = pin[2];
    bin.crossOn = pin[3];
    bin.dpadDownOn = pin[4];
    bin.dpadLeftOn = pin[5];
    bin.dpadRightOn = pin[6];
    bin.l1On = pin[7];

    setControllerData(bin);
}
