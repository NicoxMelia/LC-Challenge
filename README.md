# Arduino Alarm Project with Android Application

This project consists of an Arduino-based alarm that can be controlled via an Android application. The alarm uses a sensor to detect intruders and a buzzer to emit an alert sound. Communication between the Arduino and the Android application is done via Bluetooth.

## Components

- Arduino Uno
- HC-05 or HM-10 Bluetooth Module
- Motion Sensor (PIR)
- Buzzer
- I2C LCD Display
- Resistors and connecting wires

## Connections

- **Motion Sensor (PIR)**:
  - VCC to 5V
  - GND to GND
  - OUT to pin 4 of the Arduino

- **Buzzer**:
  - VCC to pin 9 of the Arduino
  - GND to GND

- **Bluetooth Module**:
  - VCC to 5V
  - GND to GND
  - TX to pin 10 of the Arduino
  - RX to pin 11 of the Arduino

- **I2C LCD Display**:
  - VCC to 5V
  - GND to GND
  - SDA to SDA of the Arduino
  - SCL to SCL of the Arduino

## Description of the `Alarm` Class

### Public Methods

- **`Alarm(int sensorPin, int buzzerPin, int rx, int tx)`**: Constructor that initializes the sensor, buzzer, and Bluetooth pins.
- **`~Alarm()`**: Destructor that frees dynamically allocated memory.
- **`void setupPinMode()`**: Configures the pin modes for the sensor, buzzer, and other necessary pins.
- **`void setupDisplay()`**: Configures the LCD display.
- **`void setupBluetooth()`**: Configures Bluetooth communication.
- **`bool hasReceivedKey()`**: Checks if a key has been received via Bluetooth.
- **`bool detectSomeone()`**: Detects if there is movement using the PIR sensor.
- **`bool isFirstTime()`**: Checks if it is the first time the alarm is being used.
- **`void printSingleRow(String message)`**: Prints a message on a single row of the LCD display.
- **`void printTwoRows(String message1, String message2)`**: Prints two messages on two rows of the LCD display.
- **`void setFirstTime(bool isFirstTime)`**: Sets whether it is the first time the alarm is being used.
- **`bool isArmed()`**: Checks if the alarm is armed.
- **`void setArmed(bool armed)`**: Sets the state of the alarm (armed or disarmed).
- **`void setKey(String key)`**: Sets the alarm key.
- **`void checkPassword()`**: Checks if the received key is correct.
- **`void makeSound()`**: Activates the buzzer to emit a sound.
- **`void stopSound()`**: Deactivates the buzzer.
- **`void readKey()`**: Reads the key received via Bluetooth.
- **`String getKeyReceived()`**: Gets the key received via Bluetooth.
- **`void loop()`**: Main method that runs in the Arduino's main loop.

### Private Attributes

- **`int sensorPin`**: Pin for the motion sensor.
- **`int buzzerPin`**: Pin for the buzzer.
- **`int rx`**: RX pin for the Bluetooth module.
- **`int tx`**: TX pin for the Bluetooth module.
- **`bool armed`**: State of the alarm (armed or disarmed).
- **`String key`**: Alarm key.
- **`String btkey`**: Key received via Bluetooth.
- **`bool firstTime`**: Indicates if it is the first time the alarm is being used.
- **`LiquidCrystal_I2C* displayLcd`**: Pointer to the LCD display.
- **`SoftwareSerial* bluetooth`**: Pointer to the Bluetooth module.

## Android Application

### Requirements

- Android Studio
- Android device with BLE support

### General Description

The Android application allows you to control the alarm via Bluetooth. It includes a simple interface with buttons to arm and disarm the alarm, as well as to display alert messages.

### Features

- **Show AlertDialog**: Displays a simple alert dialog.
- **Send Commands**: Sends commands to arm and disarm the alarm via Bluetooth.

## Instructions

1. **Set Up the Hardware**: Connect all components according to the connections described above.
2. **Upload the Code to Arduino**: Use the Arduino IDE to upload the code to your Arduino board.
3. **Set Up the Android Application**: Open the project in Android Studio, compile it, and run it on your Android device.
4. **Pair the Device**: Pair your Android device with the Arduino's Bluetooth module.
5. **Control the Alarm**: Use the Android application to send commands and control the alarm.

## Video Demonstration

Watch the video demonstration of the project on YouTube: [Arduino Alarm Project](https://www.youtube.com/shorts/gQN5sM1SFuw)