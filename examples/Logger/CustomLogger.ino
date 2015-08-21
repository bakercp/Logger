void theLog(Logger::Level level, const char* module, const char* message)
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
