#ifndef LOGROS_H
#define LOGROS_H

#include <string>
#include <vector>

struct Logro {
    std::string nombre;
    bool desbloqueado;
};

void inicializarLogros(std::vector<Logro>& logros);
void verificarLogros(std::vector<Logro>& logros, int curaciones, int personajesVivos, bool usoObjetos);
void mostrarLogros(const std::vector<Logro>& logros);

#endif
