// =============================================================================
//
// Copyright (c) 2013-2016 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#pragma once


#include "Arduino.h"

#if defined(ARDUINO_ARCH_AVR)
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif

class Logger
{
public:
    enum Level
    {
        VERBOSE = 0,
        NOTICE,
        WARNING,
        ERROR,
        FATAL,
        SILENT
    };

    typedef void (*LoggerOutputFunction)(Level level,
                                         const char* module,
                                         const char* message);

    static void setLogLevel(Level level);

    static Level getLogLevel();

    static void verbose(const char* message);
    static void notice(const char* message);
    static void warning(const char* message);
    static void error(const char* message);
    static void fatal(const char* message);

    static void verbose(const char* module, const char* message);
    static void notice(const char* module, const char* message);
    static void warning(const char* module, const char* message);
    static void error(const char* module, const char* message);
    static void fatal(const char* module, const char* message);

    static void log(Level level, const char* message);

    static void log(Level level, const char* module, const char* message);

    static void setOutputFunction(LoggerOutputFunction loggerOutputFunction);

    static Logger& getInstance();

    static const char* asString(Level level);

private:
    Logger();
    Logger(const Logger&);
    void operator = (const Logger&);

    static void defaultLog(Level level, const char* module, const char* message);

    Level _level;

    LoggerOutputFunction _loggerOutputFunction;

};
