#define SENSOR_PIN 4
#include "Libraries/detection.h"

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(SENSOR_PIN);

  if(reading == HIGH){
    //Turn on buzzer
    makeSound();
  }else{
    // Turn off buzzer
  }

}
