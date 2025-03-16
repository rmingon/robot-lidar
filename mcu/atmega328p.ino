#include <Wire.h>

#define I2C_ADDRESS 0x55  // Slave address

const int pwmPins[4] = {5, 6, 9, 10};
uint8_t pwmValues[4] = {0, 0, 0, 0};

void receiveEvent(int bytes) {
    int i = 0;
    while (Wire.available() && i < 4) {
        pwmValues[i] = Wire.read();
        i++;
    }
    updatePWM();
}

void updatePWM() {
    for (int i = 0; i < 4; i++) {
        analogWrite(pwmPins[i], pwmValues[i]);
    }
}

void setup() {
    Wire.begin(I2C_ADDRESS); 
    Wire.onReceive(receiveEvent);
    for (int i = 0; i < 4; i++) {
        pinMode(pwmPins[i], OUTPUT);
        analogWrite(pwmPins[i], 0);
    }
}

void loop() {
  delay(10);
}