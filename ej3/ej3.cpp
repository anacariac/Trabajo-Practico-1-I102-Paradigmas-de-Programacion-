#include <iostream>
#include <memory>
#include <vector>
#include <ctime>   // time
#include "../ej2/funcionesauxiliares.hpp"
#include "../ej2/personajefactory.hpp"
using namespace std;
enum Acciones {GOLPE_FUERTE = 1, GOLPE_RAPIDO, DEFENSA_Y_GOLPE};

int main(){
    auto jugador1 = PersonajeFactory::CrearPersonajeAleatorio(rand() % 2, "1");
    jugador1->AgregarArma(PersonajeFactory::CrearArmaAleatoria(rand() % 2));

    auto jugador2 = PersonajeFactory::CrearPersonajeAleatorio(rand() % 2, "2");
    jugador2->AgregarArma(PersonajeFactory::CrearArmaAleatoria(rand() % 2));

    int hp1 = 100, hp2 = 100;
    while (hp1 > 0 && hp2 > 0) {
        cout << "Jugador 1 (" << jugador1->getNombre() << ") tiene " << hp1 << " HP.\n";
        cout << "Jugador 2 (" << jugador2->getNombre() << ") tiene " << hp2 << " HP.\n";

        int opcion1;

        do {
            cout << "Su opción: (1) Golpe Fuerte, (2) Golpe Rápido, (3) Defensa y Golpe: ";
            cin >> opcion1;

            if (opcion1 < 1 || opcion1 > 3) {
                cout << "Opción no válida. Por favor, elija una opción entre 1 y 3.\n";
            }

        } while (opcion1 < 1 || opcion1 > 3); // Repite hasta que la opción sea válida

        int opcion2 = rand() % 3 + 1;

        auto armaUsada1 = jugador1->getArmas()[0];
        auto armaUsada2 = jugador2->getArmas()[0];

        // Mostrar acciones
        cout << jugador1->getNombre() << " atacó con " << armaUsada1->getNombre() << " usando acción " << opcion1 << "\n";
        cout << jugador2->getNombre() << " atacó con " << armaUsada2->getNombre() << " usando acción " << opcion2 << "\n";

        // Aplicar reglas
        if (opcion1 == opcion2) {
            cout << "¡Empate! Nadie recibe daño.\n";
        } else if (
            (opcion1 == GOLPE_FUERTE && opcion2 == GOLPE_RAPIDO) ||
            (opcion1 == GOLPE_RAPIDO && opcion2 == DEFENSA_Y_GOLPE) ||
            (opcion1 == DEFENSA_Y_GOLPE && opcion2 == GOLPE_FUERTE)
        ) {
            cout << jugador1->getNombre() << " hizo 10 puntos de daño.\n";
            hp2 -= 10;
        } else {
            cout << jugador2->getNombre() << " hizo 10 puntos de daño.\n";
            hp1 -= 10;
        }

        cout << "-----------------------------------\n";
    }

    if (hp1 <= 0)
        cout << jugador2->getNombre() << " ganó la batalla.\n";
    else
        cout << jugador1->getNombre() << " ganó la batalla.\n";
    return 0;
}
