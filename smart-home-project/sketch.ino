#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>  // Include the DHT sensor library

// WiFi credentials for Wokwi's virtual network
const char* ssid = "Wokwi-GUEST";   // Wokwi's virtual WiFi network
const char* password = "";          // No password for wokwi_GUEST

// MQTT broker details (use your actual MQTT broker address)
const char* mqtt_server = "test.mosquitto.org";  // Public MQTT broker
WiFiClient espClient;
PubSubClient client(espClient);

// Topics for MQTT
const char* temp_topic = "home/temperature";
const char* humidity_topic = "home/humidity";
const char* light_topic = "home/light";
const char* motion_topic = "home/motion";

// Sensor and pin definitions
#define DHTPIN 15       // Pin connected to the DHT sensor
#define DHTTYPE DHT22   // Specify the type of DHT sensor
#define PIR_PIN 27      // PIR sensor on GPIO27
#define LDR_PIN 34      // LDR sensor on GPIO34
#define LED1_PIN 16     // LED1 on GPIO16
#define LED2_PIN 17     // LED2 on GPIO17
#define BUZZER_PIN 26   // Buzzer on GPIO26

DHT dht(DHTPIN, DHTTYPE);  // Create an instance of the DHT sensor

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  dht.begin();  // Initialize the DHT sensor

  // Initialize pins
  pinMode(PIR_PIN, INPUT);  // Initialize PIR sensor pin as input
  pinMode(LED1_PIN, OUTPUT);  // Initialize LED1 pin as output
  pinMode(LED2_PIN, OUTPUT);  // Initialize LED2 pin as output
  pinMode(BUZZER_PIN, OUTPUT);  // Initialize Buzzer pin as output

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");

  // Connect to MQTT broker (Node-RED)
  client.setServer(mqtt_server, 1883);  // Connect to MQTT on port 1883
  connectToMQTT();
}

void loop() {
  // Reconnect to MQTT if the connection is lost
  if (!client.connected()) {
    connectToMQTT();
  }
  client.loop();  // Maintain MQTT connection

  // Read sensors
  float temperature = dht.readTemperature();   // Read temperature in Celsius
  float humidity = dht.readHumidity();         // Read humidity
  int lightLevel = analogRead(LDR_PIN);        // Read light level from LDR (0 to 1023)
  int motionDetected = digitalRead(PIR_PIN);   // Read PIR sensor value

  // Print sensor data to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.print(" %, Light level: ");
  Serial.println(lightLevel);

  // Debugging: Print PIR status
  if (motionDetected) {
    Serial.println("Motion detected!");
  } else {
    Serial.println("No motion detected.");
  }

  // Control LEDs based on light level and motion detection
  if (lightLevel < 3500 && motionDetected) {  // Increased threshold for light level
    digitalWrite(LED1_PIN, HIGH);  // Turn on LED1
    digitalWrite(LED2_PIN, HIGH);  // Turn on LED2
    Serial.println("LEDs are ON");
  } else {
    digitalWrite(LED1_PIN, LOW);   // Turn off LED1
    digitalWrite(LED2_PIN, LOW);   // Turn off LED2
    Serial.println("LEDs are OFF");
  }

  // Trigger buzzer when motion is detected
  if (motionDetected) {
    digitalWrite(BUZZER_PIN, HIGH);  // Turn on buzzer
    delay(500);  // Buzzer on for 500ms
    digitalWrite(BUZZER_PIN, LOW);   // Turn off buzzer
    Serial.println("Buzzer triggered");
  }

  // Publish data to MQTT
  // Ensure data is correctly formatted and transmitted
  client.publish(temp_topic, String(temperature).c_str());
  client.publish(humidity_topic, String(humidity).c_str());
  client.publish(light_topic, String(lightLevel).c_str());
  client.publish(motion_topic, motionDetected ? "1" : "0");

  delay(5000);  // Publish data every 5 seconds
}

void connectToMQTT() {
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP32Client")) {  // Use a unique client ID
      Serial.println("Connected to MQTT broker!");
    } else {
      Serial.print("Failed to connect, retrying in 5 seconds...");
      delay(5000);
    }
  }
}
