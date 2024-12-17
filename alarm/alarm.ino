#define SENSOR_PIN 4

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(SENSOR_PIN);

  if(reading == HIGH){
    //Turn on buzzer
  }else{
    // Turn off buzzer
  }

}
