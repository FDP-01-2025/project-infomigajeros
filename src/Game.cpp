#include "Game.h"
#include "Personajes.h"
#include "Items.h"
#include "Batlle.h"
#include "Estados.h"
#include "Logros.h"
#include "UI.h"

#include <iostream>
#include <vector>

using namespace std;

void runGame() {
    clearScreen();
    typeWriter("Bienvenido a Buho-Aventuras: La Batalla del Bosque Eterno ", 40);

    // Cargar personajes y objetos
    vector<Personaje> equipo = crearEquipo();
    vector<Item> inventario = cargarInventario();

    // Iniciar logros
    vector<Logro> logros;
    inicializarLogros(logros);

    int totalCurado = 0;
    bool usoObjetos = false;

    // Simulación de niveles de enemigos
    for (int nivel = 1; nivel <= 3; ++nivel) {
        Enemigo enemigo = generarEnemigo(nivel);
        bool victoria = batalla(equipo, enemigo, inventario, totalCurado, usoObjetos);
        if (!victoria) {
            typeWriter(" Tu equipo ha sido derrotado...", 40);
            mostrarLogros(logros);
            guardarInventario(inventario);
            return;
        }
        typeWriter(" Has ganado la batalla", 30);
        pauseConsole("Continúa a la siguiente batalla...");
    }

    // Batalla final contra jefe
    Enemigo jefeFinal = generarEnemigo(99);
    bool final = batalla(equipo, jefeFinal, inventario, totalCurado, usoObjetos);

    if (final) {
        typeWriter(" Felicidades, Has vencido al Rey Buho Supremo y salvado el bosque eterno. ", 30);
    } else {
        typeWriter(" El Rey Buho Supremo ha vencido a tu equipo...", 30);
    }

    // Calcular personajes vivos
    int vivos = 0;
    for (auto& p : equipo)
        if (p.hp > 0) ++vivos;

    // Verificar y mostrar logros
    verificarLogros(logros, totalCurado, vivos, usoObjetos);
    mostrarLogros(logros);

    // Guardar inventario actualizado
    guardarInventario(inventario);

    pauseConsole("Fin del juego. Gracias por jugar ");
}
