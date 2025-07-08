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

// Main game loop and flow controller
void runGame() {
    clearScreen();
    typeWriter("Bienvenido a Buho-Aventuras: La Batalla del Bosque Eterno ", 40);

    // Load team and inventory
    vector<Personaje> equipo = crearEquipo();              // Load heroes
    vector<Item> inventario = cargarInventario();          // Load items from file

    // Initialize achievements
    vector<Logro> logros;
    inicializarLogros(logros);                             // Populate logros vector

    int totalCurado = 0;       // Tracks how much HP was healed during game
    bool usoObjetos = false;   // Tracks if any items were used

    // Level progression: 3 standard enemy battles
    for (int nivel = 1; nivel <= 3; ++nivel) {
        Enemigo enemigo = generarEnemigo(nivel);           // Generate enemy based on level
        bool victoria = batalla(equipo, enemigo, inventario, totalCurado, usoObjetos);

        if (!victoria) {
            typeWriter(" Tu equipo ha sido derrotado...", 40);
            mostrarLogros(logros);                         // Display achievements
            guardarInventario(inventario);                 // Save inventory state
            return;
        }

        typeWriter(" Has ganado la batalla", 30);
        pauseConsole("Continúa a la siguiente batalla...");
    }

    // Final boss battle
    Enemigo jefeFinal = generarEnemigo(99);                // Final boss
    bool final = batalla(equipo, jefeFinal, inventario, totalCurado, usoObjetos);

    if (final) {
        typeWriter(" Felicidades, Has vencido al Rey Buho Supremo y salvado el bosque eterno. ", 30);
    } else {
        typeWriter(" El Rey Buho Supremo ha vencido a tu equipo...", 30);
    }

    // Count how many characters are still alive at the end
    int vivos = 0;
    for (auto& p : equipo)
        if (p.hp > 0) ++vivos;

    // Check and display achievements based on final stats
    verificarLogros(logros, totalCurado, vivos, usoObjetos);
    mostrarLogros(logros);

    // Save final inventory state
    guardarInventario(inventario);

    pauseConsole("Fin del juego. Gracias por jugar ");
}
