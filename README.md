# Arduino 4-Way Traffic Light System

This project simulates a **4-way traffic light system** using an Arduino board.  
Each traffic light consists of **Red, Yellow, and Green LEDs** following a real-world traffic signal logic.

## Hardware Requirements
- 1 × **Arduino Uno/Nano** or any compatible board
- 12 × **LEDs** (4 Red, 4 Yellow, 4 Green)
- 12 × **220Ω Resistors** (or equivalent)
- **Jumper wires**
- **Breadboard**

## Circuit Connections
The LEDs are connected to the Arduino pins as follows:

| Traffic Light | Red Pin | Yellow Pin | Green Pin |
|---------------|---------|------------|-----------|
| 1             | 2       | 3          | 4         |
| 2             | 5       | 6          | 7         |
| 3             | 8       | 9          | 10        |
| 4             | 11      | 12         | 13        |

## Code Explanation
- **Only one traffic light turns green at a time.**  
  The active traffic light stays green for 5 seconds.
- It then switches to yellow for 2 seconds as a warning before turning red.
- After the sequence, the next traffic light is activated.
- The cycle repeats continuously for all four directions.

## How to Use
1. **Clone this repository:**
   ```bash
   git clone https://github.com/USERNAME/Arduino-Traffic-Light.git
   cd Arduino-Traffic-Light
   ```
2. **Compile and upload the code to your Arduino board using the Arduino IDE or CLI.**  
   For example, using Arduino CLI:
   ```bash
   arduino-cli compile --fqbn arduino:avr:uno traffic_light.ino
   arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno traffic_light.ino
   ```
   *Replace `/dev/ttyUSB0` with the correct port for your Arduino board.*

## License
This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

Made with ❤️ by [Mustafa Al-Jayyashee](https://github.com/aljayyashee),,
