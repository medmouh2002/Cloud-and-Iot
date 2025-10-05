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


# Docker Course Project

Hands-on Docker project building and managing containers for a **Node.js Express API**. Covers Docker CLI, Docker Desktop, and Docker Compose.

**Project Highlights:**
- **API**: Serves JSON reviews on `GET /`, runs on port 4000, uses CORS.  
- **Docker Build & Run**: Dockerfile builds `myapp` images; containers run with port mapping.  
- **Docker Desktop**: Visual management of images and containers; cleanup via CLI/UI.  
- **Docker Compose**: Multi-service setup (`api` + `myblog`) with volume mounts and interactive sessions.  
- **Docker Hub**: Tagged images pushed and pulled; authentication and repo management demonstrated.  
- **Development**: Live-reload with nodemon; handled port and container conflicts; cleaned unused resources.  

Compact, practical Docker experience ready for deployment and experimentation.




# Smart Home Automation with Node-RED

Complete smart home project using **Node-RED** as the logic engine and an **ESP32 sensor node** (simulated in Wokwi) to monitor and control the environment in real-time.

**Project Highlights:**
- **Node-RED Dashboard**: Live gauges for Humidity, Temperature, Light, and Motion via MQTT.  
- **ESP32 Simulation**: DHT22, LDR, PIR sensors; LEDs and buzzer for actuation.  
- **Logic & Automation**: LEDs turn on when motion + low light; buzzer triggers briefly on motion.  
- **Data Flow**: ESP32 → MQTT Broker → Node-RED → Dashboard; modular, beginner-friendly design.

Real-time sensor monitoring and actuation, fully integrated in a simulated smart home environment.


# ESP32 Smart Home Monitoring

ESP32-based home automation system using **MQTT** for IoT communication. Simulates multi-sensor monitoring with real-time remote updates.

**Project Highlights:**
- **Sensors & Actuators**: DHT22 (temperature/humidity), PIR motion sensor, LDR (light), LEDs, buzzer.  
- **MQTT Integration**: Publishes temperature, humidity, light, and motion data to a public broker.  
- **Smart Automation**: LEDs turn on when dark + motion detected; buzzer alerts on motion.  
- **Realtime Monitoring**: Serial output and 5-second data updates; modular, beginner-friendly design.

Compact ESP32 IoT project for environmental monitoring and automation.






