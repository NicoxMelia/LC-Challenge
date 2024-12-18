#define SENSOR_PIN 4
#define BUZZER_PIN 9
#define RX 10
#define TX 11
#include "detection.h"
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(RX, TX);

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(38400);
  digitalWrite(13, LOW);
  digitalWrite(7, HIGH);
}

bool armed = false;
String key = "";

void loop() {
  int reading = digitalRead(SENSOR_PIN);

  /*if(Serial.available()){
    bluetooth.write(Serial.read());
  }

  if(bluetooth.available()){
    Serial.write(bluetooth.read());
  }*/

  if(!armed){
    Serial.println("Put the pswd please...");
    if(bluetooth.available()){
      
      if(bluetooth.readString() == "1234"){
        Serial.println("Please, change your pswd now!");
        Serial.println("I'm waiting for the new pswd...");
        while (true) {
          if(bluetooth.available()){
            key = bluetooth.readString();
            Serial.println("Thanks for giving me the new psw!");
            break;
          }
        }
      }else if(bluetooth.readString() == key){
        Serial.println("THE ALARM WAS TURNED ON");
      }else{
        Serial.println("You gave me a wrong key...");
      }
    }
  }

/*  if(reading == HIGH){
    makeSound(BUZZER_PIN);  // Turn on the buzzer
  }else{
    stopSound(BUZZER_PIN);  // Turn off buzzer
  }*/

  delay(500);

}
