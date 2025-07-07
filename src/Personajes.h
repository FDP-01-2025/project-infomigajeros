#ifndef PERSONAJES_H
#define PERSONAJES_H

#include <string>
#include <vector>

struct Personaje {
    std::string nombre;
    int hp;
    int maxHp;
    int atk;
    int def;
    std::vector<std::string> habilidades;
};

std::vector<Personaje> crearEquipo();

#endif
