#include "Estados.h"
#include <iostream>

using namespace std;

// Applies a status effect to the list of current statuses.
// If the status already exists, it resets the duration.
void aplicarEstado(vector<Estado>& estados, const string& nombre, int duracion) {
    for (auto& estado : estados) {
        if (estado.nombre == nombre) {
            estado.turnosRestantes = duracion;
            return;
        }
    }
    // Add new status if not already present
    estados.push_back({nombre, duracion});
}

// Checks if a character or enemy has a specific active status
bool tieneEstado(const vector<Estado>& estados, const string& nombre) {
    for (const auto& estado : estados) {
        if (estado.nombre == nombre && estado.turnosRestantes > 0)
            return true;
    }
    return false;
}

// Applies the effects of each active status to character/enemy stats
void procesarEstados(vector<Estado>& estados, int& hp, int& atk, int& def) {
    for (auto& estado : estados) {
        if (estado.turnosRestantes > 0) {
            if (estado.nombre == "Veneno") {
                cout << "Sufre 10 de dano por veneno.\n";
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

