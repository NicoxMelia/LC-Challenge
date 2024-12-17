#define SENSOR_PIN 4
#define BUZZER_PIN 9
#include "detection.h"

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(SENSOR_PIN);

  if(reading == HIGH){
    makeSound(BUZZER_PIN);  // Turn on the buzzer
  }else{
    stopSound(BUZZER_PIN);  // Turn off buzzer
  }

  delay(500);

}
