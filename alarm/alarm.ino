#define SENSOR_PIN 4
#define BUZZER_PIN 9
#define RX 10
#define TX 11
#include "detection.h"
#include <SoftwareSerial.h>
#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


SoftwareSerial bluetooth(RX, TX);
LiquidCrystal_I2C displayLcd(0x27, 2, 1, 0, 4, 5, 6, 7);

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
  digitalWrite(13, LOW);
  digitalWrite(7, HIGH);
  displayLcd.setBacklightPin(3, POSITIVE);
  displayLcd.setBacklight(HIGH);
  displayLcd.begin(16, 2);
  displayLcd.clear();
}

bool armed = false;
String key = "1234";
String btkey;
bool isFirstTime = true;


void checkKeypad(){
  while(true){
    if(bluetooth.available()){
      btkey = bluetooth.readString();
      break;
    }
  }
}

bool detectSomeone(){
  return digitalRead(SENSOR_PIN) == HIGH;
}

void loop() {
  //int reading = digitalRead(SENSOR_PIN);

  /*if(Serial.available()){
    bluetooth.write(Serial.read());
  }

  if(bluetooth.available()){
    Serial.write(bluetooth.read());
  }*/

  while(isFirstTime){
    Serial.println("\nBeing the first time of you using this product, set the password please");
    displayLcd.setCursor(0, 0);
    displayLcd.clear();
    displayLcd.print("SET THE PSWD");
    checkKeypad();
    key = btkey;
    Serial.println("Thanks for giving me the password");
    displayLcd.clear();
    displayLcd.print("Thanks for the");
    displayLcd.setCursor(0, 1);
    displayLcd.print("pswd");
    isFirstTime = false;
    delay(1500);
  }

  if(!armed){
    Serial.println("Put the pswd please...");
    //Serial.println("The correct pswd is " + key);
    displayLcd.clear();
    displayLcd.setCursor(0, 0);
    displayLcd.print("ALARM DISABLED");
    checkKeypad();
    if(btkey == key){
      armed = !armed;
    }else{
      Serial.println("Incorrect password");
      displayLcd.clear();
      displayLcd.print("INCORRECT PSWD");
      delay(500);
    }

  }else{
     Serial.println("THE ALARM WAS TURNED ON");
     displayLcd.setCursor(0, 0);
     displayLcd.clear();
     displayLcd.print("TURNED ON");
     if(detectSomeone()){

      makeSound(BUZZER_PIN);
     }
     if(bluetooth.available()){
          btkey = bluetooth.readString();
          if(btkey == key){
            armed = !armed;
            stopSound(BUZZER_PIN);
        }else{
          Serial.println("Incorrect password");
          displayLcd.clear();
          displayLcd.print("INCORRECT");
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
