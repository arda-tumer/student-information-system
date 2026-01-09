#include "logger.h"

#include <ctime>
#include <fstream>

void logMessage(const std::string &level, const std::string &message) {
  std::ofstream logFile("/app/logs/app.log", std::ios::app);
  if (!logFile) {
    return;
  }

  std::time_t now = std::time(nullptr);
  char buf[26];
  ctime_r(&now, buf);
  buf[24] = '\0'; // remove newline added by ctime_r

  logFile << "[" << buf << "] "
          << "[" << level << "] " << message << std::endl;
}
