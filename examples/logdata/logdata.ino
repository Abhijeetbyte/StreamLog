
/*
   StreamLog - A library for logging sensor data over Serial as CSV format.
   Author: Abhijeet Kumar
   Email: abhijeetkr.sci@gail.com
   GitHub: https://github.com/Abhijeetbyte/StreamLog.git
   Created: 24 Feb 2024

   Description:
   This library provides functionality to log sensor data over Serial communication.
   It includes functions to initialize the logger, print sensor headings, and log sensor data at specified intervals.
*/

#include "StreamLog.h"

// Create an instance of the StreamLog logger
StreamLog sensorLogger; 

// Define the pin connected to the LDR sensor
const int LDR_PIN = A0;

void setup() {
  // Initialize serial communication with a baud rate of 9600
  sensorLogger.begin(9600); 
}

void loop() {
  // Read the analog value from the LDR sensor
  int lightIntensity = analogRead(LDR_PIN);
  
  // Calculate derived sensor values
  int lightIntensityTwice = lightIntensity * 2;
  int lightIntensityThrice = lightIntensity * 3;
  
  // Log the sensor data headings, including derived values (x2 and x3)
  sensorLogger.head("Light Intensity, Light Intensity (x2), Light Intensity (x3)");

  // Log the sensor data at a specified interval with a delay between readings
  // Parameters:
  //   - 5000: Time interval between data logs in milliseconds (5 seconds)
  //   - 3: Total number of sensor readings, including the delay and derived values
  //   - lightIntensity: Current light intensity reading from the LDR sensor
  //   - lightIntensityTwice: Light intensity multiplied by 2 (derived value)
  //   - lightIntensityThrice: Light intensity multiplied by 3 (derived value)
  sensorLogger.data(5000, 3, lightIntensity, lightIntensityTwice, lightIntensityThrice);
  
  // Delay for 5 seconds before the next reading
  delay(5000);
}
