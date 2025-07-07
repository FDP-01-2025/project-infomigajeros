#include "Personajes.h"
#include <vector>
using namespace std;

vector<Personaje> crearEquipo() {
    return {
        {"🛡️ Armando el Valiente", 130, 130, 18, 15, {"Defender", "Corte Firme"}},
        {"🔥 Lía la Maga", 90, 90, 28, 6, {"Bola de Fuego", "Rayo Arcano"}},
        {"💖 Sania la Curandera", 80, 80, 10, 10, {"Curar", "Bendición"}},
        {"⚔️ Rolf el Espadachín", 100, 100, 25, 10, {"Estocada", "Doble Corte"}},
        {"🌀 Kael el Invocador", 85, 85, 20, 8, {"Bestia Etérea", "Sello Mágico"}},
        {"🌿 Elra la Druida", 95, 95, 18, 12, {"Raíces", "Curar"}}
    };
}