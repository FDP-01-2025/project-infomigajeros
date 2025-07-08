[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# Proyecto de C++ - [Buho-aventuras]

## Descripción del Proyecto

Temática y ambientación:El juego está ambientado en un mundo de fantasía mágica donde los jugadores encarnan a un equipo de héroes animales liderados por búhos sabios que buscan proteger el Bosque Ancestral de criaturas oscuras. La ambientación está inspirada en bosques mágicos, ruinas antiguas, y zonas elementales (fuego, hielo, sombra).

Mecánica principal:Sistema de combate por turnos en consola. Los jugadores eligen acciones por personaje: atacar, usar habilidad o usar un objeto. Hay enemigos con inteligencia simple, habilidades, y sistema de estados (veneno, defensa, congelado).

Idea general de la jugabilidad:

° El jugador controla a 6 personajes con habilidades únicas.

° Cada combate es una batalla por turnos.

° Hay objetos que curan, fortalecen o envenenan.

° Se guardan logros al superar enemigos especiales.

° El juego avanza en niveles (1 al 3 y jefe final).

Aplicación de los temas vistos:

° Variables y tipos de datos: uso de variables como int hp, string nombre, bool usoObjetos, etc. para representar estado y decisiones.

° Estructuras condicionales (if, else, switch): utilizadas para lógica de combate, decisiones del jugador, efectos de habilidades y objetos. Ejemplo: if (hp <= 0), switch (opcion).

° Ciclos (for, while, do while): for para mostrar menús e iterar personajes, while para el loop de batalla, do while puede usarse para validación de entrada.

° Funciones: separadas en módulos como mostrarBarraVida(), batalla(), usarItem(), guardarInventario(), etc.

° Estructuras de datos: uso de struct como Personaje, Item, Enemigo, y vectores (vector<T>) para manejar listas dinámicas.

° Manejo de archivos: se carga y guarda inventario con ifstream y ofstream desde y hacia inventory.txt.

° Manejo de errores: validación de entrada del jugador, control de objetos agotados, habilidades inválidas, archivo inexistente.

° Interfaz por consola: barra de vida con colores ANSI, menús, texto animado tipo máquina de escribir, mensajes estilizados.

° Consideraciones técnicas del desarrollo:

Lenguaje: C++

Modularización: uso de archivos .h y .cpp separados (UI, Items, Personajes, Battle, Estados, Logros).

Compilación multiplataforma: compatible con Windows/Linux usando comandos g++.

## Equipo

- **Nombre del equipo:** Infomigajeros

### Integrantes del equipo

1. **Nombre completo:** Daniel Andrés Hernández Barahona  
   **Carnet:** [00036225]

2. **Nombre completo:** Yacira Elisheba Gutierrez 
   **Carnet:** [00173925]

## Instrucciones de Ejecución

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone [URL del repositorio]
