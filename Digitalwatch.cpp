#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

void displayTime(int hours, int minutes, int seconds) {
    std::cout << std::setfill('0') << std::setw(2) << hours << ":"
              << std::setfill('0') << std::setw(2) << minutes << ":"
              << std::setfill('0') << std::setw(2) << seconds << "\r";
    std::cout.flush();
}

int main() {
    int hours = 0, minutes = 0, seconds = 0;

    while (true) {
        displayTime(hours, minutes, seconds);

        std::this_thread::sleep_for(std::chrono::seconds(1));

        seconds++;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
        }
        if (minutes == 60) {
            minutes = 0;
            hours++;
        }
        if (hours == 24) {
            hours = 0;
        }
    }

    return 0;
}

