#include "personajesmagicos.hpp"
#include <iostream>

Hechicero::Hechicero(string nomb, int hp, size_t nivel, size_t mana, vector<unique_ptr<ARMAS>> armas, TipoHechicero tipoH): MAGOS(nomb, hp, nivel, mana, move(armas)), tipoHechicero(tipoH) {}

void Hechicero::Atacar() {
    cout << nombre << " lanza un hechizo básico desde su varita mágica." << endl;
    puntosMana -= 10;
}

void Hechicero::Meditar() {
    cout << nombre << " medita profundamente, recuperando su energía mística..." << endl;
    puntosMana += 25;
}

void Hechicero::UsarArma() {
     MAGOS::UsarArma();
}

void Hechicero::MostrarEstado() {
    cout << "\nNombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Nivel de Magia: " << nivelMagia << endl;
    cout << "Puntos de Maná: " << puntosMana << endl;
    cout << "Tipo de Hechicero: ";
    switch (tipoHechicero) {
        case TipoHechicero::ANIMAGOS: cout << "Animagos" << endl; break;
        case TipoHechicero::MORTIFAGOS: cout << "Mortífagos" << endl; break;
        case TipoHechicero::ELITE: cout << "Elite" << endl; break;
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

size_t Hechicero::Cambiaforma() {
    if (tipoHechicero == TipoHechicero::ANIMAGOS) {
        cout << nombre << " se transforma en un hombre lobo, aumentando su poder de ataque temporalmente." << endl;
        return 40;
    }
    cout << nombre << " no es un animago, no puede cambiar de forma." << endl;
    return 0;
}

size_t Hechicero::MaldicionIlimitada() {
    if (tipoHechicero == TipoHechicero::MORTIFAGOS || tipoHechicero == TipoHechicero::ELITE) {
        cout << nombre << " lanza una maldición oscura de poder ilimitado..." << endl;
        puntosMana -= 30;
        return 60;
    }
    cout << nombre << " no domina la maldición ilimitada." << endl;
    return 0;
}

Brujo::Brujo(string nomb, int hp, size_t nivel, size_t mana, vector<unique_ptr<ARMAS>> armas, TipoBrujo tipoBrujo): MAGOS(nomb, hp, nivel, mana, move(armas)), tipoBrujo(tipoBrujo) {}

void Brujo::Atacar() {
    cout << nombre << " lanza un hechizo oscuro." << endl;
    puntosMana -= 10;
}

void Brujo::Meditar() {
    cout << nombre << " medita y recupera su maná..." << endl;
    puntosMana += 20;
}

void Brujo::UsarArma() {
    MAGOS::UsarArma();
}

void Brujo::MostrarEstado() {
    cout << "\nNombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Nivel de Magia: " << nivelMagia << endl;
    cout << "Puntos de Maná: " << puntosMana << endl;
    cout << "Tipo de Brujo: ";
    switch (tipoBrujo) {
        case TipoBrujo::MAGIA_BLANCA: cout << "Magia Blanca" << endl; break;
        case TipoBrujo::MAGIA_NEGRA: cout << "Magia Negra" << endl; break;
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
size_t Brujo::LlamadoAquelarre() {
    cout << nombre << " invoca a su aquelarre para asistirlo en combate!" << endl;
    return 30;
}

Conjurador::Conjurador(string nomb, int hp, size_t nivel, size_t mana, vector<unique_ptr<ARMAS>> armas, TipoBrujo tipoConjurador): MAGOS(nomb, hp, nivel, mana, move(armas)), tipoConjurador(tipoConjurador) {}

void Conjurador::Atacar() {
    cout << nombre << " lanza una invocación de daño mágico." << endl;
    puntosMana -= 8;
}

void Conjurador::Meditar() {
    cout << nombre << " entra en trance y recupera maná." << endl;
    puntosMana += 18;
}

void Conjurador::UsarArma() {
    MAGOS::UsarArma();
}

void Conjurador::MostrarEstado() {
    cout << "\nNombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Nivel de Magia: " << nivelMagia << endl;
    cout << "Puntos de Maná: " << puntosMana << endl;
    cout << "Tipo de Conjurador: ";
    switch (tipoConjurador) {
        case TipoBrujo::MAGIA_BLANCA: cout << "Magia Blanca" << endl; break;
        case TipoBrujo::MAGIA_NEGRA: cout << "Magia Negra" << endl; break;
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

size_t Conjurador::InvocacionBestiasProtectoras() {
    cout << nombre << " invoca bestias mágicas para protegerlo en combate!" << endl;
    return 40;
}

Nigromante::Nigromante(string nomb, int hp, size_t nivel, size_t mana, vector<unique_ptr<ARMAS>> armas, size_t almas): MAGOS(nomb, hp, nivel, mana, move(armas)), cantAlmas(almas) {}

void Nigromante::Atacar() {
    cout << nombre << " invoca un alma para atacar al enemigo." << endl;
    if (cantAlmas > 0) cantAlmas--;
    puntosMana -= 12;
}

void Nigromante::Meditar() {
    cout << nombre << " absorbe energía oscura para recuperar maná." << endl;
    puntosMana += 25;
    cantAlmas += 2;
}

void Nigromante::UsarArma() {
    MAGOS::UsarArma();
}

void Nigromante::MostrarEstado() {
    cout << "\nNombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Nivel de Magia: " << nivelMagia << endl;
    cout << "Puntos de Maná: " << puntosMana << endl;
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

size_t Nigromante::EjercitodeAlmas() {
    if(cantAlmas>0){
        cout << nombre << " libera un ejército de almas para arrasar al enemigo!" << endl;
        size_t dano = 10 * cantAlmas;
        cantAlmas = 0;
        return dano;   
    }
    cout<<"No tiene almas de reserva! No puede hacer el ataque"<<endl;
    return 0;
}

