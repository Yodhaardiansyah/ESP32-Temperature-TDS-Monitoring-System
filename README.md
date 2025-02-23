# **ESP32 Temperature & TDS Monitoring System**  

🚀 **A real-time monitoring system using ESP32, DS18B20 Temperature Sensor, and TDS Sensor**  

## 📌 **Project Overview**  
This project uses an **ESP32** to monitor **water temperature** and **TDS (Total Dissolved Solids) levels**, making it ideal for **aquaponics, hydroponics, or water quality monitoring**.  

### 🎯 **Features:**  
✅ Reads **water temperature** using the **DS18B20 sensor**  
✅ Measures **TDS levels** using an **analog TDS sensor**  
✅ **ESP32 ADC (12-bit resolution)** for accurate voltage reading  
✅ Serial Monitor output for real-time monitoring  

---

## 🛠️ **Hardware Requirements**  
| Component       | Description                        |
|---------------|--------------------------------|
| ESP32 Board   | Microcontroller with WiFi & Bluetooth  |
| DS18B20       | Digital Temperature Sensor |
| TDS Sensor    | Measures Total Dissolved Solids |
| 4.7kΩ Resistor | Required for DS18B20 Pull-up |
| Jumper Wires  | For wiring connections |

---

## 📜 **Wiring Diagram**  

| **ESP32 Pin** | **Component**  | **Description** |
|--------------|---------------|----------------|
| GPIO 15      | DS18B20 (DATA) | Temperature Sensor |
| GPIO 4       | TDS Sensor (A0) | Analog TDS Input |
| 3.3V         | DS18B20 & TDS  | Power Supply |
| GND          | DS18B20 & TDS  | Ground Connection |

---

## 📄 **Code Explanation**  
### **1️⃣ Read Temperature from DS18B20**
- Uses the **DallasTemperature** library.
- Requests temperature data.
- Converts it into **Celsius**.

### **2️⃣ Measure TDS Levels**
- Reads **analog voltage** from the TDS sensor.
- Converts voltage into **ppm (parts per million)**.
- Uses a **TDS factor** for calibration.

---

## 📦 **Installation & Setup**  
### **🔧 Required Libraries**  
Before uploading the code, install these libraries:  
✅ **OneWire** – For DS18B20 Communication  
✅ **DallasTemperature** – For Temperature Reading  

📌 **Install via Arduino IDE:**  
1. Open **Arduino IDE**  
2. Go to **Sketch > Include Library > Manage Libraries**  
3. Search & install:  
   - **OneWire**  
   - **DallasTemperature**  

---

## 🚀 **Getting Started**  
1️⃣ **Connect all components** as per the wiring diagram.  
2️⃣ **Upload the provided code** to the ESP32.  
3️⃣ Open **Serial Monitor** (115200 baud rate) to view readings.  

---

## 📊 **Expected Output**  
```plaintext
ESP32 Temperature & TDS Monitoring Initialized.
Temperature: 27.5 °C
TDS Value: 450 ppm
```

---

## 📜 **License & Credits**  
🔹 Developed by: **Yodha Ardiansyah**  
🔹 Website: [arunovasi.my.id](https://arunovasi.my.id)  
🔹 Open-source for educational & research purposes 🎓  

---

🔥 **Now your ESP32 is ready to monitor water quality in real-time!** 🚀
