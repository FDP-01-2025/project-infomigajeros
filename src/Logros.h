#ifndef LOGROS_H
#define LOGROS_H

#include <string>
#include <vector>

// Struct to represent an achievement with its name and unlocked state
struct Logro {
    std::string nombre;
    bool desbloqueado;
};

// Initializes the list of achievements with their initial states
void inicializarLogros(std::vector<Logro>& logros);

// Checks game conditions to unlock achievements
void verificarLogros(std::vector<Logro>& logros, int curaciones, int personajesVivos, bool usoObjetos);

// Displays the list of achievements and their current states
void mostrarLogros(const std::vector<Logro>& logros);

#endif
