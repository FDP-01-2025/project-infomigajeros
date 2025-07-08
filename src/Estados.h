#ifndef ESTADOS_H
#define ESTADOS_H

#include <string>
#include <vector>

// Represents a status effect that can be applied to a character or enemy.
// Each status has a name and a number of remaining turns.
struct Estado {
    std::string nombre;         // Name of the status effect (e.g., "Veneno", "BuffAtk", "BuffDef")
    int turnosRestantes;        // How many turns the status will remain active
};

// Applies a new status effect to the given list or refreshes its duration if already present.
// Parameters:
// - estados: the list of current status effects
// - nombre: the name of the status effect
// - duracion: number of turns the status will be active
void aplicarEstado(std::vector<Estado>& estados, const std::string& nombre, int duracion);

// Checks if a specific status is currently active in the list.
// Returns true if found and still active.
bool tieneEstado(const std::vector<Estado>& estados, const std::string& nombre);

// Processes all active statuses by applying their effects (damage, buffs, etc.)
// and reducing their remaining turns.
// Parameters are passed by reference to be updated directly.
void procesarEstados(std::vector<Estado>& estados, int& hp, int& atk, int& def);

#endif
