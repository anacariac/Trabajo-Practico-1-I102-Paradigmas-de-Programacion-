#include <iostream>
#include <memory>
#include <vector>
#include <ctime>   // time
#include "../ej2/funcionesauxiliares.hpp"
#include "../ej2/personajefactory.hpp"
using namespace std;
enum Acciones {GOLPE_FUERTE = 1, GOLPE_RAPIDO, DEFENSA_Y_GOLPE};

int main(){
    srand(time(nullptr));
    auto jugador1 = PersonajeFactory::CrearPersonajeAleatorio(rand() % 2, "1");
    jugador1->AgregarArma(PersonajeFactory::CrearArmaAleatoria(rand() % 2));

    auto jugador2 = PersonajeFactory::CrearPersonajeAleatorio(rand() % 2, "2");
    jugador2->AgregarArma(PersonajeFactory::CrearArmaAleatoria(rand() % 2));

    while (jugador1->getHP() > 0 && jugador2->getHP()> 0) {
        cout << "El Jugador 1 (" << jugador1->getNombre() << ") tiene " << jugador1->getHP() << " HP.\n";
        cout << "El Jugador 2 (" << jugador2->getNombre() << ") tiene " << jugador2->getHP() << " HP.\n";

        int opcion1;

        do {
            cout << "Su opción: (1) Golpe Fuerte, (2) Golpe Rápido, (3) Defensa y Golpe: ";
            cin >> opcion1;

            if (opcion1 < 1 || opcion1 > 3) {
                cout << "Opción no válida. Por favor, elija una opción entre 1 y 3.\n";
            }

        } while (opcion1 < 1 || opcion1 > 3); // Repite hasta que la opción sea válida

        int opcion2 = rand() % 3 + 1;

        auto& armaUsada1 = jugador1->getArmas()[0]; //usamos el arma principal por default
        auto& armaUsada2 = jugador2->getArmas()[0];

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
            cout << jugador1->getNombre() << " hizo "<<armaUsada1->getPowerModificado()<<" puntos de daño.\n";
            jugador2->Daño(armaUsada1->getPowerModificado());
        } else {
            cout << jugador2->getNombre() << " hizo "<<armaUsada2->getPowerModificado()<<" puntos de daño.\n";
            jugador1->Daño(armaUsada2->getPowerModificado());
        }

        cout << "-----------------------------------\n";
    }

    if (jugador1->getHP() <= 0)
        cout << jugador2->getNombre() << " ganó la batalla! Festeja con el Baile de la Victoria!\n";
    else
        cout << jugador1->getNombre() << " ganó la batalla! Festeja con el Baile de la Victoria!\n";
    return 0;
}
