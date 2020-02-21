#include "../include/Logger.h"
#include <FEHUtility.h>
#include <FEHLCD.h>
#include <stdio.h>
#include <string.h>
using namespace util;

Logger::Logger(LogLevel logLevel) {
  this->file = nullptr;
  this->logLevel = logLevel;
}

void Logger::open(const TCHAR* fileName) {
  // Open the file
  file = SD.FOpen(fileName, "w");
  // Print out the header
  SD.FPrintf(file, "LOGGING STARTED AT %d\n", TimeNowMSec());
  SD.FPrintf(file, "----------------------------------------\n");
}

void Logger::close() {
  SD.FClose(file);
}

void Logger::setLogLevel(LogLevel logLevel) {
  this->logLevel = logLevel;
}

void Logger::printLine(char* str) {
  // Print to the log file if opened
  if (file != nullptr) {
    SD.FPrintf(file, str);
    // Print a new line
    SD.FPrintf(file, "\n");
  }
}

void Logger::telemetry(const char* format, ...) {
  // Format the telemetry data
  va_list args;
  va_start(args, format);
  vsnprintf(buffer, sizeof(buffer), format, args);
  va_end(args);
  // Print to the screen
  LCD.WriteLine(buffer);
}

void Logger::log(LogLevel level, const char* format, va_list args) {
  // Print out the timestamp
  sprintf(buffer, "%ld ", TimeNowMSec());
  // Print out the log level
  switch (level) {
    case Debug:
      sprintf(buffer + strlen(buffer), "DEBUG - ");
      break;
    case Info:
      sprintf(buffer + strlen(buffer), "INFO - ");
      break;
    case Warn:
      sprintf(buffer + strlen(buffer), "WARN - ");
      break;
    case Error:
      sprintf(buffer + strlen(buffer), "ERROR - ");
      break;
  }
  // Print the formatted string
  vsprintf(buffer + strlen(buffer), format, args);
  // Print to the file
  if (level >= logLevel) {
    printLine(buffer);
  }
}

void Logger::debug(const char* format, ...) {
  va_list args;
  va_start(args, format);
  log(Debug, format, args);
  va_end(args);
}

void Logger::info(const char* format, ...) {
  va_list args;
  va_start(args, format);
  log(Info, format, args);
  va_end(args);
}

void Logger::warn(const char* format, ...) {
  va_list args;
  va_start(args, format);
  log(Warn, format, args);
  va_end(args);
}

void Logger::error(const char* format, ...) {
  va_list args;
  va_start(args, format);
  log(Error, format, args);
  va_end(args);
}