#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

// Wi-Fi credentials
const char* ssid = "CST WIFI";
const char* password = "iotdevs123";

// DHT sensor configuration
const int dhtPin = 4;
const int dhtType = DHT11;
DHT dht(dhtPin, dhtType);

// Web server on port 80
WebServer server(80);

// Variables for sensor data
float temperature = 0.0;
float humidity = 0.0;

// Function to read temperature and humidity, print to Serial, and format for Serial Plotter
void readAndDisplaySensorData() {
  // Read data from DHT sensor
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // Check if reading was successful
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    // Display data on Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // For Serial Plotter-friendly format
    Serial.print("Temperature:");
    Serial.print(temperature);
    Serial.print(",");
    Serial.print("Humidity:");
    Serial.println(humidity);

  }
}

// Function to handle the root request and generate HTML page
void handleRoot() {
  // Create HTML content with embedded CSS for styling
  String html = R"====(
    <!DOCTYPE html>
    <html>
    <head>
      <title>DHT11 Sensor Data</title>
      <meta http-equiv='refresh' content='2'>
      <style>
        body {
          font-family: Arial, sans-serif;
          display: flex;
          justify-content: center;
          align-items: center;
          height: 100vh;
          margin: 0;
          background: linear-gradient(135deg, #71b7e6, #9b59b6);
        }
        .container {
          background-color: #ffffff;
          border-radius: 10px;
          box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);
          padding: 20px;
          max-width: 300px;
          text-align: center;
        }
        h1 {
          color: #333;
          margin-bottom: 20px;
        }
        .reading {
          font-size: 24px;
          margin: 10px 0;
          font-weight: bold;
          color: #9b59b6;
        }
        .label {
          font-size: 18px;
          color: #555;
        }
      </style>
    </head>
    <body>
      <div class="container">
        <h1>DHT11 Sensor Readings</h1>
        <div class="reading">
          <span class="label">Humidity:</span> )====" + String(humidity) + R"====( %
        </div>
        <div class="reading">
          <span class="label">Temperature:</span> )====" + String(temperature) + R"====( &deg;C
        </div>
      </div>
    </body>
    </html>
  )====";

  // Send HTML content to client
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Display ESP32 IP address
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Initialize DHT sensor
  dht.begin();

  // Set up web server routes
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  // Read and display sensor data every 2 seconds
  readAndDisplaySensorData();
  delay(2000);

  // Handle client requests
  server.handleClient();
}
