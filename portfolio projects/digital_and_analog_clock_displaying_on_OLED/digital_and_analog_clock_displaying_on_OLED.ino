#include <Wire.h>                // I2C communication
#include <Adafruit_GFX.h>        // OLED graphics library
#include <Adafruit_SSD1306.h>    // OLED driver
#include <WiFi.h>                // WiFi library
#include "time.h"                // Time library

// WiFi credentials
const char* ssid = "CST WIFI";
const char* password = "iotdevs123";

// NTP settings
const char* ntpServer1 = "pool.ntp.org";
const char* ntpServer2 = "time.nist.gov";
const long gmtOffset_sec = 18000;  // GMT+5 for Pakistan
const int daylightOffset_sec = 0; // No daylight saving

// OLED display setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Analog clock parameters
const int NUM_POINTS = 60;
const int RADIUS = 28;
int pointsX[NUM_POINTS];
int pointsY[NUM_POINTS];

// Time variables
int hrs = 0, mins = 0, secs = 0;

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" CONNECTED");

  // Configure NTP
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }
  display.clearDisplay();
  display.display();

  // Precompute clock face points
  for (int i = 0; i < NUM_POINTS; i++) {
    pointsX[i] = 96 + RADIUS * cos(i * 6.28 / NUM_POINTS);
    pointsY[i] = 32 + RADIUS * sin(i * 6.28 / NUM_POINTS);
  }
}

void loop() {
  // Update local time
  setLocalTime();

  // Clear the display
  display.clearDisplay();

  // Draw digital clock on the left
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 5);
  display.printf("Time:");

  // Print the time in HH:MM:SS format
  display.setCursor(5, 20);
  display.printf("%02d:%02d:%02d", hrs, mins, secs);

  // Draw the analog clock
  drawAnalogClock();

  // Update the display
  display.display();
  delay(1000);  // Refresh every second
}

void drawAnalogClock() {
  // Calculate hand angles
  float secAngle = map(secs, 0, 60, 0, 360);
  float minAngle = map(mins, 0, 60, 0, 360);
  float hrAngle = map(hrs % 12, 0, 12, 0, 360);

  // Calculate hand positions
  int hrX = 96 + (RADIUS - 10) * cos((hrAngle - 90) * PI / 180);
  int hrY = 32 + (RADIUS - 10) * sin((hrAngle - 90) * PI / 180);
  int minX = 96 + (RADIUS - 5) * cos((minAngle - 90) * PI / 180);
  int minY = 32 + (RADIUS - 5) * sin((minAngle - 90) * PI / 180);
  int secX = 96 + RADIUS * cos((secAngle - 90) * PI / 180);
  int secY = 32 + RADIUS * sin((secAngle - 90) * PI / 180);

  // Draw the clock face
  display.drawCircle(96, 32, RADIUS, WHITE);  // Clock outline
  for (int i = 0; i < NUM_POINTS; i += 5) {
    display.fillCircle(pointsX[i], pointsY[i], 1, WHITE);  // Hour markers
  }

  // Draw clock hands
  display.drawLine(96, 32, hrX, hrY, WHITE);  // Hour hand
  display.drawLine(96, 32, minX, minY, WHITE);  // Minute hand
  display.drawLine(96, 32, secX, secY, WHITE);  // Second hand

  // Draw clock center
  display.fillCircle(96, 32, 2, WHITE);
}

void setLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }
  hrs = timeinfo.tm_hour;
  mins = timeinfo.tm_min;
  secs = timeinfo.tm_sec;
}













// #include <Wire.h> // I2C communication
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
// #include <WiFi.h>
// #include <time.h>

// // Wi-Fi credentials
// const char* ssid = "CST WIFI";
// const char* password = "iotdevs123";

// // NTP settings
// const char* ntpServer = "pool.ntp.org";
// const long gmtOffset_sec = 18000; // GMT+5 (Pakistan Standard Time)
// const int daylightOffset_sec = 0; // No daylight saving time in Pakistan

// // Display settings
// Adafruit_SSD1306 display(128, 64, &Wire, -1);

// const int NUM_POINTS = 60;
// const int RADIUS = 28;

// int pointsX[NUM_POINTS];
// int pointsY[NUM_POINTS];

// // Time variables
// int hrs = 0;
// int mins = 0;
// int secs = 0;

// void setup() {
//   Serial.begin(115200);

//   // Connect to Wi-Fi
//   Serial.printf("Connecting to Wi-Fi: %s\n", ssid);
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\nWi-Fi Connected!");
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.localIP());

//   // Configure NTP
//   configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

//   // Initialize the display
//   if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
//     Serial.println("SSD1306 allocation failed");
//     while (1); // Stop execution if the display initialization fails
//   }
//   display.clearDisplay();
//   display.display();

//   // Precompute clock face points
//   for (int i = 0; i < NUM_POINTS; i++) {
//     pointsX[i] = 64 + RADIUS * cos(i * 6.28 / NUM_POINTS);
//     pointsY[i] = 32 + RADIUS * sin(i * 6.28 / NUM_POINTS);
//   }
// }

// void loop() {
//   updateTime();
//   drawClock();
//   delay(1000);
// }

// void updateTime() {
//   struct tm timeinfo;
//   if (!getLocalTime(&timeinfo)) {
//     Serial.println("Failed to obtain time from NTP.");
//     return;
//   }
//   hrs = timeinfo.tm_hour;
//   mins = timeinfo.tm_min;
//   secs = timeinfo.tm_sec;
//   Serial.printf("Time: %02d:%02d:%02d\n", hrs, mins, secs);
// }

// void drawClock() {
//   // Calculate hand positions
//   float secAngle = map(secs, 0, 60, 0, 360);
//   float minAngle = map(mins, 0, 60, 0, 360);
//   float hrAngle = map(hrs % 12, 0, 12, 0, 360); // Handle 24-hour format

//   int hrX = 64 + (RADIUS - 11) * cos((hrAngle - 90) * PI / 180);
//   int hrY = 32 + (RADIUS - 11) * sin((hrAngle - 90) * PI / 180);
//   int minX = 64 + (RADIUS - 6) * cos((minAngle - 90) * PI / 180);
//   int minY = 32 + (RADIUS - 6) * sin((minAngle - 90) * PI / 180);
//   int secX = 64 + (RADIUS)*cos((secAngle - 90) * PI / 180);
//   int secY = 32 + (RADIUS)*sin((secAngle - 90) * PI / 180);

//   // Clear the display
//   display.clearDisplay();

//   // Draw the clock face
//   display.drawCircle(64, 32, RADIUS, WHITE);
//   for (int i = 0; i < NUM_POINTS; i += 5) {
//     display.fillCircle(pointsX[i], pointsY[i], 1, WHITE);
//   }

//   // Draw hands
//   display.drawLine(64, 32, hrX, hrY, WHITE);  // Hour hand
//   display.drawLine(64, 32, minX, minY, WHITE); // Minute hand
//   display.drawLine(64, 32, secX, secY, WHITE); // Second hand
//   display.drawCircle(secX, secY, 2, WHITE); // Second hand tip

//   // Draw clock center
//   display.fillCircle(64, 32, 2, WHITE);

//   // Update the display
//   display.display();
// }







