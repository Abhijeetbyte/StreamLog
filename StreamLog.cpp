#include "StreamLog.h"

// Variable to keep track of whether headers are printed or not
bool headersPrinted = false;

// Constructor: Initialize variables
StreamLog::StreamLog() {
  _previousMillis = 0;
}

// Function to begin serial communication
void StreamLog::begin(uint32_t baudRate) {
  // Initialize serial communication with the specified baud rate
  Serial.begin(baudRate);
}

// Function to log data at specified intervals
void StreamLog::data(unsigned long interval, const char* sensorHeading, int sensorValue) {
  // Get the current time in milliseconds
  unsigned long currentMillis = millis();

  // Check if the specified interval has elapsed since the last log
  if (currentMillis - _previousMillis >= interval * 1000) {
    // Print headers if they haven't been printed yet
    if (!headersPrinted) {
      // Print column headers
      Serial.print("Timestamps (HH:MM:SS)");
      Serial.print(", ");                // comma for CSV format
      Serial.println(sensorHeading);     // Additional header for additional column
      // Update headersPrinted to indicate that headers are printed
      headersPrinted = true;
    }

    // Print current time in seconds
    Serial.print(currentMillis / 1000);
    Serial.print(", ");  // comma for CSV format

    // Print sensor value
    Serial.println(sensorValue);

    // Update the previousMillis variable to the current time
    _previousMillis = currentMillis;
  }
}
