# Cloud-and-Iot


### ☁️ AWS IoT Monitoring Pipeline
End-to-end cloud project integrating **IoT data**, **EC2 hosting**, **CloudWatch monitoring**, and **SNS alerts**.

- Simulated ESP32 device sending MQTT data via AWS IoT Core.  
- Hosted Apache web server on EC2 instance.  
- Configured CloudWatch alarm (CPU ≥ 20%) → triggers SNS email notification.  
- Demonstrates IoT → Cloud → Monitoring → Alert workflow.

*Tools: AWS IoT Core, EC2, CloudWatch, SNS, MQTT, ESP32 (Wokwi)*
