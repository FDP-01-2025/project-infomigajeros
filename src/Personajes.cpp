#include "Personajes.h"
#include <vector>

using namespace std;

// Creates the team of characters with their stats and abilities
vector<Personaje> crearEquipo() {
    return {
        {"Armando el Valiente", 130, 130, 18, 15, {"Defender", "Corte Firme"}},
        {"Lia la Maga", 90, 90, 28, 6, {"Bola de Fuego", "Rayo Arcano"}},
        {"Sania la Curandera", 80, 80, 10, 10, {"Curar", "Bendicion"}},
        {"Rolf el Espadachin", 100, 100, 25, 10, {"Estocada", "Doble Corte"}},
        {"Kael el Invocador", 85, 85, 20, 8, {"Bestia Eterea", "Sello Magico"}},
        {"Elra la Druida", 95, 95, 18, 12, {"Raices", "Curar"}}
    };
}
