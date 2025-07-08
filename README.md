Nombre del juego:
Buho-Aventuras

------------------------------------------------------------------------------------------------------------------------

Temática y ambientación:
El juego está ambientado en un mundo de fantasía mágica donde los jugadores encarnan a un equipo de héroes animales liderados por búhos sabios que buscan proteger el Bosque Ancestral de criaturas oscuras. La ambientación está inspirada en bosques mágicos, ruinas antiguas, y zonas elementales como fuego, hielo y sombra.

------------------------------------------------------------------------------------------------------------------------

Mecánica principal:
Sistema de combate por turnos en consola. Los jugadores eligen acciones para cada personaje: atacar, usar habilidades o usar objetos. Los enemigos tienen inteligencia simple, habilidades y sistema de estados como veneno, defensa o congelado.

------------------------------------------------------------------------------------------------------------------------

Idea general de la jugabilidad:
El jugador controla a 6 personajes con habilidades únicas.

Cada combate es una batalla por turnos.

Hay objetos que curan, fortalecen o envenenan.

Se registran logros al superar enemigos especiales.

El juego avanza en niveles (1 al 3 y jefe final).

------------------------------------------------------------------------------------------------------------------------
Aplicación de los temas vistos en Buho-Aventuras (con ejemplos del código)

Variables y tipos de datos
Usamos variables para almacenar la información vital de personajes, enemigos y objetos, como salud, ataque, defensa, y para controlar estados del juego.

int totalCurado = 0;  // Total de puntos de vida curados
bool usoObjetos = false;  // Indica si se usaron objetos
std::string nombre = p.nombre;  // Nombre de un personaje

------------------------------------------------------------------------------------------------------------------------
Estructuras condicionales (if, else, switch)
Controlan el flujo de la lógica, decidiendo acciones, aplicando efectos y validando entradas

if (enemigo.hp <= 0) {
    cout << "Enemigo derrotado!\n";
} else {
    cout << "El enemigo sigue con vida.\n";
}

switch (opcion) {
    case 1:
        atacar(p, enemigo);
        break;
    case 2:
        usarHabilidad(p, enemigo);
        break;
    case 3:
        usarObjeto(p, inventario);
        break;
    default:
        cout << "Opción inválida.\n";
        break;
}

------------------------------------------------------------------------------------------------------------------------

Ciclos (for, while, do while)
Permiten repetir acciones, como mostrar menús, recorrer personajes o mantener activa la batalla.

// For para mostrar barra de vida
for (size_t i = 0; i < equipo.size(); ++i) {
    mostrarBarraVida(equipo[i].nombre, equipo[i].hp, equipo[i].maxHp);
}

// While para mantener la batalla
while (enemigo.hp > 0 && any_alive(equipo)) {
    turnoJugador(equipo, enemigo);
    if (enemigo.hp <= 0) break;
    turnoEnemigo(enemigo, equipo);
}

// Do-while para validar opción
int opcion;
do {
    cout << "Elige opción (1-3): ";
    cin >> opcion;
} while (opcion < 1 || opcion > 3);

------------------------------------------------------------------------------------------------------------------------
Funciones
Organizan la lógica para reutilización y claridad.

void atacar(Personaje& atacante, Enemigo& enemigo) {
    int dano = max(0, atacante.atk - enemigo.def);
    enemigo.hp -= dano;
    cout << atacante.nombre << " ataca y causa " << dano << " de daño.\n";
}

bool batalla(std::vector<Personaje>& equipo, Enemigo& enemigo, std::vector<Item>& inventario, int& totalCurado, bool& usoObjetos);

------------------------------------------------------------------------------------------------------------------------

Estructuras de datos
Usamos struct para representar personajes, enemigos y objetos, y vectores para colecciones dinámicas.

struct Personaje {
    std::string nombre;
    int hp;
    int atk;
    int def;
    std::vector<std::string> habilidades;
};

std::vector<Personaje> equipo;

struct Item {
    std::string nombre;
    std::string efecto;
    int cantidad;
};

std::vector<Item> inventario;

------------------------------------------------------------------------------------------------------------------------

Manejo de archivos
El inventario se guarda y carga para mantener persistencia entre partidas.

void guardarInventario(const std::vector<Item>& inventario) {
    std::ofstream file("inventory.txt");
    for (const auto& item : inventario) {
        file << item.nombre << " " << item.cantidad << "\n";
    }
    file.close();
}

std::vector<Item> cargarInventario() {
    std::ifstream file("inventory.txt");
    std::vector<Item> inventario;
    if (file.is_open()) {
        // Código para leer y crear items
    }
    return inventario;
}

------------------------------------------------------------------------------------------------------------------------

Manejo de errores
Validamos entradas y estados para evitar fallos.

if (opcion < 1 || opcion > 3) {
    cout << "Opción inválida, intenta de nuevo.\n";
    return;
}

if (item.cantidad <= 0) {
    cout << "No quedan de ese objeto.\n";
    break;
}

------------------------------------------------------------------------------------------------------------------------

Interfaz por consola
Usamos colores y barras de vida para mejorar la experiencia visual.

void mostrarBarraVida(const std::string& nombre, int hp, int maxHp) {
    int barraLength = 30;
    int llenado = (hp * barraLength) / maxHp;

    std::string color;
    if (hp > maxHp * 0.5) color = "\033 32m";       // Verde
    else if (hp > maxHp * 0.2) color = "\033 33m";  // Amarillo
    else color = "\033 31m";                        // Rojo

    cout << nombre << ": " << color;
    for (int i = 0; i < llenado; ++i) cout << "#";
    cout << "\033[0m";
    for (int i = llenado; i < barraLength; ++i) cout << "-";
    cout << "] " << hp << "/" << maxHp << "\n";
}

------------------------------------------------------------------------------------------------------------------------

Consideraciones técnicas del desarrollo
Lenguaje: C++

Modularización clara con archivos .h y .cpp (Personajes, Items, Batalla, Estados, Logros, UI, Game)

Persistencia de datos con manejo de archivos

Interfaz en consola con ANSI para colores y estilos

Control de errores y validaciones de entrada

------------------------------------------------------------------------------------------------------------------------