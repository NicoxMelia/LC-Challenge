#include "LiquidCrystal_I2C.h"
#include "alarmclass.h"

Alarm::Alarm(int sensorPin, int buzzerPin, int rx, int tx){
  this->sensorPin = sensorPin;
  this->buzzerPin = buzzerPin;
  this->rx = rx;
  this->tx = tx;
  displayLcd = new LiquidCrystal_I2C(0x27, 2, 1, 0, 4, 5, 6, 7);
  bluetooth = new SoftwareSerial(rx, tx);
  armed = false;
  setKey("1234");
  setFirstTime(true);
}

void Alarm::setupPinMode(){
    pinMode(sensorPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(13, OUTPUT);
}

void Alarm::setupDisplay(){
    displayLcd->setBacklightPin(3, POSITIVE);
    displayLcd->setBacklight(HIGH);
    displayLcd->begin(16, 2);
    displayLcd->clear();
}

void Alarm::setupBluetooth(){
    bluetooth->begin(9600);
}

bool Alarm::hasReceivedKey(){
    if(bluetooth->available()){
        return true;
    }
}

bool Alarm::detectSomeone(){
    return digitalRead(sensorPin) == HIGH;
}

bool Alarm::isFirstTime(){
    return firstTime;
}

void Alarm::printSingleRow(String message){
    displayLcd->setCursor(0,0);
    displayLcd->clear();
    displayLcd->print(message);
}

void Alarm::printTwoRows(String message1, String message2){
    displayLcd->setCursor(0,0);
    displayLcd->clear();
    displayLcd->print(message1);
    displayLcd->setCursor(0,1);
    displayLcd->print(message2);
}

void Alarm::setFirstTime(bool firstTime){
    this->firstTime = firstTime;
}

bool Alarm::isArmed(){
    return armed;
}

void Alarm::setArmed(bool armed){
    this->armed = armed;
}

void Alarm::setKey(String key){
    this->key = key;
}

void Alarm::checkPassword(){
    if(getKeyReceived() == key){
      setArmed(!isArmed());
    }else{
      printSingleRow("INCORRECT PSWD");
      delay(500);
    }
}

void Alarm::makeSound(){
    tone(buzzerPin, 2000);
}

void Alarm::stopSound(){
    noTone(buzzerPin);
}

void Alarm::readKey(){
    btkey = bluetooth->readString();
}

String Alarm::getKeyReceived(){
    return btkey;
}

