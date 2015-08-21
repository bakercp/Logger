#include <Logger.h>
#include "CustomLoggerOutput.h"


// Declare the local logger function before it is called.
void localLogger(Logger::Level level, const char* module, const char* message);


void setup()
{
  Serial.begin(115200);

  delay(1000);

  Logger::setLogLevel(Logger::WARNING);

  Logger::verbose("setup()", "This is a verbose message.");
  Logger::notice("setup()", "This is a notice message.");
  Logger::warning("setup()", "This is a warning message.");
  Logger::error("setup()", "This is a error message.");
  Logger::fatal("setup()", "This is a fatal error message.");

  Logger::setLogLevel(Logger::VERBOSE);

  // Set a custom class for logging output.
  Logger::setOutputFunction(CustomLoggerOutput::customLogger);

  Logger::verbose("setup()", "This is a verbose message.");
  Logger::notice("setup()", "This is a notice message.");
  Logger::warning("setup()", "This is a warning message.");
  Logger::error("setup()", "This is a error message.");
  Logger::fatal("setup()", "This is a fatal error message.");

  Logger::setOutputFunction(localLogger);

  Logger::verbose("setup()", "This is a verbose message.");
  Logger::notice("setup()", "This is a notice message.");
  Logger::warning("setup()", "This is a warning message.");
  Logger::error("setup()", "This is a error message.");
  Logger::fatal("setup()", "This is a fatal error message.");

}


void loop()
{
}


void localLogger(Logger::Level level, const char* module, const char* message)
{
  Serial.print(F("LocalLogger: ["));

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
