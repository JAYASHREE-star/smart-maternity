# 🤰 Smart Maternity – IoT-Based Maternal Health Monitoring System (ESP32 + Arduino)

**Smart Maternity** is an IoT-enabled healthcare solution built using **ESP32**, **Arduino-compatible sensors**, and real-time monitoring to assist pregnant women. The system is designed to track key health parameters, send alerts, and provide proactive maternal support using connected sensors and mobile/web interfaces.

## 🔧 Project Overview

This system continuously monitors:
- ❤️ **Heart Rate** of the mother
- 🌡️ **Body Temperature**
- 👣 **Fetal Movement Detection**
- 💧 **Hydration/Water Intake Reminders**
- 🛌 **Sleep Monitoring (optional)**

It sends data wirelessly to a cloud or mobile app, providing real-time alerts and daily summaries.

## 🛠️ Hardware Components

- ✅ **ESP32** (Wi-Fi + BLE-enabled microcontroller)
- 💓 **Pulse Sensor / MAX30100** – Heart rate monitoring
- 🌡️ **DS18B20 / DHT11** – Temperature sensing
- 🔌 **Vibration Sensor** – Fetal movement simulation
- 🔔 **Buzzer / Vibration motor** – Alert system
- 🖥️ **OLED / LCD Display** – On-device status display
- 📱 **Mobile App / Web Dashboard** (via Blynk, Firebase, or custom app)

## 🔁 Software & Tools

- Arduino IDE (for ESP32 programming)
- Blynk / Firebase / MIT App Inventor (for UI)
- C/C++ (Arduino Code)
- Optional: Python for backend/API

## 🔩 Circuit Overview

```
Sensors → ESP32 → Wi-Fi → Mobile/Web App
           ↓
        OLED/Buzzer
```

### Sample Connections:
- Pulse sensor → A0
- Temp sensor → D4
- Vibration sensor → D5
- OLED display → I2C (SDA, SCL)
- Buzzer → D2

## 💻 Project Flow

1. Sensors collect data from the pregnant individual.
2. ESP32 processes and transmits the data via Wi-Fi.
3. Data is displayed on a web/mobile dashboard in real time.
4. Alerts/reminders are triggered based on thresholds (e.g., high temperature, missed hydration).
5. Daily summaries can be logged or sent via SMS/email.
   
## 📦 Folder Structure

```
/SmartMaternity-ESP32
│
├── /ArduinoCode/           # ESP32 code
│   └── SmartMaternity.ino
├── /CircuitDiagrams/
├── /AppDesign/             # Blynk/App Inventor files
├── README.md
```

## ✅ How to Use

1. Set up your ESP32 and connect the sensors as per the diagram.
2. Flash the `SmartMaternity.ino` file using Arduino IDE.
3. Configure Wi-Fi credentials in the code.
4. Monitor data on the connected dashboard (mobile/web).
5. Receive alerts and track health metrics.

## 🚀 Future Enhancements

- Integration with wearable devices
- Machine Learning-based anomaly detection
- SMS alert via GSM module
- Multilingual voice assistant feedback

## 🙌 Credits

- Arduino Community
- Blynk/Firebase APIs
- Open-source sensor libraries

## 📃 License

MIT License – Free to use, modify, and share with attribution.

---

🎯 A smart, affordable IoT-based maternity solution for enhancing maternal care—especially in remote or underserved regions.
