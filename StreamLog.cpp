#include "StreamLog.h"
#include <stdarg.h>

StreamLog::StreamLog() {
  _previousMillis = 0;
}

void StreamLog::begin(uint32_t baudRate) {
  Serial.begin(baudRate);
}

void StreamLog::data(unsigned long interval, ...) {
  unsigned long currentMillis = millis();
  if (currentMillis - _previousMillis >= interval * 1000) {
    va_list args;
    va_start(args, interval);

    // Print timestamp in seconds
    Serial.print(currentMillis / 1000);
    Serial.print(", ");

    // Print Elapsedtime header
    Serial.print("Elapsedtime (s), ");

    // Print sensor name
    Serial.print(va_arg(args, const char*));
    Serial.print(", ");

    // Print sensor value
    Serial.print(va_arg(args, int));

    Serial.println();
    
    va_end(args);

    _previousMillis = currentMillis;
  }
}
