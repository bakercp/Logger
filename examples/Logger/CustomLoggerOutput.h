#include <Logger.h>

class CustomLoggerOutput
{
public:
  static void customLogger(Logger::Level level, const char* module, const char* message)
  {
    Serial.print(F("CustomLogger: ["));

    Serial.print(Logger::asString(level));

    Serial.print(F("] "));

    if (strlen(module) > 0)
    {
        Serial.print(F(": "));
        Serial.print(module);
        Serial.print(" ");
    }

    Serial.println(message);
  }
  
};
