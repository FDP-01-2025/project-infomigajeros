#ifndef BATTLE_H
#define BATTLE_H

#include "Personajes.h"
#include "Items.h"
#include <vector>

struct Enemigo {
    std::string nombre;
    int hp;
    int atk;
    int def;
};

Enemigo generarEnemigo(int nivel);
bool batalla(std::vector<Personaje>& equipo, Enemigo& enemigo, std::vector<Item>& inventario);

#endif
