#include <Logger.h>
#include "CustomLoggerOutput.h"


void setup()
{
  Serial.begin(115200);

  Logger::setLogLevel(Logger::WARNING);

  Logger::verbose("setup()", "This is a verbose message.");
  Logger::notice("setup()", "This is a notice message.");
  Logger::warning("setup()", "This is a warning message.");
  Logger::error("setup()", "This is a error message.");
  Logger::fatal("setup()", "This is a fatal error message.");

  Logger::setLogLevel(Logger::VERBOSE);

  // Set a custom class for logging output.
  Logger::setOutputFunction(CustomLoggerOutput::log);

  Logger::verbose("setup()", "This is a verbose message.");
  Logger::notice("setup()", "This is a notice message.");
  Logger::warning("setup()", "This is a warning message.");
  Logger::error("setup()", "This is a error message.");
  Logger::fatal("setup()", "This is a fatal error message.");

}


void loop()
{
}

