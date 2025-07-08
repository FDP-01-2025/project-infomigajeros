#ifndef BATTLE_H
#define BATTLE_H

#include "Personajes.h"
#include "Items.h"
#include "UI.h"

// Structure that defines an enemy entity for the battle system
struct Enemigo {
    std::string nombre;  // Enemy name
    int hp;              // Health points
    int atk;             // Attack power
    int def;             // Defense power
};

// Generates an enemy based on the current level or game phase
Enemigo generarEnemigo(int nivel);

// Battle function that handles the full turn-based combat logic
// Parameters:
// - equipo: the player's team (vector of characters)
// - enemigo: the enemy to battle
// - inventario: current inventory (items available)
// - totalCurado: reference to track how much HP has been healed (used for achievements)
// - usoObjetos: flag to track if any item was used during the battle
// Returns:
// - true if the player wins the battle, false otherwise
bool batalla(std::vector<Personaje>& equipo, Enemigo& enemigo, std::vector<Item>& inventario, int& totalCurado, bool& usoObjetos);

#endif
