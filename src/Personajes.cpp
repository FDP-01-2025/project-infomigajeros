#include "Personajes.h"
#include <vector>

std::vector<Personaje> crearEquipo() {
    return {
        { "Aegon", "Guerrero", 120, 120, 25, 12, {"Corte Furia", "Grito de Guerra"} },
        { "Lyra", "Hechicera", 90, 90, 30, 5, {"Rayo Arcano", "Tormenta de Fuego"} },
        { "Nara", "Sanadora", 80, 80, 10, 8, {"Curación", "Revivir"} },
        { "Tyr", "Defensor", 150, 150, 15, 18, {"Provocar", "Muro de Hierro"} },
        { "Kael", "Explorador", 95, 95, 20, 10, {"Disparo Preciso", "Esquiva"} },
        { "Ezra", "Invocador", 100, 100, 18, 10, {"Invocar Lobo", "Espíritu del Bosque"} }
    };
}
