#ifndef UI_H
#define UI_H

#include <string>

// Limpia la consola (compatible con Windows y Linux/Mac)
void clearScreen();

// Pausa la consola y espera a que el usuario presione Enter
void pauseConsole(const std::string& message);

// Muestra una barra de vida con colores y formato elegante
void mostrarBarraVida(const std::string& nombre, int hp, int maxHp);

// Imprime una línea de separación visual en consola
void printSeparator(int length);

// Escribe texto con efecto de máquina de escribir
void typeWriter(const std::string& text, unsigned int millisPerChar = 30);

#endif // UI_H
