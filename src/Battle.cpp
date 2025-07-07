#include "Batlle.h"
#include "UI.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

Enemigo generarEnemigo(int nivel) {
    srand(time(NULL));
    if (nivel == 99)
        return {"🦉 Rey Búho Supremo", 400, 40, 20};

    return {
        "🐍 Enemigo Nv." + to_string(nivel),
        80 + nivel * 20,
        15 + nivel * 5,
        8 + nivel * 2
    };
}

bool batalla(vector<Personaje>& equipo, Enemigo& enemigo, vector<Item>& inventario) {
    while (enemigo.hp > 0 && any_of(equipo.begin(), equipo.end(), [](Personaje& p) { return p.hp > 0; })) {
        clearScreen();
        printSeparator(40);
        cout << "🧨 Batalla contra: " << enemigo.nombre << "\n";
        mostrarBarraVida(enemigo.nombre, enemigo.hp, 400);

        for (auto& p : equipo) {
            if (p.hp <= 0) continue;

            cout << "\n🎮 Turno de " << p.nombre << "\n";
            mostrarBarraVida(p.nombre, p.hp, p.maxHp);
            cout << "1. Atacar\n2. Usar habilidad\n3. Usar objeto\nElige opción: ";
            int opcion;
            cin >> opcion;

            switch (opcion) {
                case 1: {
                    int daño = max(0, p.atk - enemigo.def);
                    enemigo.hp -= daño;
                    cout << p.nombre << " ataca y causa " << daño << " de daño.\n";
                    break;
                }
                case 2: {
                    cout << "🔮 Habilidades:\n";
                    for (size_t i = 0; i < p.habilidades.size(); ++i)
                        cout << i + 1 << ". " << p.habilidades[i] << "\n";
                    cout << "Elige habilidad: ";
                    int hab;
                    cin >> hab;
                    if (hab < 1 || hab > (int)p.habilidades.size()) {
                        cout << "⚠️ Habilidad inválida.\n";
                        break;
                    }
                    string habilidad = p.habilidades[hab - 1];
                    if (habilidad == "Curar") {
                        p.hp = min(p.maxHp, p.hp + 30);
                        cout << p.nombre << " se cura 30 puntos de vida.\n";
                    } else if (habilidad == "Defender" || habilidad == "Escudo Mágico") {
                        p.def += 5;
                        cout << p.nombre << " aumenta su defensa temporalmente.\n";
                    } else {
                        int dmg = 25;
                        enemigo.hp -= dmg;
                        cout << p.nombre << " lanza " << habilidad << " causando " << dmg << " de daño.\n";
                    }
                    break;
                }
                case 3: {
                    cout << "🎒 Inventario:\n";
                    for (size_t i = 0; i < inventario.size(); ++i)
                        cout << i + 1 << ". " << inventario[i].nombre << " (x" << inventario[i].cantidad << ")\n";
                    cout << "Elige objeto: ";
                    int obj;
                    cin >> obj;
                    if (obj < 1 || obj > (int)inventario.size()) {
                        cout << "Objeto inválido.\n";
                        break;
                    }
                    if (inventario[obj - 1].cantidad <= 0) {
                        cout << "No quedan de ese objeto.\n";
                        break;
                    }
                    inventario[obj - 1].cantidad--;
                    if (inventario[obj - 1].efecto == "Curar25") {
                        p.hp = min(p.maxHp, p.hp + 25);
                        cout << p.nombre << " recupera 25 puntos de vida.\n";
                    } else if (inventario[obj - 1].efecto == "CurarTodo") {
                        p.hp = p.maxHp;
                        cout << p.nombre << " se cura por completo.\n";
                    }
                    break;
                }
                default:
                    cout << "Opción inválida.\n";
                    break;
            }
            pauseConsole("Presiona Enter para continuar...");
            if (enemigo.hp <= 0) break;
        }

        if (enemigo.hp > 0) {
            vector<Personaje*> vivos;
            for (auto& p : equipo)
                if (p.hp > 0) vivos.push_back(&p);

            if (!vivos.empty()) {
                Personaje* objetivo = vivos[rand() % vivos.size()];
                int daño = max(0, enemigo.atk - objetivo->def);
                objetivo->hp -= daño;
                cout << enemigo.nombre << " ataca a " << objetivo->nombre << " causando " << daño << " de daño.\n";
                pauseConsole("Presiona Enter para continuar...");
            }
        }
    }

    return enemigo.hp <= 0;
}
