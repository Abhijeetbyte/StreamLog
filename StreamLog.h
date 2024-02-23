#ifndef STREAMLOG_H
#define STREAMLOG_H

#include <Arduino.h>

class StreamLog {
  public:
    // Constructor
    StreamLog();

    // Function to begin serial communication
    void begin(uint32_t baudRate);

    // Function to log data at specified intervals
    void data(unsigned long interval, const char* sensorName, int sensorValue);

  private:
    // Variable to store the previous millis() value
    unsigned long _previousMillis;
};

#endif
