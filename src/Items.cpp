#include "Items.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For min and max
#include "Personajes.h"
#include "Batlle.h"

using namespace std;

// Loads the inventory from a file. If the file doesn't exist, returns a default inventory.
vector<Item> cargarInventario() {
    vector<Item> inventario = {
        {"Pocion", "Curar25", 5},
        {"Elixir", "CurarTodo", 2},
        {"BombaDeFuego", "Daño30", 3},
        {"EscudoMagico", "Defensa10", 1},
        {"Veneno", "DañoPorTurno", 2}
    };

    ifstream archivo("inventory.txt");
    if (!archivo.is_open()) {
        cout << "[Aviso] No se encontro el archivo del inventario. Usando items por defecto.\n";
        return inventario;
    }

    inventario.clear();
    string nombre, efecto;
    int cantidad;

    // Read inventory items from file
    while (archivo >> nombre >> efecto >> cantidad) {
        inventario.push_back({nombre, efecto, cantidad});
    }

    archivo.close();
    return inventario;
}

// Saves the current inventory to a file
void guardarInventario(const vector<Item>& inventario) {
    ofstream archivo("inventory.txt");
    if (!archivo.is_open()) {
        cout << "[Error] No se pudo guardar el inventario.\n";
        return;
    }

    for (const auto& item : inventario) {
        archivo << item.nombre << " " << item.efecto << " " << item.cantidad << "\n";
    }

    archivo.close();
    cout << "[Exito] Inventario guardado correctamente.\n";
}

// Applies the item's effect to either the character or the enemy
void usarItem(Item& item, Personaje& personaje, Enemigo& enemigo) {
    if (item.cantidad <= 0) {
        cout << "[Error] No quedan mas unidades de " << item.nombre << ".\n";
        return;
    }

    item.cantidad--;

    if (item.efecto == "Curar25") {
        personaje.hp = min(personaje.maxHp, personaje.hp + 25);
        cout << personaje.nombre << " recupera 25 puntos de vida.\n";
    } 
    else if (item.efecto == "CurarTodo") {
        personaje.hp = personaje.maxHp;
        cout << personaje.nombre << " se cura completamente.\n";
    } 
    else if (item.efecto == "Daño30") {
        enemigo.hp = max(0, enemigo.hp - 30);
        cout << enemigo.nombre << " recibe 30 puntos de daño por bomba.\n";
    } 
    else if (item.efecto == "Defensa10") {
        personaje.def += 10;
        cout << personaje.nombre << " aumenta su defensa en 10 temporalmente.\n";
    }
    else if (item.efecto == "DañoPorTurno") {
        cout << enemigo.nombre << " ha sido envenenado.\n";
    }
    else {
        cout << "[Aviso] Efecto de objeto no reconocido.\n";
    }
}
