// Define traffic light pins for 4 signals (Red, Yellow, Green)
int lights[4][3] = {
  {2, 3, 4},   // Signal 1 (Red, Yellow, Green)
  {5, 6, 7},   // Signal 2 (Red, Yellow, Green)
  {8, 9, 10},  // Signal 3 (Red, Yellow, Green)
  {11, 12, 13} // Signal 4 (Red, Yellow, Green)
};

// Declare time variables for each signal's green and yellow light durations
int greenTimes[4] = {5000, 5000, 5000, 5000};  // Green light durations for all 4 signals
int yellowTimes[4] = {2000, 2000, 2000, 2000}; // Yellow light durations for all 4 signals

void setup() {
  // Initialize Serial communication at 9600 baud
  Serial.begin(9600);

  // Set all traffic light pins as OUTPUT
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      pinMode(lights[i][j], OUTPUT);
    }
  }

  // Display instructions for the user in the Serial Monitor
  Serial.println("Traffic Light Controller");
  Serial.println("You can set the green and yellow light durations for each street.");
  Serial.println("To set the green time for a street, type 'green <street_number> <time_in_ms>'.");
  Serial.println("To set the yellow time for a street, type 'yellow <street_number> <time_in_ms>'.");
  Serial.println("To start the traffic light cycle, type 'start'.");
}

void loop() {
  // Check if there is incoming data in the Serial buffer
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read user input until a newline character

    // Check for 'green' command to set green light time for a specific signal
    if (input.startsWith("green")) {
      int streetNum = input.charAt(6) - '0'; // Extract street number (0-3)
      int time = input.substring(8).toInt(); // Extract time in ms
      if (streetNum >= 0 && streetNum < 4) {
        greenTimes[streetNum] = time;
        Serial.print("Green light time for Street ");
        Serial.print(streetNum + 1);
        Serial.print(" set to: ");
        Serial.println(time);
      } else {
        Serial.println("Invalid street number! Use numbers 0-3.");
      }
    }

    // Check for 'yellow' command to set yellow light time for a specific signal
    if (input.startsWith("yellow")) {
      int streetNum = input.charAt(7) - '0'; // Extract street number (0-3)
      int time = input.substring(9).toInt(); // Extract time in ms
      if (streetNum >= 0 && streetNum < 4) {
        yellowTimes[streetNum] = time;
        Serial.print("Yellow light time for Street ");
        Serial.print(streetNum + 1);
        Serial.print(" set to: ");
        Serial.println(time);
      } else {
        Serial.println("Invalid street number! Use numbers 0-3.");
      }
    }

    // Start the traffic light cycle if the user types "start"
    if (input == "start") {
      Serial.println("Starting the traffic light cycle...");
      startTrafficLightCycle();
    }
  }
}

void startTrafficLightCycle() {
  while (true) {
    for (int i = 0; i < 4; i++) {
      controlTrafficLights(i);
    }
  }
}

void controlTrafficLights(int activeStreet) {
  // Turn all signals to RED first
  for (int i = 0; i < 4; i++) {
    digitalWrite(lights[i][0], HIGH);  // RED ON
    digitalWrite(lights[i][1], LOW);   // YELLOW OFF
    digitalWrite(lights[i][2], LOW);   // GREEN OFF
  }

  // Activate GREEN for the current street
  digitalWrite(lights[activeStreet][0], LOW);  // RED OFF
  digitalWrite(lights[activeStreet][2], HIGH); // GREEN ON
  delay(greenTimes[activeStreet]); // Green light duration based on user input

  // Turn on YELLOW for the warning
  digitalWrite(lights[activeStreet][2], LOW);  // GREEN OFF
  digitalWrite(lights[activeStreet][1], HIGH); // YELLOW ON
  delay(yellowTimes[activeStreet]); // Yellow light duration based on user input

  // Turn off YELLOW before switching to next street
  digitalWrite(lights[activeStreet][1], LOW); // YELLOW OFF
}
