#define SENSOR_PIN 4
#define BUZZER_PIN 9
#define RX 10
#define TX 11
#include "alarmclass.h"

Alarm alarm(SENSOR_PIN, BUZZER_PIN, RX, TX);

void setup() {
  Serial.begin(9600);
  digitalWrite(13, LOW);
  alarm.setupPinMode();
  alarm.setupDisplay();
  alarm.setupBluetooth();
  
}

void loop() {

  while(alarm.isFirstTime()){
    Serial.println("\nBeing the first time of you using this product, set the password please");
    alarm.printSingleRow("SET THE PSWD");
    if(alarm.hasReceivedKey()){
      alarm.readKey();
      alarm.setKey(alarm.getKeyReceived());
      Serial.println("Thanks for giving me the password");
      alarm.printTwoRows("Thanks for the", "pswd");
      alarm.setFirstTime(false);
    }
    delay(1500);
  }

  if(!alarm.isArmed()){
    alarm.stopSound();
    Serial.println("Put the pswd please...");
    alarm.printSingleRow("ALARM DISABLED");
    if(alarm.hasReceivedKey()){
      alarm.readKey();
      alarm.checkPassword();
    }

  }else{
     Serial.println("THE ALARM WAS TURNED ON");
     alarm.printSingleRow("TURNDED ON");
     if(alarm.detectSomeone()){
      alarm.makeSound();
     }

        if(alarm.hasReceivedKey()){
          alarm.readKey();
          alarm.checkPassword();
        }
     }

  delay(500);

}
