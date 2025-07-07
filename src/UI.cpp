#include "UI.h"
#include <iostream>
#include <limits>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseConsole() {
    std::cout << "\nPresiona Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void mostrarBarraVida(std::string nombre, int hp, int maxHp) {
    int ancho = 20;
    int llenado = (hp * ancho) / maxHp;
    std::cout << nombre << " [";
    for (int i = 0; i < ancho; ++i) {
        std::cout << (i < llenado ? "#" : "-");
    }
    std::cout << "] " << hp << "/" << maxHp << "\n";
}
