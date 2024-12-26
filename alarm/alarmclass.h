#ifndef ALARMCLASS_H
#define ALARMCLASS_H
#include "Arduino.h"
#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

class Alarm{
  public:
    Alarm(int sensorPin, int buzzerPin, int rx, int tx);
    void setupPinMode();
    void setupDisplay();
    void setupBluetooth();
    bool hasReceivedKey();
    bool detectSomeone();
    bool isFirstTime();
    void printSingleRow(String message);
    void printTwoRows(String message1, String message2);
    void setFirstTime(bool isFirstTime);
    bool isArmed();
    void setArmed(bool armed);
    void setKey(String key);
    void checkPassword();
    void makeSound();
    void stopSound();
    void readKey();
    String getKeyReceived();

    private:
        int sensorPin;
        int buzzerPin;
        int rx;
        int tx;
        bool armed;
        String key;
        String btkey;
        bool firstTime;
        LiquidCrystal_I2C* displayLcd;
        SoftwareSerial* bluetooth;
};

#endif