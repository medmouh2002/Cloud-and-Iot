# Cloud-and-Iot


### ☁️ AWS IoT Monitoring Pipeline
End-to-end cloud project integrating **IoT data**, **EC2 hosting**, **CloudWatch monitoring**, and **SNS alerts**.

- Simulated ESP32 device sending MQTT data via AWS IoT Core.  
- Hosted Apache web server on EC2 instance.  
- Configured CloudWatch alarm (CPU ≥ 20%) → triggers SNS email notification.  
- Demonstrates IoT → Cloud → Monitoring → Alert workflow.

*Tools: AWS IoT Core, EC2, CloudWatch, SNS, MQTT, ESP32 (Wokwi)*

# Blynk project

A simple **ESP32-based Home Automation System** simulation for **[Wokwi](https://wokwi.com/)**. Monitors temperature, humidity, and light, and controls LEDs via the **Blynk IoT platform**.

**Files:**
- `diagram.json` – circuit layout (ESP32, DHT22, PIR, LDR, LEDs, buzzer)
- `libraries.txt` – required Arduino libraries
- `sketch.ino` – main code: reads sensors, updates Blynk, controls LEDs
- `wokwi-project.txt` – project metadata

**Features:**
- Real-time sensor monitoring  
- Automatic LED control  
- IoT integration via Blynk  

Lightweight, modular, and ready to simulate in Wokwi.

