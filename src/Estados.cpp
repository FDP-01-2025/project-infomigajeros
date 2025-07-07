#include "Estados.h"
#include <iostream>

using namespace std;

void aplicarEstado(vector<Estado>& estados, const string& nombre, int duracion) {
    for (auto& estado : estados) {
        if (estado.nombre == nombre) {
            estado.turnosRestantes = duracion;
            return;
        }
    }
    estados.push_back({nombre, duracion});
}

bool tieneEstado(const vector<Estado>& estados, const string& nombre) {
    for (const auto& estado : estados) {
        if (estado.nombre == nombre && estado.turnosRestantes > 0)
            return true;
    }
    return false;
}

void procesarEstados(vector<Estado>& estados, int& hp, int& atk, int& def) {
    for (auto& estado : estados) {
        if (estado.turnosRestantes > 0) {
            if (estado.nombre == "Veneno") {
                cout << "\033[35m☠️ Sufre 10 de daño por veneno.\033[0m\n";
                hp -= 10;
            } else if (estado.nombre == "BuffAtk") {
                atk += 5;
            } else if (estado.nombre == "BuffDef") {
                def += 5;
            }
            estado.turnosRestantes--;
        }
    }
}
