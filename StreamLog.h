
#ifndef STREAMLOG_H
#define STREAMLOG_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class StreamLog {
  public:
    StreamLog(); // Constructor
    void begin(uint32_t baudRate);
    void data(unsigned long interval, ...);

  private:
    uint32_t _previousMillis;
    bool _headersPrinted;
};

#endif
