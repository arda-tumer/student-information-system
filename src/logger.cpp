#include "logger.h"
#include <ctime>
#include <fstream>

void logMessage(const std::string &level, const std::string &message) {
  std::ofstream logFile("/app/logs/app.log", std::ios::app);
  if (!logFile)
    return;

  std::time_t now = std::time(nullptr);
  logFile << "[" << std::ctime(&now) << "] " << "[" << level << "] " << message << "\n";
}
