#ifndef ESTADOS_H
#define ESTADOS_H

#include <string>
#include <vector>

struct Estado {
    std::string nombre;
    int turnosRestantes;
};

void aplicarEstado(std::vector<Estado>& estados, const std::string& nombre, int duracion);
bool tieneEstado(const std::vector<Estado>& estados, const std::string& nombre);
void procesarEstados(std::vector<Estado>& estados, int& hp, int& atk, int& def);

#endif
