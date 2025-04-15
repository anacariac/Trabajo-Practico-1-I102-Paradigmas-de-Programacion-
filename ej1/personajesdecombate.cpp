#include "personajesdecombate.hpp"
#include <iostream>

Barbaro::Barbaro(string nomb, int hp, size_t fuerza, size_t resistencia, vector<unique_ptr<ARMAS>> armas, TipoBarbaro tipoBarbaro): GUERREROS(nomb, hp, fuerza, resistencia, move(armas)), tipoBarbaro(tipoBarbaro) {}

void Barbaro::Atacar() {
    cout << nombre << " ataca con furia bestial!" << endl;
    resistencia -= 10;
}

void Barbaro::Descansar() {
    resistencia += 10;
    cout << nombre << " descansa y recupera resistencia." << endl;
}

void Barbaro::UsarArma() {
    GUERREROS::UsarArma();
}

void Barbaro::MostrarEstado() {
    cout << "\nNombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Resistencia: " << resistencia << endl;
    cout << "Tipo de Barbaro: ";
    switch (tipoBarbaro) {
        case TipoBarbaro::OGRO: cout << "Ogro" << endl; break;
        case TipoBarbaro::TITAN: cout << "Titan" << endl; break;
        case TipoBarbaro::CICLOPE: cout << "Cicliope" << endl; break;
    }
    cout << "Armas: ";
    if (armas.empty()) {
        cout << "ninguna" << endl;
    } else {
        for (const auto& arma : armas) {
            cout << arma->getNombre() << "\n       ";
        }
        cout << endl;
    }
}

size_t Barbaro::AplastamientoColosal() {
    cout << nombre << " realiza un aplastamiento colosal con su arma!" << endl;
    return fuerza * 2;
}

Paladin::Paladin(string nomb, int hp, size_t fuerza, size_t resistencia, vector<unique_ptr<ARMAS>> armas, bool bendecido): GUERREROS(nomb, hp, fuerza, resistencia, move(armas)), bendecido(bendecido) {}

void Paladin::Atacar() {
    cout << nombre << " ataca con justicia divina!" << endl;
    resistencia -= 10;
}

void Paladin::Descansar() {
    resistencia += 15;
    cout << nombre << " descansa bajo una bendicion sagrada." << endl;
}

void Paladin::UsarArma() {
    GUERREROS::UsarArma();
}

void Paladin::MostrarEstado() {
    cout << "\nNombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Resistencia: " << resistencia << endl;
    cout << "Armas: ";
    if (armas.empty()) {
        cout << "ninguna" << endl;
    } else {
        for (const auto& arma : armas) {
            cout << arma->getNombre() << "\n       ";
        }
        cout << endl;
    }
}

size_t Paladin::AyudaDivina() {
    if (bendecido) {
        cout << nombre << " recibe la ayuda divina! Su fuerza aumenta." << endl;
        return fuerza + 20;
    }
    return fuerza;
}

Caballero::Caballero(string nomb, int hp, size_t fuerza, size_t resistencia, vector<unique_ptr<ARMAS>> armas, TipoCaballero tipoBarbaro): GUERREROS(nomb, hp, fuerza, resistencia, move(armas)), tipoCaballero(tipoBarbaro) {}

void Caballero::Atacar() {
    cout << nombre << " ataca con honor!" << endl;
    resistencia -= 10;
}

void Caballero::Descansar() {
    resistencia += 10;
    cout << nombre << " descansa para su proxima batalla." << endl;
}

void Caballero::UsarArma() {
    GUERREROS::UsarArma();
}

void Caballero::MostrarEstado() {
    cout << "\nNombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Resistencia: " << resistencia << endl;
    cout << "Tipo de Caballero: ";
    switch (tipoCaballero) {
        case TipoCaballero::ZODIACO: cout << "Caballero del Zodiaco" << endl; break;
        case TipoCaballero::DE_ARTURO: cout << "Caballero de la Mesa Redonda" << endl; break;
    }
    cout << "Armas: ";
    if (armas.empty()) {
        cout << "ninguna" << endl;
    } else {
        for (const auto& arma : armas) {
            cout << arma->getNombre() << "\n       ";
        }
        cout << endl;
    }

}

size_t Caballero::ShakaDeVirgo() {
    if (tipoCaballero == TipoCaballero::ZODIACO) {
        cout << nombre << " recibe el poder de Shaka de Virgo!" << endl;
        return fuerza + 30;
    }
    return fuerza;
}

size_t Caballero::SantoGrial() {
    if (tipoCaballero == TipoCaballero::DE_ARTURO) {
        cout << nombre << " bebe del Santo Grial y recupera fuerzas!" << endl;
        return fuerza + 25;
    }
    return fuerza;
}

Mercenario::Mercenario(string nomb, int hp, size_t fuerza, size_t resistencia, vector<unique_ptr<ARMAS>> armas, int oro): GUERREROS(nomb, hp, fuerza, resistencia, move(armas)), oro(oro) {}

void Mercenario::Atacar() {
    cout << nombre << " ataca motivado por el oro!" << endl;
    resistencia -= 10;
}

void Mercenario::Descansar() {
    resistencia += 10;
    cout << nombre << " descansa brevemente." << endl;
}

void Mercenario::UsarArma() {
    GUERREROS::UsarArma();
}

void Mercenario::MostrarEstado() {
    cout << "\nNombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Resistencia: " << resistencia << endl;
    cout << "Oro: "<< oro<<endl;
    cout << "Armas: ";
    if (armas.empty()) {
        cout << "ninguna" << endl;
    } else {
        for (const auto& arma : armas) {
            cout << arma->getNombre() << "\n       ";
        }
        cout << endl;
    }
}

void Mercenario::RecolectarBotin() {
    int botin = 50;
    oro += botin;
    cout << nombre << " recolecta botin y gana " << botin << " monedas de oro!" << endl;
}

Gladiador::Gladiador(string nomb, int hp, size_t fuerza, size_t resistencia, vector<unique_ptr<ARMAS>> armas, bool arena): GUERREROS(nomb, hp, fuerza, resistencia, move(armas)), enArena(arena) {}

void Gladiador::Atacar() {
    cout << nombre << " desata su furia en combate!" << endl;
    resistencia -= 10;
}

void Gladiador::Descansar() {
    resistencia += 10;
    cout << nombre << " se recupera entre peleas." << endl;
}

void Gladiador::UsarArma() {
    GUERREROS::UsarArma();
}

void Gladiador::MostrarEstado() {
    cout << "\nNombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Resistencia: " << resistencia << endl;
    cout << "Armas: ";
    if (armas.empty()) {
        cout << "ninguna" << endl;
    } else {
        for (const auto& arma : armas) {
            cout << arma->getNombre() << "\n       ";
        }
        cout << endl;
    }
}

size_t Gladiador::EnArena() {
    if (enArena) {
        cout << nombre << " se encuentra en la arena y lucha con valentia!" << endl;
        return fuerza + 15;
    }
    return fuerza;
}
