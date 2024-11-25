// Pin Definitions
#define IN1 5  // Direction control pin 1
#define IN2 18  // Direction control pin 2
#define ENA 19  // PWM pin for motor speed control

void setup() {
  // Set motor pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // Start Serial for debugging
  Serial.begin(115200);
}

void loop() {
  // Forward rotation
  Serial.println("Motor rotating forward...");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 128); // Set speed (range: 0-255)
  delay(2000);

  // Stop motor
  Serial.println("Motor stopping...");
  analogWrite(ENA, 0);
  delay(2000);

  // Reverse rotation
  Serial.println("Motor rotating backward...");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200); // Set speed
  delay(2000);

  // Stop motor
  Serial.println("Motor stopping...");
  analogWrite(ENA, 0);
  delay(2000);
}
