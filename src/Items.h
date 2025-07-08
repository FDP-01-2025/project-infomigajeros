#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <vector>

// Data structure for an item (name, effect type, and quantity)
struct Item {
    std::string nombre;   // Item name
    std::string efecto;   // Effect type (e.g., heal, damage)
    int cantidad;         // Available quantity
};

// Loads the inventory from a file or returns default items if the file is missing
std::vector<Item> cargarInventario();

// Saves the current inventory state to a file
void guardarInventario(const std::vector<Item>& inventario);

#endif
