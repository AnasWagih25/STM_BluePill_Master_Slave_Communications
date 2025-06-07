# STM32 Blue Pill Master-Slave 7-Segment Display Project

This project connects three STM32 Blue Pill boards in a master-slave UART communication setup.

- **Slave 1** has a push button and a 7-segment common anode display.
- **Master** receives commands from Slave 1 and controls Slave 2.
- **Slave 2** blinks an LED on PC13 when triggered by the master.
- When the button on Slave 1 is pressed once, the master blinks its onboard LED (PB2) and Slave 1 shows digit `1` on the 7-segment.
- When the button is pressed twice, the master triggers Slave 2 to blink the LED on PC13, and Slave 1 shows digit `2` on the 7-segment.

---

## Features

- UART communication between Master and Slaves
- Button debouncing and press count logic on Slave 1
- Common Anode 7-segment display controlled by Slave 1
- LED indicators on Master and Slave 2
- Simple and modular Arduino IDE code

---

## Hardware Connections (Wiring Diagram)

![STM32 Blue Pill Master-Slave Wiring Diagram](STM32_BluePill_Master-Slave.png)

**Connection details:**

**Slave 1:**

- Button connected to PB4 with internal pull-up enabled
- 7-segment display (common anode) connected to segments:
  - PB8 → Segment A
  - PB9 → Segment B
  - PB10 → Segment C
  - PB11 → Segment D
  - PB12 → Segment E
  - PB13 → Segment F
  - PB14 → Segment G
- Common anode pin connected to +3.3V

**Master:**

- Onboard LED connected to PB2
- UART RX connected to Slave 1 TX (Slave 1 PA2 → Master PA3)
- UART TX connected to Slave 2 RX (Master PB10 → Slave 2 PB11)
- UART RX connected to Slave 2 TX (Master PB11 ← Slave 2 PB10)

**Slave 2:**

- LED connected to PC13 with appropriate resistor
- UART RX connected to Master TX (Slave 2 PB11 ← Master PB10)
- UART TX connected to Master RX (Slave 2 PB10 → Master PB11)

**Power:**

- All devices share common 3.3V and GND

---

## 7-Segment Display Digit Codes (Common Anode)

```cpp
uint8_t digits[] = {
  0x40,  // 0
  0x79,  // 1
  0x24,  // 2
  0x30,  // 3
  0x19,  // 4
  0x12,  // 5
  0x02,  // 6
  0x78,  // 7
  0x00,  // 8
  0x10   // 9
};
