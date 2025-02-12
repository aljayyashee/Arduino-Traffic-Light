// Define traffic light pins for 4 signals
int lights[4][3] = {
  {2, 3, 4},   // Signal 1 (Red, Yellow, Green)
  {5, 6, 7},   // Signal 2 (Red, Yellow, Green)
  {8, 9, 10},  // Signal 3 (Red, Yellow, Green)
  {11, 12, 13} // Signal 4 (Red, Yellow, Green)
};

void setup() {
  // Set all traffic light pins as OUTPUT
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      pinMode(lights[i][j], OUTPUT);
    }
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    controlTrafficLight(i);
  }
}

void controlTrafficLight(int activeSignal) {
  // Turn all signals to RED first
  for (int i = 0; i < 4; i++) {
    digitalWrite(lights[i][0], HIGH);  // RED ON
    digitalWrite(lights[i][1], LOW);   // YELLOW OFF
    digitalWrite(lights[i][2], LOW);   // GREEN OFF
  }

  // Activate GREEN for the current signal
  digitalWrite(lights[activeSignal][0], LOW);  // RED OFF
  digitalWrite(lights[activeSignal][2], HIGH); // GREEN ON
  delay(5000); // Green time (5 seconds)

  // Turn on YELLOW for warning
  digitalWrite(lights[activeSignal][2], LOW);  // GREEN OFF
  digitalWrite(lights[activeSignal][1], HIGH); // YELLOW ON
  delay(2000); // Yellow time (2 seconds)

  // Turn YELLOW off before switching to next signal
  digitalWrite(lights[activeSignal][1], LOW); // YELLOW OFF
}
