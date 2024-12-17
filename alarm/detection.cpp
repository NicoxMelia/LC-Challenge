#include "detection.h"
#include "Arduino.h"


void makeSound(int pin) {
    //digitalWrite(pin, HIGH);
    tone(pin, 2000);
    Serial.println("AAAAA");
}

void stopSound(int pin){
  //digitalWrite(pin, LOW);
  noTone(pin);
  Serial.println("NOOOO");
}