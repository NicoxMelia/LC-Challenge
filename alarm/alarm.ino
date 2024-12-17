#define SENSOR_PIN 4
#define BUZZER_PIN 7
#include "Libraries/detection.h"

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(SENSOR_PIN);

  if(reading == HIGH){
    say();  // Turn on the buzzer
  }else{
    // Turn off buzzer
  }

}
