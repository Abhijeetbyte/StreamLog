#ifndef STREAMLOG_H
#define STREAMLOG_H

#include <Arduino.h>
#include <stdarg.h>

class StreamLog {
public:
  // Constructor: Initializes the StreamLog object
  StreamLog();

  // Function to begin serial communication
  void begin(uint32_t baudRate);

  // Function to print sensor headings
  void head(const char* dataHeadings);

  // Function to log data at specified intervals
  // Parameters:
  //   - interval: time interval between data logs in milliseconds
  //   - numReadings: total number of sensor readings (including delay)
  //   - ...: variable number of sensor readings
  void data(unsigned long interval, int numReadings, ...);

private:
  unsigned long _previousMillis; // Variable to store the previous timestamp
};

#endif
