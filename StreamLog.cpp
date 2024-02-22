
#include "StreamLog.h"
#include <stdarg.h>

StreamLog::StreamLog() {
  _previousMillis = 0;
  _headersPrinted = false;
}

void StreamLog::begin(uint32_t baudRate) {
  Serial.begin(baudRate);
}

void StreamLog::data(unsigned long interval, ...) {
  unsigned long currentMillis = millis();
  if (!_headersPrinted) {
    va_list headerArgs;
    va_start(headerArgs, interval);
    const char* name;

    while ((name = va_arg(headerArgs, const char*)) != NULL) {
      Serial.print(name);
      Serial.print(", ");
    }
    Serial.println();
    va_end(headerArgs);
    
    _headersPrinted = true;
  }
  
  if (currentMillis - _previousMillis >= interval * 1000) {
    va_list args;
    va_start(args, interval);

    const char* name;
    int value;
    while ((name = va_arg(args, const char*)) != NULL) {
      value = va_arg(args, int);
      Serial.print(value);
      Serial.print(", ");
    }
    Serial.println();
    
    va_end(args);

    _previousMillis = currentMillis;
  }
}
