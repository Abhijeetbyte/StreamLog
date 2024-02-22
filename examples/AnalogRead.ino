#include "StreamLog.h"

StreamLog mylogger; // Initialize logger object 

int LDR_sensor = A0 ; 

void setup() {
  mylogger.begin(9600); // Initialize Serial communication
}

void loop() {
  int data1Variable = analogRead(LDR_sensor);
  
  // Example usage:
  mylogger.data(5000, "Light Intensity", data1Variable);
  // The first argument is the delay interval in milliseconds
  
}
