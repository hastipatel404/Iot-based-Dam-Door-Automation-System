# 🔌 Circuit Connections

This document describes the connections between the **Arduino UNO**, **HC-SR04 Ultrasonic Sensor**, and **SG90 Servo Motor** used in the IoT-Based Automatic Dam Gate Automation System.

---

## 🧩 Components

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- Breadboard
- Jumper wires
- Power supply

---

## 📡 HC-SR04 Connections

| HC-SR04 Pin | Arduino UNO Pin | Purpose |
|---|---|---|
| VCC | 5V | Power supply |
| GND | GND | Ground |
| TRIG | Digital Pin 9 | Sends ultrasonic pulse |
| ECHO | Digital Pin 10 | Receives reflected pulse |

---

## ⚙️ SG90 Servo Motor Connections

| SG90 Wire/Pin | Arduino UNO | Purpose |
|---|---|---|
| Signal (Orange/Yellow) | Digital Pin 6 | Servo control |
| VCC (Red) | 5V / suitable external supply | Power |
| GND (Brown/Black) | GND | Ground |

> **Important:** If an external power supply is used for the servo, connect its GND to the Arduino GND to maintain a common ground.

---

## 🔗 Complete Connection

```text
                    Arduino UNO
                  ┌───────────────┐
                  │               │
       TRIG ──────┤ D9            │
       ECHO ──────┤ D10           │
       SERVO ─────┤ D6            │
                  │               │
       VCC ───────┤ 5V            │
       GND ───────┤ GND           │
                  └───────────────┘
                       │
          ┌────────────┴────────────┐
          │                         │
     HC-SR04                    SG90 Servo
   ┌───────────┐              ┌───────────┐
   │ VCC ──────┼── 5V         │ Red ──────┼── 5V*
   │ GND ──────┼── GND        │ Brown ────┼── GND
   │ TRIG ─────┼── D9         │ Orange ───┼── D6
   │ ECHO ─────┼── D10        │           │
   └───────────┘              └───────────┘

   * Use a suitable external supply if required.
