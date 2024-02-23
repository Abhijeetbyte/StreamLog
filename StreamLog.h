#ifndef STREAMLOG_H
#define STREAMLOG_H

#include <Arduino.h>
#include <stdarg.h>

class StreamLog {
  public:
    StreamLog();
    void begin(uint32_t baudRate);
    void data(unsigned long interval, ...);

  private:
    unsigned long _previousMillis;
    bool _headersPrinted;

    void printHeaders(va_list args);
};

#endif
