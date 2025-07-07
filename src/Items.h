#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <vector>

struct Item {
    std::string nombre;
    std::string efecto;
    int cantidad;
};

std::vector<Item> cargarInventario();
void guardarInventario(const std::vector<Item>& inventario);

#endif
