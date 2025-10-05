#define BLYNK_TEMPLATE_ID "TMPL2Tmz_c_Gr"
#define BLYNK_TEMPLATE_NAME "home automation"
#define BLYNK_AUTH_TOKEN "5z6THmaEYdcMjFMLXp9xKB2ogC7aUsJq"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHTesp.h>  // Include DHTesp for handling DHT sensor

// Wi-Fi credentials
const char* ssid = "Wokwi-GUEST";   // Wokwi's virtual WiFi network
const char* password = "";

// Sensor and pin definitions
#define DHT_PIN 15       // Pin connected to the DHT sensor
#define LDR_PIN 34       // Pin connected to the LDR sensor
#define LED1_PIN 16      // First LED
#define LED2_PIN 17      // Second LED

DHTesp dht;
BlynkTimer timer;

// Store previous states for comparison
float lastTemperature = -1;
float lastHumidity = -1;
int lastLightLevel = -1;

// Function to read and send sensor data
void updateSensors() {
  // Read temperature and humidity
  TempAndHumidity data = dht.getTempAndHumidity();
  float temperature = data.temperature;
  float humidity = data.humidity;

  // Read light level
  int lightLevel = analogRead(LDR_PIN);

  // Send data to Blynk only if it changes
  if (!isnan(temperature) && temperature != lastTemperature) {
    Blynk.virtualWrite(V1, temperature);  // Send temperature to V1
    Serial.print("Temperature: ");
    Serial.println(temperature);
    lastTemperature = temperature;
  }

  if (!isnan(humidity) && humidity != lastHumidity) {
    Blynk.virtualWrite(V2, humidity);  // Send humidity to V2
    Serial.print("Humidity: ");
    Serial.println(humidity);
    lastHumidity = humidity;
  }

  if (lightLevel != lastLightLevel) {
    Blynk.virtualWrite(V3, lightLevel);  // Send light level to V3
    Serial.print("Light Level: ");
    Serial.println(lightLevel);
    lastLightLevel = lightLevel;
  }

  // Control LEDs based on light level
  if (lightLevel < 2000) {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    Serial.println("LEDs are ON");
  } else {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    Serial.println("LEDs are OFF");
  }
}

void setup() {
  // Debug console
  Serial.begin(115200);

  // Initialize DHT sensor
  dht.setup(DHT_PIN, DHTesp::DHT22);

  // Initialize LEDs
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);

  // Set up a timer to update sensors every second
  timer.setInterval(1000L, updateSensors);  // Update every 1 second
}

void loop() {
  Blynk.run();
  timer.run();  // Handle BlynkTimer
}
