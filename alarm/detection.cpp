#include "detection.h"
#include "Arduino.h"


void makeSound(int pin) {
    tone(pin, 2000);
    Serial.println("AAAAA");
}

void stopSound(int pin){
  noTone(pin);
  Serial.println("NOOOO");
}