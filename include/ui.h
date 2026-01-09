#ifndef UI_H
#define UI_H

#include <string>

// Screen & banner
void clearScreen();
void printBanner();

// Menu
void printMenu();

// Animations
void showLoading(const std::string& text = "Loading", int durationMs = 1500);
void showProgressBar(const std::string& text = "Processing", int durationMs = 2000);

// Messages
void printError(const std::string& msg);
void printSuccess(const std::string& msg);

#endif // UI_H
