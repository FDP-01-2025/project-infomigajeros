#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <string>
#include <vector>

// Struct representing a character with stats and abilities
struct Personaje {
    std::string nombre;                // Character name
    int hp;                           // Current health points
    int maxHp;                        // Maximum health points
    int atk;                          // Attack stat
    int def;                          // Defense stat
    std::vector<std::string> habilidades;  // List of abilities
};

// Function to create and return the team of characters
std::vector<Personaje> crearEquipo();

#endif
