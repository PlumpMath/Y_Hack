//includes
#include "UnoJoy.h"

void setup() {
	setupUnoJoy();

	for (int i = 2; i < 10; i++) {
		pinMode(i, INPUT);
		digitalWrite(i, HIGH);
	}

	pinMode(A0, INPUT);
	pinMode(A1, INPUT);
}

void loop() {
	dataForController_t bin = getBlankDataForController();

	bin.triangleOn = ! digitalRead(7);
	bin.circleOn = ! digitalRead(6);
	bin.squareOn = ! digitalRead(9);
	bin.crossOn = ! digitalRead(8);

	bin.startOn = ! digitalRead(3);
        bin.selectOn = ! digitalRead(4);
        
        bin.l1On = ! digitalRead(5);
        bin.r1On = ! digitalRead(2);

	bin.leftStickX = analogRead(A1) >> 2;
	bin.leftStickY = analogRead(A0) >> 2;

	setControllerData(bin);
}