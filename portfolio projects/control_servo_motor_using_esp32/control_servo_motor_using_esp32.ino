#include <ESP32Servo.h>  // Include the ESP32Servo library to control servo motors with ESP32

Servo myServo;  // Create an instance of the Servo class to control the servo motor
int servoPin = 27;  // Define the pin to which the servo is connected (GPIO 27)

void setup() {
  // put your setup code here, to run once:
  
  myServo.attach(servoPin);  // Attach the servo to the specified pin (GPIO 27)
  
  // myServo.write(90);  // Optional: Set the servo to the neutral position (90 degrees), but this line is commented out
  
  Serial.begin(115200);  // Initialize the Serial Monitor with a baud rate of 115200 for communication
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Serial.available()) {  // Check if data is available to read from the Serial Monitor
    int angle = Serial.parseInt();  // Read the integer value (angle) sent via the Serial Monitor
    myServo.write(angle);  // Move the servo to the specified angle
  }
  
  delay(20);  // Delay for 20 milliseconds to allow the servo to move and avoid overwhelming the loop
}













// #include <ESP32Servo.h>  // Include the ESP32Servo library to control servo motors with ESP32

// Servo myServo;  // Create an instance of the Servo class to control the servo motor
// int servoPin = 27;  // Define the pin to which the servo is connected (GPIO 27)

// void setup() {
//   // Initialization code:
  
//   myServo.attach(servoPin);  // Attach the servo to the specified pin (GPIO 27)
  
//   Serial.begin(115200);  // Initialize the Serial Monitor with a baud rate of 115200 for communication
  
//   Serial.println("Servo Control Project Initialized!");
//   Serial.println("Send an angle (0-180) to move the servo.");
//   Serial.println("Example: Send 90 to move to the middle position.");
//   Serial.println("To reset, send 'reset'. To stop, send 'stop'.");
// }

// void loop() {
//   // Main code:
  
//   if (Serial.available()) {  // Check if data is available to read from the Serial Monitor
//     String input = Serial.readStringUntil('\n');  // Read the input string from Serial Monitor
    
//     // Check if the input is a number (angle)
//     int angle = input.toInt();  // Convert the string input to an integer
    
//     // If input is a valid angle (between 0 and 180 degrees)
//     if (angle >= 0 && angle <= 180) {
//       Serial.print("Moving servo to: ");
//       Serial.print(angle);
//       Serial.println(" degrees.");
//       smoothMove(angle);  // Move the servo smoothly to the new angle
//     }
//     // Check for "reset" command
//     else if (input == "reset") {
//       Serial.println("Resetting servo to 90 degrees.");
//       smoothMove(90);  // Reset the servo to the middle position
//     }
//     // Check for "stop" command
//     else if (input == "stop") {
//       Serial.println("Stopping servo movement.");
//       // Optionally, we can hold the servo at the current position or turn it off
//     }
//     // Handle invalid inputs
//     else {
//       Serial.println("Invalid input! Please enter a number between 0 and 180 or a command.");
//     }
//   }
  
//   delay(20);  // Small delay to allow for stable serial communication
// }

// // Function to smoothly move the servo from its current position to the target angle
// void smoothMove(int targetAngle) {
//   int currentAngle = myServo.read();  // Get the current position of the servo
//   int step = (targetAngle > currentAngle) ? 1 : -1;  // Determine direction of movement

//   // Move the servo in small steps
//   while (currentAngle != targetAngle) {
//     currentAngle += step;  // Increment or decrement the angle based on direction
//     myServo.write(currentAngle);  // Set the servo to the new position
//     delay(15);  // Small delay for smoother movement
//   }
  
//   Serial.print("Servo reached: ");
//   Serial.print(targetAngle);
//   Serial.println(" degrees.");
// }
