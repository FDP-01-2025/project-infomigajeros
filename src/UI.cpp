#include "UI.h"
#include <iostream>
#include <thread>
#include <chrono>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

// Clears the console screen depending on the operating system
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[1;1H"; // ANSI escape code to clear screen
#endif
}

// Pauses the console and waits for the user to press Enter
void pauseConsole(const std::string& message) {
    std::cout << "\n" << message << "\n";
    
    // Limpia cualquier carácter sobrante en el buffer de entrada
    if (std::cin.peek() == '\n') std::cin.get();

    std::cout << "Presiona Enter para continuar...";
    std::cin.get();
}

// Displays a health bar with colors based on current HP
void mostrarBarraVida(const string& nombre, int hp, int maxHp) {
    const int barraLength = 30;
    int filledLength = (hp * barraLength) / maxHp;

    string color;
    if (hp > maxHp * 0.5) color = "\033[32m";       // Green
    else if (hp > maxHp * 0.2) color = "\033[33m";  // Yellow
    else color = "\033[31m";                         // Red

    cout << nombre << ": [";
    cout << color;
    for (int i = 0; i < filledLength; ++i) cout << "#";
    cout << "\033[0m"; // Reset color

    for (int i = filledLength; i < barraLength; ++i) cout << "-";
    cout << "] " << hp << "/" << maxHp << "\n";
}

// Prints a visual separator line of given length
void printSeparator(int length) {
    for (int i = 0; i < length; ++i) cout << "=";
    cout << "\n";
}

// Writes text with a typewriter effect (prints character by character)
void typeWriter(const string& text, unsigned int millisPerChar) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(millisPerChar));
    }
    cout << endl;
}
