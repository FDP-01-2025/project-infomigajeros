#ifndef BATTLE_H
#define BATTLE_H

#include "Personajes.h"
#include "Items.h"
#include "UI.h"

struct Enemigo {
    std::string nombre;
    int hp;
    int atk;
    int def;
};

Enemigo generarEnemigo(int nivel);

// 🔧 Cambiar la firma de batalla:
bool batalla(std::vector<Personaje>& equipo, Enemigo& enemigo, std::vector<Item>& inventario, int& totalCurado, bool& usoObjetos);

#endif
