#include "personajefactory.hpp"
#include <iostream>

int main() {
    srand(time(nullptr));
    PersonajeFactory fabrica;
    auto personajes = fabrica.CrearPersonajesConArmas();

    cout << "\n==== PERSONAJES GENERADOS ====\n";
    for (const auto& personaje : personajes) {
        cout << "Nombre: " << personaje->getNombre() << endl;
        cout << "Tipo: " << personaje->getTipo() << endl;
        cout << "HP: " << personaje->getHP() << endl;
        cout << "Armas:\n";
        if((personaje->getArmas()).size()==0){
            cout<<"Ninguna"<<endl;
        }
        for (const auto& arma : personaje->getArmas()) {
            cout<<arma->getNombre()<<"-> "<<arma->getTipo()<<endl;
        }
        cout << "--------------------------\n";
    }

    return 0;
}