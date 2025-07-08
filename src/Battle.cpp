#include "Batlle.h"
#include "UI.h"
#include "Estados.h"
#include "Logros.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

Enemigo generarEnemigo(int nivel) {
    srand(time(NULL));
    if (nivel == 99)
        return {"Rey Buho Supremo", 400, 40, 20};

    if (nivel == 3)
        return {"Dragon de Lava", 300, 35, 18};
    if (nivel == 2)
        return {"Espectro Oscuro", 250, 30, 15};

    return {
        "Enemigo Nv." + to_string(nivel),
        80 + nivel * 20,
        15 + nivel * 5,
        8 + nivel * 2
    };
}

bool batalla(vector<Personaje>& equipo, Enemigo& enemigo, vector<Item>& inventario, int& totalCurado, bool& usoObjetos) {
    vector<Estado> estadosEnemigo;
    vector<vector<Estado>> estadosPersonajes(equipo.size());

    while (enemigo.hp > 0 && any_of(equipo.begin(), equipo.end(), [](Personaje& p) { return p.hp > 0; })) {
        clearScreen();
        printSeparator(40);
        cout << "BATALLA CONTRA: " << enemigo.nombre << "\n";
        mostrarBarraVida(enemigo.nombre, enemigo.hp, 400);

        procesarEstados(estadosEnemigo, enemigo.hp, enemigo.atk, enemigo.def);

        for (size_t i = 0; i < equipo.size(); ++i) {
            auto& p = equipo[i];
            if (p.hp <= 0) continue;

            procesarEstados(estadosPersonajes[i], p.hp, p.atk, p.def);

            cout << "\nTURNO DE " << p.nombre << "\n";
            mostrarBarraVida(p.nombre, p.hp, p.maxHp);
            cout << "1. Atacar\n2. Usar habilidad\n3. Usar objeto\nElige opcion: ";
            int opcion;
            cin >> opcion;

            switch (opcion) {
                case 1: {
                    int dano = max(0, p.atk - enemigo.def);
                    enemigo.hp -= dano;
                    cout << p.nombre << " ataca y causa " << dano << " de dano.\n";
                    break;
                }
                case 2: {
                    cout << "Habilidades:\n";
                    for (size_t j = 0; j < p.habilidades.size(); ++j)
                        cout << j + 1 << ". " << p.habilidades[j] << "\n";
                    cout << "Elige habilidad: ";
                    int hab;
                    cin >> hab;
                    if (hab < 1 || hab > (int)p.habilidades.size()) {
                        cout << "Habilidad invalida.\n";
                        break;
                    }
                    string habilidad = p.habilidades[hab - 1];
                    if (habilidad == "Curar") {
                        int cantidad = 30;
                        p.hp = min(p.maxHp, p.hp + cantidad);
                        totalCurado += cantidad;
                        cout << p.nombre << " se cura " << cantidad << " puntos de vida.\n";
                    } else if (habilidad == "Bendicion") {
                        aplicarEstado(estadosPersonajes[i], "BuffDef", 3);
                        cout << p.nombre << " se protege con una bendicion.\n";
                    } else if (habilidad == "Defender") {
                        aplicarEstado(estadosPersonajes[i], "BuffDef", 2);
                        cout << p.nombre << " aumenta su defensa temporalmente.\n";
                    } else if (habilidad == "CurarTodo") {
                        for (auto& aliado : equipo) {
                            if (aliado.hp > 0) {
                                int curado = 20;
                                aliado.hp = min(aliado.maxHp, aliado.hp + curado);
                                totalCurado += curado;
                            }
                        }
                        cout << p.nombre << " lanza curacion grupal.\n";
                    } else if (habilidad == "Congelar") {
                        enemigo.atk = max(0, enemigo.atk - 10);
                        cout << p.nombre << " congela al enemigo y reduce su ataque.\n";
                    } else {
                        int dmg = 25;
                        enemigo.hp -= dmg;
                        cout << p.nombre << " lanza " << habilidad << " causando " << dmg << " de dano.\n";
                    }
                    break;
                }
                case 3: {
                    cout << "Inventario:\n";
                    for (size_t j = 0; j < inventario.size(); ++j)
                        cout << j + 1 << ". " << inventario[j].nombre << " (x" << inventario[j].cantidad << ")\n";
                    cout << "Elige objeto: ";
                    int obj;
                    cin >> obj;
                    if (obj < 1 || obj > (int)inventario.size()) {
                        cout << "Objeto invalido.\n";
                        break;
                    }

                    Item& item = inventario[obj - 1];
                    if (item.cantidad <= 0) {
                        cout << "No quedan de ese objeto.\n";
                        break;
                    }

                    item.cantidad--;
                    usoObjetos = true;

                    if (item.efecto == "Curar25") {
                        int cantidad = 25;
                        p.hp = min(p.maxHp, p.hp + cantidad);
                        totalCurado += cantidad;
                        cout << p.nombre << " recupera " << cantidad << " puntos de vida.\n";
                    } else if (item.efecto == "CurarTodo") {
                        p.hp = p.maxHp;
                        totalCurado += p.maxHp;
                        cout << p.nombre << " se cura por completo.\n";
                    } else if (item.efecto == "Dano30") {
                        enemigo.hp -= 30;
                        cout << enemigo.nombre << " recibe 30 puntos de dano por bomba.\n";
                    } else if (item.efecto == "Defensa10") {
                        aplicarEstado(estadosPersonajes[i], "BuffDef", 3);
                        cout << p.nombre << " aumenta su defensa.\n";
                    } else if (item.efecto == "DanoPorTurno") {
                        aplicarEstado(estadosEnemigo, "Veneno", 3);
                        cout << enemigo.nombre << " ha sido envenenado.\n";
                    } else {
                        cout << "Objeto no reconocido.\n";
                    }

                    break;
                }
                default:
                    cout << "Opcion invalida.\n";
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
                int dano = max(0, enemigo.atk - objetivo->def);
                objetivo->hp -= dano;
                cout << enemigo.nombre << " ataca a " << objetivo->nombre << " causando " << dano << " de dano.\n";
                pauseConsole("Presiona Enter para continuar...");
            }
        }
    }

    return enemigo.hp <= 0;
}