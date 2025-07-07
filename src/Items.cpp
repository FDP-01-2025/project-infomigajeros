#include "Items.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Para min y max
#include "Personajes.h"
#include "Batlle.h"

using namespace std;

// Carga el inventario desde archivo, si no existe, usa inventario por defecto
vector<Item> cargarInventario() {
    vector<Item> inventario = {
        {"🧪 Poción", "Curar25", 5},
        {"✨ Elixir", "CurarTodo", 2},
        {"💣 Bomba de Fuego", "Daño30", 3},
        {"🛡️ Escudo Mágico", "Defensa10", 1},
        {"☠️ Veneno", "DañoPorTurno", 2}
    };

    ifstream archivo("inventory.txt");
    if (!archivo.is_open()) {
        cout << "\033[33m⚠️ No se pudo abrir el archivo de inventario. Usando inventario por defecto.\033[0m\n";
        return inventario;
    }

    inventario.clear();
    string nombre, efecto;
    int cantidad;

    while (archivo >> nombre >> efecto >> cantidad) {
        inventario.push_back({nombre, efecto, cantidad});
    }

    archivo.close();
    return inventario;
}

// Guarda el inventario actual en archivo
void guardarInventario(const vector<Item>& inventario) {
    ofstream archivo("inventory.txt");
    if (!archivo.is_open()) {
        cout << "\033[31m❌ Error al guardar inventario en archivo.\033[0m\n";
        return;
    }

    for (const auto& item : inventario) {
        archivo << item.nombre << " " << item.efecto << " " << item.cantidad << "\n";
    }

    archivo.close();
    cout << "\033[32m✅ Inventario guardado exitosamente.\033[0m\n";
}

// Aplica el efecto del objeto seleccionado sobre un personaje o enemigo
void usarItem(Item& item, Personaje & personaje, Enemigo& enemigo) {
    if (item.cantidad <= 0) {
        cout << "\033[31m❌ No quedan " << item.nombre << " disponibles.\033[0m\n";
        return;
    }

    item.cantidad--;

    if (item.efecto == "Curar25") {
        personaje.hp = min(personaje.maxHp, personaje.hp + 25);
        cout << "\033[32m💚 " << personaje.nombre << " recupera 25 puntos de vida.\033[0m\n";
    } 
    else if (item.efecto == "CurarTodo") {
        personaje.hp = personaje.maxHp;
        cout << "\033[32m💚 " << personaje.nombre << " se cura completamente.\033[0m\n";
    } 
    else if (item.efecto == "Daño30") {
        enemigo.hp = max(0, enemigo.hp - 30);
        cout << "\033[31m🔥 " << enemigo.nombre << " recibe 30 puntos de daño por la bomba.\033[0m\n";
    } 
    else if (item.efecto == "Defensa10") {
        personaje.def += 10;
        cout << "\033[36m🛡️ " << personaje.nombre << " aumenta su defensa en 10 puntos temporalmente.\033[0m\n";
    }
    else if (item.efecto == "DañoPorTurno") {
        // Aquí podrías añadir un estado al enemigo si tienes un sistema de estados
        cout << "\033[35m☠️ " << enemigo.nombre << " ha sido envenenado y sufrirá daño por turnos.\033[0m\n";
    }
    else {
        cout << "\033[33m⚠️ Efecto del objeto no reconocido.\033[0m\n";
    }
}
