/*
   StreamLog - A library for logging sensor data over Serial in CSV format.
   Author: Abhijeet Kumar
   Email: abhijeetkr.sci@gmail.com
   GitHub: https://github.com/Abhijeetbyte/StreamLog.git
   Created: 24 June 2024

   Description:
   This library provides functionality to log sensor data over Serial communication.
   It includes functions to initialize the logger, print sensor headings, and log sensor data at specified intervals.
   Below is an example use case with multiple sensors.
*/

#include "StreamLog.h"

// Create an instance of the StreamLog logger
StreamLog sensorLogger;

// Define pins connected to arbitrary sensors
const int X_SENSOR_PIN = A0;  // X sensor pin
const int Y_SENSOR_PIN = A1;  // Y sensor pin
const int Z_SENSOR_PIN = A2;  // Z sensor pin

void setup() {
  // Initialize serial communication with a baud rate of 9600
  sensorLogger.begin(9600);

  // Log the sensor data headings
  sensorLogger.head("X Sensor, Y Sensor, Z Sensor");  // Variable names or column headings
}

void loop() {
  // Read the analog values from the sensors
  int xSensorValue = analogRead(X_SENSOR_PIN);
  int ySensorValue = analogRead(Y_SENSOR_PIN);
  int zSensorValue = analogRead(Z_SENSOR_PIN);

  // Log the sensor data
  sensorLogger.data(300000, 3, xSensorValue, ySensorValue, zSensorValue);

  // Parameters:
  //   - 300000: Time interval between data logs in milliseconds (5 minutes)
  //   - 3: Total number of sensor readings
  //   - xSensorValue, ySensorValue, zSensorValue: readings from the sensors

  // Note: Make sure to turn on "Timestamp" in your Serial monitor
}
