#include "../include/Logger.h"
#include <FEHUtility.h>
#include <FEHLCD.h>
#include <stdio.h>
#include <string.h>
using namespace util;

Logger::Logger(LogLevel lcdLogLevel, LogLevel fileLogLevel) {
  this->file = nullptr;
  this->lcdLogLevel = lcdLogLevel;
  this->fileLogLevel = fileLogLevel;
}

void Logger::open(const TCHAR* fileName) {
  // Open the file
  file = SD.FOpen(fileName, "w");
  // Print out the header
  SD.FPrintf(file, "LOGGING STARTED AT %dl", TimeNowMSec());
  SD.FPrintf(file, "----------------------------------------");
}

void Logger::close() {
  SD.FClose(file);
}

void Logger::setLcdLogLevel(LogLevel logLevel) {
  this->lcdLogLevel = logLevel;
}

void Logger::setFileLogLevel(LogLevel logLevel) {
  this->fileLogLevel = logLevel;
}

void Logger::printLine(char* str) {
  LCD.WriteLine(str);
}

void Logger::filePrintLine(char* str) {
  // Print to the log file if opened
  if (file != nullptr) {
    SD.FPrintf(file, str);
    // Print a new line
    SD.FPrintf(file, "\n");
  }
}

void Logger::telemetry(const char* format, ...) {
  char* str;
  // Format the telemetry data
  sprintf(str, format);
  // Print to the screen
  printLine(str);
}

void Logger::log(LogLevel level, const char* format, ...) {
  // The output string
  char* str;
  // Print out the timestamp
  sprintf(str, "%ld ", TimeNowMSec());
  // Print out the log level
  switch (level) {
    case Debug:
      sprintf(str, "DEBUG - ");
      break;
    case Info:
      sprintf(str, "INFO - ");
      break;
    case Warn:
      sprintf(str, "WARN - ");
      break;
    case Error:
      sprintf(str, "ERROR - ");
      break;
  }
  sprintf(str, format);
  // Print to the LCD screen
  if (level >= lcdLogLevel) {
    printLine(str);
  }
  // Print to the file
  if (level >= fileLogLevel) {
    filePrintLine(str);
  }
}

void Logger::debug(const char* format, ...) {
  log(Debug, format);
}

void Logger::info(const char* format, ...) {
  log(Info, format);
}

void Logger::warn(const char* format, ...) {
  log(Warn, format);
}

void Logger::error(const char* format, ...) {
  log(Error, format);
}