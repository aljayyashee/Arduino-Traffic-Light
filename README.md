# Arduino 4-Way Traffic Light System

This project simulates a **4-way traffic light system** using an Arduino.
Each traffic light consists of **Red, Yellow, and Green LEDs** following a standard traffic light pattern.

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
- **Serial Interface Control**:
  - You can now **set independent green and yellow timings** for each street using the serial interface.
  - The program will allow you to customize the green and yellow light durations for each street individually.
  
- **How to Use**:
  1. **Upload the Code**: Upload the provided `TrafficLightController.ino` file to your Arduino board.
  2. **Open Serial Monitor**: Open the Serial Monitor in the Arduino IDE (set the baud rate to 9600).
  
  3. **Set Green and Yellow Light Durations**:
     - To set the **green light duration** for a street, use:
       ```
       green <street_number> <time_in_ms>
       ```
       For example, to set the green light for street 1 to 5000 milliseconds (5 seconds):
       ```
       green 0 5000
       ```

     - To set the **yellow light duration** for a street, use:
       ```
       yellow <street_number> <time_in_ms>
       ```
       For example, to set the yellow light for street 2 to 2000 milliseconds (2 seconds):
       ```
       yellow 1 2000
       ```

  4. **Start the Traffic Cycle**:
     - To start the traffic light cycle, type:
       ```
       start
       ```

## Example Commands:
- Set green light for street 1 to 6 seconds:
  ```
  green 0 6000
  ```
- Set yellow light for street 3 to 3 seconds:
  ```
  yellow 2 3000
  ```

## License
This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more information.

---

Made by [Mustafa Al-Jayyashee](https://github.com/aljayyashee)
