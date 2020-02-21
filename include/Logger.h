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
      LogLevel logLevel;
      /**
       * The string buffer for the logger.
       */
      char buffer[100];
      /**
       * Gets the timestamp.
       * 
       * @return The current timestamp.
       */
      char* getTimestamp();
      /**
       * Prints a string to the log file.
       * 
       * @param str The string to print.
       */
      void printLine(char* str);
      /**
       * Logs a string to the output file.
       * 
       * @param level The log level.
       * @param format The format for the log.
       * @param args The variable arguments.
       */
      void log(LogLevel level, const char* format, va_list args);
    public:
      /**
       * Construct a new Logger object
       * 
       * @param logLevel The maximum log level to output to the file.
       */
      Logger(LogLevel logLevel);
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
      void setLogLevel(LogLevel logLevel);
      /**
       * Prints a telemetry string to the screen.
       * 
       * @param format The format for the telemetry log.
       */
      void telemetry(const char* format, ...);
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