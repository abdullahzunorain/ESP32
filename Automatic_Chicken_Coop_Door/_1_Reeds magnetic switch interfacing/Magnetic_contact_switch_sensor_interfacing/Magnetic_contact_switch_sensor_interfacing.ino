// // Pin Definitions
// const byte sensor_1 = 27;  // Pin D27 - Sensor_1(upper) for door closed position
// const byte sensor_2 = 2;  // Pin D2 - Sensor_2(lower) for door open position
// const byte LED_Close = 15; // Pin D15 - LED(green) for door closed indication
// const byte LED_Open = 4;   // Pin D4 - LED(white) for door open indication

// unsigned long previousMillis = 0;  // Timer for blinking LEDs
// const unsigned long interval = 500; // Blink interval in milliseconds
// bool ledState_Close = false;  // LED state for closed position
// bool ledState_Open = false;   // LED state for open position

// void setup() {
//   Serial.begin(115200);          // Initialize Serial Monitor
//   pinMode(sensor_1, INPUT);      // Set sensor_1 pin as input
//   pinMode(sensor_2, INPUT);      // Set sensor_2 pin as input
//   pinMode(LED_Close, OUTPUT);    // Set LED_Close pin as output
//   pinMode(LED_Open, OUTPUT);     // Set LED_Open pin as output
//   digitalWrite(LED_Close, LOW);  // Ensure LED_Close is OFF initially
//   digitalWrite(LED_Open, LOW);   // Ensure LED_Open is OFF initially

//   Serial.println("Automatic Chicken Coop Door System Initialized");
// }

// void loop() {
//   unsigned long currentMillis = millis();  // Get the current time

//   // Read sensor states
//   bool sensorState_1 = digitalRead(sensor_1); // Sensor 1 state (Door Closed)
//   bool sensorState_2 = digitalRead(sensor_2); // Sensor 2 state (Door Open)

//   // Handle Door Closed State
//   if (sensorState_1) {
//     // Blink LED_Close if the door is completely closed
//     if (currentMillis - previousMillis >= interval) {
//       previousMillis = currentMillis;
//       ledState_Close = !ledState_Close;  // Toggle LED state
//       digitalWrite(LED_Close, ledState_Close);
//     }
//     digitalWrite(LED_Open, LOW);  // Ensure Open LED is OFF
//     Serial.println("Door Status: Completely Closed");
//   } 
//   // Handle Door Open State
//   else if (sensorState_2) {
//     // Blink LED_Open if the door is completely open
//     if (currentMillis - previousMillis >= interval) {
//       previousMillis = currentMillis;
//       ledState_Open = !ledState_Open;  // Toggle LED state
//       digitalWrite(LED_Open, ledState_Open);
//     }
//     digitalWrite(LED_Close, LOW);  // Ensure Close LED is OFF
//     Serial.println("Door Status: Completely Open");
//   } 
//   // Handle Undefined State (Transition/Error)
//   else {
//     digitalWrite(LED_Close, LOW);  // Ensure both LEDs are OFF
//     digitalWrite(LED_Open, LOW);
//     Serial.println("Door Status: In Transition");
//   }

//   delay(100);  // Small delay for debounce and stability
// }





// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




// #include <Wire.h>                // For I2C communication
// #include <Adafruit_GFX.h>         // Core graphics library for OLED
// #include <Adafruit_SSD1306.h>     // OLED display library

// // OLED Display setup
// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 64
// #define OLED_RESET -1
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// // Pin Definitions
// const byte sensor_1 = 27;  // Pin D27 - Sensor_1(upper) for door closed position
// const byte sensor_2 = 2;   // Pin D2 - Sensor_2(lower) for door open position
// const byte LED_Close = 15; // Pin D15 - LED(green) for door closed indication
// const byte LED_Open = 4;   // Pin D4 - LED(white) for door open indication

// unsigned long previousMillis = 0;  // Timer for blinking LEDs
// const unsigned long interval = 500; // Blink interval in milliseconds
// bool ledState_Close = false;  // LED state for closed position
// bool ledState_Open = false;   // LED state for open position

// void setup() {
//   Serial.begin(115200);          // Initialize Serial Monitor
//   pinMode(sensor_1, INPUT);      // Set sensor_1 pin as input
//   pinMode(sensor_2, INPUT);      // Set sensor_2 pin as input
//   pinMode(LED_Close, OUTPUT);    // Set LED_Close pin as output
//   pinMode(LED_Open, OUTPUT);     // Set LED_Open pin as output
//   digitalWrite(LED_Close, LOW);  // Ensure LED_Close is OFF initially
//   digitalWrite(LED_Open, LOW);   // Ensure LED_Open is OFF initially

//   // Initialize OLED display
//   // if(!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
//     // Serial.println(F("SSD1306 allocation failed"));
//   //   for(;;);  // Stay in infinite loop if initialization fails
//   // }
//   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
//   display.clearDisplay();
//   display.setTextSize(2);         // Text size
//   display.setTextColor(SSD1306_WHITE); // Text color
//   display.setCursor(0, 0);       // Set cursor to top-left
//   display.println("Automatic Chicken Coop Door System Initialized");
//   display.display();             // Update display
//   delay(500);                   // Show initialization message for 2 seconds
// }

// void loop() {
//   unsigned long currentMillis = millis();  // Get the current time

//   // Read sensor states
//   bool sensorState_1 = digitalRead(sensor_1); // Sensor 1 state (Door Closed)
//   bool sensorState_2 = digitalRead(sensor_2); // Sensor 2 state (Door Open)

//   // Clear previous display content before showing new status
//   display.clearDisplay();
//   display.setCursor(0, 0);  // Reset cursor to the top-left corner

//   // Handle Door Closed State
//   if (sensorState_1) {
//     // Blink LED_Close if the door is completely closed
//     if (currentMillis - previousMillis >= interval) {
//       previousMillis = currentMillis;
//       ledState_Close = !ledState_Close;  // Toggle LED state
//       digitalWrite(LED_Close, ledState_Close);
//     }
//     digitalWrite(LED_Open, LOW);  // Ensure Open LED is OFF

//     display.println("Door Status: Completely Closed");
//   } 
//   // Handle Door Open State
//   else if (sensorState_2) {
//     // Blink LED_Open if the door is completely open
//     if (currentMillis - previousMillis >= interval) {
//       previousMillis = currentMillis;
//       ledState_Open = !ledState_Open;  // Toggle LED state
//       digitalWrite(LED_Open, ledState_Open);
//     }
//     digitalWrite(LED_Close, LOW);  // Ensure Close LED is OFF

//     display.println("Door Status: Completely Open");
//   } 
//   // Handle Undefined State (Transition/Error)
//   else {
//     digitalWrite(LED_Close, LOW);  // Ensure both LEDs are OFF
//     digitalWrite(LED_Open, LOW);

//     display.println("Door Status: In Transition");
//   }

//   display.display();  // Update the OLED display with the new information
//   delay(100);  // Small delay for debounce and stability
// }





// ------------------------------------------------------------------------------------------------------------------------------------------------------------------





#include <Wire.h>                // For I2C communication
#include <Adafruit_GFX.h>         // Core graphics library for OLED
#include <Adafruit_SSD1306.h>     // OLED display library

// OLED Display setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pin Definitions
const byte sensor_1 = 27;  // Pin D27 - Sensor_1(upper) for door closed position
const byte sensor_2 = 2;   // Pin D2 - Sensor_2(lower) for door open position
const byte LED_Close = 15; // Pin D15 - LED(green) for door closed indication
const byte LED_Open = 4;   // Pin D4 - LED(white) for door open indication

unsigned long previousMillis = 0;  // Timer for blinking LEDs
const unsigned long interval = 500; // Blink interval in milliseconds
bool ledState_Close = false;  // LED state for closed position
bool ledState_Open = false;   // LED state for open position

void setup() {
  Serial.begin(115200);          // Initialize Serial Monitor
  pinMode(sensor_1, INPUT);      // Set sensor_1 pin as input
  pinMode(sensor_2, INPUT);      // Set sensor_2 pin as input
  pinMode(LED_Close, OUTPUT);    // Set LED_Close pin as output
  pinMode(LED_Open, OUTPUT);     // Set LED_Open pin as output
  digitalWrite(LED_Close, LOW);  // Ensure LED_Close is OFF initially
  digitalWrite(LED_Open, LOW);   // Ensure LED_Open is OFF initially

  // Initialize OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);         // Text size
  display.setTextColor(SSD1306_WHITE); // Text color
  display.setCursor(0, 0);       // Set cursor to top-left
  display.println("Automatic Chicken Coop Door System Initialized");
  display.display();             // Update display
  delay(500);                    // Show initialization message for 2 seconds
}

void loop() {
  unsigned long currentMillis = millis();  // Get the current time

  // Read sensor states
  bool sensorState_1 = digitalRead(sensor_1); // Sensor 1 state (Door Closed)
  bool sensorState_2 = digitalRead(sensor_2); // Sensor 2 state (Door Open)

  // Clear previous display content before showing new status
  display.clearDisplay();
  display.setCursor(0, 0);  // Reset cursor to the top-left corner

  // Handle Door Closed State
  if (sensorState_1) {
    // Blink LED_Close if the door is completely closed
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      ledState_Close = !ledState_Close;  // Toggle LED state
      digitalWrite(LED_Close, ledState_Close);
    }
    digitalWrite(LED_Open, LOW);  // Ensure Open LED is OFF

    display.println("Door Status: Completely Closed");
    Serial.println("Door Status: Completely Closed");  // Print to Serial Monitor
  } 
  // Handle Door Open State
  else if (sensorState_2) {
    // Blink LED_Open if the door is completely open
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      ledState_Open = !ledState_Open;  // Toggle LED state
      digitalWrite(LED_Open, ledState_Open);
    }
    digitalWrite(LED_Close, LOW);  // Ensure Close LED is OFF

    display.println("Door Status: Completely Open");
    Serial.println("Door Status: Completely Open");  // Print to Serial Monitor
  } 
  // Handle Undefined State (Transition/Error)
  else {
    digitalWrite(LED_Close, LOW);  // Ensure both LEDs are OFF
    digitalWrite(LED_Open, LOW);

    display.println("Door Status: In Transition");
    Serial.println("Door Status: In Transition");  // Print to Serial Monitor
  }

  display.display();  // Update the OLED display with the new information
  delay(100);  // Small delay for debounce and stability
}


