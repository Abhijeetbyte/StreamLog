#include "StreamLog.h"

// Variable to keep track of whether headers are printed or not
bool headersPrinted = false;

// Constructor: Initializes the StreamLog object
StreamLog::StreamLog() {
  _previousMillis = 0; // Initialize _previousMillis to 0
}

// Function to begin serial communication
void StreamLog::begin(uint32_t baudRate) {
  Serial.begin(baudRate); // Initialize serial communication with specified baud rate
}

// Function to print sensor headings
void StreamLog::head(const char* dataHeadings) {
  if (!headersPrinted) { // Check if headers are already printed
    // Print column headers
    Serial.print("Timestamps (HH:MM:SS)");
    Serial.print(", "); // comma for CSV format
    Serial.print("Elapsedtime (S)"); // Print elapsed time header
    Serial.print(", "); // comma for CSV format
    Serial.println(dataHeadings); // Print sensor headings
    headersPrinted = true; // Update headersPrinted to indicate that headers are printed
  }
}

// Function to log data at specified intervals
void StreamLog::data(unsigned long interval, int numReadings, ...) {
  unsigned long currentMillis = millis(); // Get the current time in milliseconds

  // Check if the specified interval has elapsed since the last log
  if (currentMillis - _previousMillis >= interval) {
    // Print current time in seconds
    Serial.print(", "); // comma for CSV format
    Serial.print(currentMillis / 1000); // Print current time in seconds
    Serial.print(", "); // comma for CSV format

    // Extract and print sensor values
    va_list args; // Declare a variable argument list
    va_start(args, numReadings); // Initialize the argument list
    for (int i = 0; i < numReadings; i++) {
      int sensorValue = va_arg(args, int); // Get the next sensor value from the argument list
      Serial.print(sensorValue); // Print the sensor value
      if (i < numReadings - 1) {
        Serial.print(", "); // Print comma if there are more sensor values to follow
      }
    }
    va_end(args); // Clean up the argument list

    // Move to the next line
    Serial.println();

    // Update the previousMillis variable to the current time
    _previousMillis = currentMillis;
  }
}
