#include <FEHSD.h>

/**
 * The log level.
 */
enum LogLevel {
  Debug = 0,
  Info = 1,
  Warn = 2,
  Error = 3
};

/**
 * The utility namespace.
 */
namespace util {
  /**
   * A logger.
   */
  class Logger {
    private:
      /**
       * The output file pointer.
       */
      FEHFile* file;
      /**
       * The file log level.
       */
      LogLevel fileLogLevel;
      /**
       * The LCD log level.
       */
      LogLevel lcdLogLevel;
      /**
       * Gets the timestamp.
       * 
       * @return The current timestamp.
       */
      char* getTimestamp();
      /**
       * Prints a string to the LCD screen.
       * 
       * @param str The string to print.
       */
      void printLine(char* str);
      /**
       * Prints a string to the log file.
       * 
       * @param str The string to print.
       */
      void filePrintLine(char* str);
    public:
      /**
       * Construct a new Logger object
       * 
       * @param lcdLogLevel The maximum log level to output to the screen.
       * @param fileLogLevel The maximum log level to output to the file.
       */
      Logger(LogLevel lcdLogLevel, LogLevel fileLogLevel);
      /**
       * Opens a log file.
       * 
       * @param The file name
       */
      void open(const TCHAR* fileName);
      /**
       * Closes the log file.
       */
      void close();
      /**
       * Sets the file log level.
       * 
       * @param logLevel The new log level.
       */ 
      void setFileLogLevel(LogLevel logLevel);
      /**
       * Sets the LCD screen log level.
       * 
       * @param logLevel The new log level.
       */ 
      void setLcdLogLevel(LogLevel logLevel);
      /**
       * Prints a telemetry string to the screen.
       * 
       * @param format The format for the telemetry log.
       */
      void telemetry(const char* format, ...);
      /**
       * Logs a string to the output file.
       * 
       * @param level The log level.
       * @param format The format for the log.
       */
      void log(LogLevel level, const char* format, ...);
      /**
       * Logs a debug string.
       * 
       * @param format The format for the log.
       */
      void debug(const char* format, ...);
      /**
       * Logs an info string.
       * 
       * @param format The format for the log.
       */
      void info(const char* format, ...);
      /**
       * Logs a warn string.
       * 
       * @param format The format for the log.
       */
      void warn(const char* format, ...);
      /**
       * Logs an error string.
       * 
       * @param format The format for the log.
       */
      void error(const char* format, ...);
  };
};