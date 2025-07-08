#ifndef UI_H
#define UI_H

#include <string>

// Clears the console screen (compatible with Windows and Linux/Mac)
void clearScreen();

// Pauses the console and waits for the user to press Enter
void pauseConsole(const std::string& message);

// Displays a health bar with colors and formatted style
void mostrarBarraVida(const std::string& nombre, int hp, int maxHp);

// Prints a visual separator line in the console
void printSeparator(int length);

// Writes text with a typewriter effect
void typeWriter(const std::string& text, unsigned int millisPerChar = 30);

#endif // UI_H

