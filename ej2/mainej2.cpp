#include "personajefactory.hpp"
#include <iostream>

int main() {
    PersonajeFactory fabrica;
    auto personajes = fabrica.CrearPersonajesConArmas();

    cout << "\n==== PERSONAJES GENERADOS ====\n";
    for (const auto& personaje : personajes) {
        if (auto mago = dynamic_pointer_cast<MAGOS>(personaje)) {
            mago->MostrarEstado();
        } else if (auto guerrero = dynamic_pointer_cast<GUERREROS>(personaje)) {
            guerrero->MostrarEstado();
        } else {
            cout << "Tipo de personaje desconocido.\n";
        }
    }

    return 0;
}