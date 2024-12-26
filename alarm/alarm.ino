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
  bluetooth.begin(9600);
  digitalWrite(13, LOW);
  digitalWrite(7, HIGH);
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
    checkKeypad();
    key = btkey;
    Serial.println("Thanks for giving me the password");
    isFirstTime = false;
  }

  if(!armed){
    Serial.println("Put the pswd please...");
    //Serial.println("The correct pswd is " + key);
    checkKeypad();
    if(btkey == key){
      armed = !armed;
    }else{
      Serial.println("Incorrect password");
    }

  }else{
     Serial.println("THE ALARM WAS TURNED ON");
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
