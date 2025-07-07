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

// Limpia la pantalla según el sistema operativo
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[1;1H"; // Código ANSI para limpiar pantalla
#endif
}

// Pausa la consola esperando que el usuario presione Enter
void pauseConsole(const string& message) {
    cout << "\n" << message << "\n";
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Presiona Enter para continuar...";
    cin.get();
}

// Muestra una barra de vida con colores según la cantidad de HP
void mostrarBarraVida(const string& nombre, int hp, int maxHp) {
    const int barraLength = 30;
    int filledLength = (hp * barraLength) / maxHp;

    string color;
    if (hp > maxHp * 0.5) color = "\033[32m";       // Verde
    else if (hp > maxHp * 0.2) color = "\033[33m";  // Amarillo
    else color = "\033[31m";                        // Rojo

    cout << nombre << ": [";
    cout << color;
    for (int i = 0; i < filledLength; ++i) cout << "#";
    cout << "\033[0m"; // Reset color

    for (int i = filledLength; i < barraLength; ++i) cout << "-";
    cout << "] " << hp << "/" << maxHp << "\n";
}

// Imprime una línea separadora visual
void printSeparator(int length) {
    for (int i = 0; i < length; ++i) cout << "=";
    cout << "\n";
}

// Escribe texto con efecto de máquina de escribir
void typeWriter(const string& text, unsigned int millisPerChar) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(millisPerChar));
    }
    cout << endl;
}
