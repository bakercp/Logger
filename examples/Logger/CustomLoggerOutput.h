#include <Arduino.h>
#include <Logger.h>
#include <pgmspace.h>

class CustomLoggerOutput
{
public:
  static void customLogger(Logger::Level level, const char* module, const char* message)
  {
    Serial.print("CustomLogger: [");

    Serial.print(Logger::asString(level));

    Serial.print("] ");

    if (strlen(module) > 0)
    {
        Serial.print(": ");
        Serial.print(module);
        Serial.print(" ");
    }

    Serial.println(message);
  }

};
