#include "Logros.h"
#include <iostream>

using namespace std;

void inicializarLogros(vector<Logro>& logros) {
    logros = {
        {"💉 Curandero experto (Curaste más de 100 HP)", false},
        {"🛡️ Superviviente (Terminaste con menos de 2 personajes vivos)", false},
        {"🚫 Minimalista (Ganaste sin usar objetos)", false}
    };
}

void verificarLogros(vector<Logro>& logros, int curaciones, int personajesVivos, bool usoObjetos) {
    if (curaciones > 100) logros[0].desbloqueado = true;
    if (personajesVivos <= 2) logros[1].desbloqueado = true;
    if (!usoObjetos) logros[2].desbloqueado = true;
}

void mostrarLogros(const vector<Logro>& logros) {
    cout << "\n🏅 Logros obtenidos:\n";
    for (const auto& logro : logros) {
        if (logro.desbloqueado)
            cout << "\033[32m✅ " << logro.nombre << "\033[0m\n";
        else
            cout << "\033[90m❌ " << logro.nombre << "\033[0m\n";
    }
}
