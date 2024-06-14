/*
   StreamLog - A library for logging sensor data over Serial in CSV format.
   Author: Abhijeet Kumar
   Email: abhijeetkr.sci@gmail.com
   GitHub: https://github.com/Abhijeetbyte/StreamLog.git
   Created: 24 Feb 2024

   Description:
   This library provides functionality to log sensor data over Serial communication.
   It includes functions to initialize the logger, print sensor headings, and log sensor data at specified intervals.
   Below is an example use case with an LDR sensor on pin A0.
*/

#include "StreamLog.h"

// Create an instance of the StreamLog logger
StreamLog sensorLogger;

// Define the pin connected to the LDR sensor
const int LDR_PIN = A0;

void setup() {
  // Initialize serial communication with a baud rate of 9600
  sensorLogger.begin(9600);

  // Log the sensor data headings
  sensorLogger.head("Light Intensity"); // Variable name or column heading
}

void loop() {
  // Read the analog value from the LDR sensor
  int lightIntensity = analogRead(LDR_PIN);

  // Log the sensor data
  sensorLogger.data(300000, 1, lightIntensity);

  // Parameters:
  //   - 300000: Time interval between data logs in milliseconds (5 minutes)
  //   - 1: Total number of sensor readings
  //   - lightIntensity: Current light intensity reading from the LDR sensor

  // Note: Make sure to turn on "Timestamp" in your Serial monitor
}
