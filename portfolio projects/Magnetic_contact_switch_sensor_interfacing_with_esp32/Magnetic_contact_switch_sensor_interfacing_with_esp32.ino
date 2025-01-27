
byte Sensor_Pin = 2, LED_Pin = 4;
void setup() {
  Serial.begin(115200);
  pinMode(Sensor_Pin, INPUT);
  pinMode(LED_Pin, OUTPUT);
  Serial.println("\n\nWelcome\n");
}

void loop() {
  bool Sensor_State = digitalRead(Sensor_Pin);
  Serial.println("\nSensor_State: " + String(Sensor_State));
  if (Sensor_State) {
    digitalWrite(LED_Pin, LOW);
    Serial.println("Door Close");
  } else {
    digitalWrite(LED_Pin, HIGH);
    Serial.println("Door Open");
  }
  delay(100);
}