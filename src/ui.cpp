#include "ui.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

// ANSI COLORS
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define DIM     "\033[2m"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Clear screen
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ASCII Banner
void printBanner() {
    std::cout << RED << BOLD;
    std::cout <<
R"(  
     @@@@@@ @@@@@@@ @@@  @@@ @@@@@@@  @@@@@@@@ @@@  @@@ @@@@@@@                               
    !@@       @@!   @@!  @@@ @@!  @@@ @@!      @@!@!@@@   @@!                                 
      !@@!!    @!!   @!@  !@! @!@  !@! @!!!:!   @!@@!!@!   @!!                                 
         !:!   !!:   !!:  !!! !!:  !!! !!:      !!:  !!!   !!:                                 
     ::.: :     :     :.:: :  :: :  :  : :: ::: ::    :     :                                  

     @@@ @@@  @@@ @@@@@@@@  @@@@@@  @@@@@@@  @@@@@@@@@@   @@@@@@  @@@@@@@ @@@  @@@@@@  @@@  @@@
     @@! @@!@!@@@ @@!      @@!  @@@ @@!  @@@ @@! @@! @@! @@!  @@@   @@!   @@! @@!  @@@ @@!@!@@@
     !!@ @!@@!!@! @!!!:!   @!@  !@! @!@!!@!  @!! !!@ @!@ @!@!@!@!   @!!   !!@ @!@  !@! @!@@!!@!
     !!: !!:  !!! !!:      !!:  !!! !!: :!!  !!:     !!: !!:  !!!   !!:   !!: !!:  !!! !!:  !!!
     :   ::    :   :        : :. :   :   : :  :      :    :   : :    :    :    : :. :  ::    : 

      @@@@@@ @@@ @@@  @@@@@@ @@@@@@@ @@@@@@@@ @@@@@@@@@@                                       
     !@@     @@! !@@ !@@       @@!   @@!      @@! @@! @@!                                      
      !@@!!   !@!@!   !@@!!    @!!   @!!!:!   @!! !!@ @!@                                      
         !:!   !!:       !:!   !!:   !!:      !!:     !!:                                      
     ::.: :    .:    ::.: :     :    : :: :::  :      :                                        
                                                          

)";
    std::cout << RESET;
    std::cout << MAGENTA << BOLD
              << "          Student Information System\n\n"
              << RESET;
}

// Menu
void printMenu() {
    clearScreen();
    printBanner();

    std::cout << CYAN
              << "╔══════════════════════════════════════════╗\n"
              << "║                MAIN MENU                 ║\n"
              << "╠══════════════════════════════════════════╣\n"
              << RESET;

    std::cout << GREEN
              << "║  [1]    Add Student                      ║\n"
              << "║  [2]    List Students                    ║\n"
              << "║  [3]    Update Student                   ║\n"
              << "║  [4]    Delete Student                   ║\n"
              << YELLOW
              << "║  [5]    Exit                             ║\n"
              << RESET;

    std::cout << CYAN
              << "╚══════════════════════════════════════════╝\n"
              << RESET;

    std::cout << DIM << "Enter your choice (1-5): " << RESET;
}

// Loading spinner
void showLoading(const std::string& text, int durationMs) {
    const char spinner[] = {'|', '/', '-', '\\'};
    int interval = 100;
    int steps = durationMs / interval;

    std::cout << CYAN << text << " ";

    for (int i = 0; i < steps; ++i) {
        std::cout << spinner[i % 4] << "\r" << text << " ";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }

    std::cout << GREEN << "✔\n" << RESET;
}

// Progress bar
void showProgressBar(const std::string& text, int durationMs) {
    const int barWidth = 40;
    const int steps = 100;
    int delay = durationMs / steps;

    std::cout << CYAN << text << "\n" << RESET;

    for (int i = 0; i <= steps; ++i) {
        float progress = static_cast<float>(i) / steps;
        int pos = static_cast<int>(barWidth * progress);

        std::cout << "\r" << BLUE << "[";
        for (int j = 0; j < barWidth; ++j) {
            if (j < pos)
                std::cout << "█";
            else
                std::cout << "░";
        }

        std::cout << "] " << std::setw(3) << i << "%" << RESET;
        std::cout.flush();

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }

    std::cout << GREEN << " ✔\n" << RESET;
}

// Messages
void printError(const std::string& msg) {
    std::cout << RED << BOLD << "\n[ ✖ ERROR ] " << RESET
              << RED << msg << RESET << "\n";
}

void printSuccess(const std::string& msg) {
    std::cout << GREEN << BOLD << "\n[ ✔ SUCCESS ] " << RESET
              << GREEN << msg << RESET << "\n";
}
