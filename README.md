# IOT Patient Fall Detection System using ESP8266


## Introduction
With increasing age, the risk of falling due to weak bones and other health conditions also increases. Immediate assistance after a fall is crucial to prevent severe health complications. The *IoT Fall Detection System* is designed to detect falls using sensors and alert caregivers in real time, ensuring timely medical intervention.

## Objective
The primary goal of this project is to develop a *wearable fall detection device* that:
- Monitors falls using motion sensors.
- Sends alerts to caregivers or emergency services.
- Provides a *real-time monitoring solution* for elderly and wheelchair users.

## Components Used
The system is built using the following components:

- *ESP8266-NODEMCU*: A Wi-Fi-enabled microcontroller for data processing and communication.
- *MPU6050*: A gyroscope and accelerometer sensor for detecting movement and orientation changes.
- *Jumper Wires*: Used to establish circuit connections.
- *Breadboard*: For prototyping the circuit.
- *Buzzer*: Alerts nearby individuals when a fall is detected.
## Circuit Diagram

![Vrnnn!!!](https://github.com/user-attachments/assets/98ffbfb5-17f8-4627-8930-b175f3b00895)


This project connects an *MPU6050 Accelerometer & Gyroscope* sensor to an *ESP8266* and triggers a *buzzer* based on sensor data.

## 🛠 Wiring Connections

### 📌 MPU6050 to ESP8266

| MPU6050 Pin | ESP8266 Pin  |
|------------|-------------|
| VCC    | 3.3V        |
| GND    | GND         |
| SDA    | D2 (GPIO4)  |
| SCL    | D1 (GPIO5)  |
| ADO    | GND         |

### 🔔 Buzzer to ESP8266

| Buzzer Pin | ESP8266 Pin  |
|------------|-------------|
| VCC        | 3.3V or 5V  |
| GND        |   GND       |
| Signal Pin | D3 (GPIO0)  |

## Notes
- Ensure the *MPU6050* is powered using *3.3V*, as using 5V might damage it.
- The *buzzer voltage* depends on the type of buzzer used. Check its specifications.
- Use *I2C scanner code* to verify if the *MPU6050* is detected correctly.

## Methodology
1. The *MPU6050 sensor* continuously monitors the user's movement.
2. The *ESP8266 microcontroller* processes the data and detects sudden falls based on pre-defined threshold values.
3. If a fall is detected, an *alert is sent* to the caregiver via a mobile notification.
4. A *buzzer is triggered* to alert people nearby.
5. The system ensures real-time monitoring to improve response times.

## Advantages
- *Immediate Emergency Response*: Notifies caregivers or emergency services in real time.
- *24/7 Monitoring*: Ensures constant tracking even when the person is alone.
- *Customizable Alerts*: Users can configure notifications based on personal needs.
- *Automatic Activation*: No need for manual intervention to trigger alerts.

## Disadvantages
- *False Positives*: Sudden movements like sitting down quickly may trigger false alerts.
- *Dependency on Connectivity*: Requires an internet connection for real-time alerts.
- *Limited Adoption*: Awareness and acceptance among elderly users may be a challenge.

## Conclusion
The *IoT Fall Detection System* is a *cost-effective, real-time solution* to monitor the elderly and wheelchair users. By integrating *motion sensors and wireless communication, it ensures that help arrives promptly in case of an emergency, reducing the risk of severe injuries. This project can significantly improve **healthcare monitoring* and provide peace of mind to caregivers.

## References
- [Smart Fall Detection System for Elderly People with IoT and Sensor](https://www.rcciit.org/students_projects/projects/ee/2021/GR9.pdf)
- [An IoT-Based System to Detect a Person/Wheelchair Fall](https://www.researchgate.net/publication/330993777_An_IoT_Based_System_to_Detect_a_PersonWheelchair_Fall)
