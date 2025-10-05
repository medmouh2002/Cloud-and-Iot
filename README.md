# 🏠 IoT & Smart Home Projects

This repository contains a curated collection of **IoT and home automation projects** using ESP32, Node-RED, MQTT, Docker, and AWS. Each folder represents a stand-alone project or simulation with modular, beginner-friendly code and real-time monitoring capabilities.

---

## 📚 Project Guides

### 1. **ESP32 Home Automation System** (`ESP32_Home_Automation`)  
Simulation of a smart home system using **ESP32** and **Blynk IoT platform**, built for **Wokwi**. Monitors environmental conditions and controls actuators automatically.  

**Key Concepts Explored:**  
- Sensor integration: DHT22, PIR, LDR, LEDs, buzzer  
- IoT data transfer to Blynk virtual pins  
- Automated LED control based on ambient light  
- Real-time monitoring via Serial Monitor  

**Files:** `sketch.ino`, `diagram.json`, `libraries.txt`, `wokwi-project.txt`  

---

### 2. **Docker Crash Course Project** (`docker_course_pics`)  
Hands-on project to **build, run, and manage Docker containers** for a Node.js Express API. Covers CLI, Docker Desktop, and Docker Compose workflows.  

**Key Concepts Explored:**  
- Dockerfile & image building (`myapp:latest`)  
- Container management with port mapping (`docker run`)  
- Docker Desktop UI for images and containers  
- Multi-service setup using `docker-compose.yaml`  
- Pushing/pulling images to/from Docker Hub  

**Files:** `api/app.js`, `api/package.json`, `Dockerfile`, `.dockerignore`, `docker-compose.yaml`  

---

### 3. **Node-RED Smart Home Dashboard** (`smart_home_with_nodered`)  
Complete home automation with **Node-RED** and **ESP32 simulation**. Provides a live dashboard for environmental monitoring and actuation via MQTT.  

**Key Concepts Explored:**  
- Node-RED flows for Humidity, Temperature, Light, Motion  
- MQTT input/output nodes for sensor communication  
- Modular design for easy expansion  
- Automated actuators: LEDs & buzzer controlled by sensor logic  

**Files:** `sketch.ino` (ESP32 simulation), Node-RED flow JSON, dashboard configuration  

---

### 4. **ESP32 Smart Home Monitoring** (`ESP32_Smart_Home_Monitoring`)  
ESP32 project using **MQTT** to monitor temperature, humidity, light, and motion. Automates LEDs and buzzer based on sensor conditions.  

**Key Concepts Explored:**  
- MQTT-based IoT data publishing (`home/temperature`, `home/humidity`, `home/light`, `home/motion`)  
- Smart automation logic: LEDs on when dark + motion, buzzer alerts  
- Real-time serial monitoring every 5 seconds  
- Multi-sensor environmental tracking  

**Files:** `sketch.ino`, `diagram.json`, `libraries.txt`, `wokwi-project.txt`  

---

### 5. **IoT Home Security System with AWS** (`IoT_Home_Security_AWS`)  
Full IoT security system integrating **ESP32 sensors**, **AWS DynamoDB**, **Lambda**, **SNS**, and a **Flask web dashboard**. Detects intrusions and sends real-time alerts.  

**Key Concepts Explored:**  
- Sensors: DHT22, PIR, LDR, door/window contacts  
- AWS cloud: DynamoDB storage, Lambda alarms, SNS email notifications, EC2-hosted Flask API  
- Dashboard: Live charts using Chart.js  
- Automation: Motion + open door triggers alarm with email notifications  
- Containerized deployment with Docker  

**Files:** `app.py`, `analyze_sensor_data.py`, `db.py`, `dashboard.js`, `index.html`  

---

## 🛠️ Common Tools & Technologies

- **Hardware & Simulation:** ESP32, DHT22, PIR, LDR, LEDs, buzzer, Wokwi  
- **IoT & Communication:** MQTT, Blynk, Node-RED  
- **Cloud & Backend:** AWS DynamoDB, Lambda, SNS, EC2, Flask, Docker  
- **Visualization & Dashboards:** Node-RED UI, Chart.js  
- **Development Tools:** Arduino IDE, Docker Desktop, VS Code  

---

## 🔮 Next Steps / Enhancements

- **Advanced IoT Logic:** Integrate AI-based sensor prediction or anomaly detection  
- **Expanded Cloud Features:** Use AWS IoT Core, S3, or real-time dashboards  
- **Mobile App Integration:** Enable smartphone alerts and controls  
- **Security Enhancements:** Add encryption for MQTT and API endpoints  
- **Portfolio Presentation:** Add screenshots, GIFs, or live demos for each project  
