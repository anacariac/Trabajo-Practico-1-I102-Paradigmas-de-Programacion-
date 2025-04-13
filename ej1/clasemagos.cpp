#include "clasemagos.hpp"
#include "clasemagica.hpp"
#include "clasedecombate.hpp" 
#include <iostream>
#include <algorithm>

MAGOS::MAGOS(string nomb, string tipoMago, size_t nivel, size_t mana, vector<shared_ptr<ARMAS>> armasIniciales): nombre(nomb), tipo(tipoMago), nivelMagia(nivel), puntosMana(mana), armas(armasIniciales) {}

string MAGOS::getNombre() {return nombre;}

string MAGOS::getTipo() {return tipo;}

size_t MAGOS::getNivel() {return nivelMagia;}

size_t MAGOS::getMana() {return puntosMana;}

void MAGOS::CambiarArma(int indice) {
    if (indice >= 0 && indice < static_cast<int>(armas.size())) {
        armaSeleccionada = indice;
        cout << "Has cambiado al arma #" << indice + 1 << "." << endl;
    } else {
        cout << "Índice inválido. No se ha cambiado el arma." << endl;
    }
}

void MAGOS::UsarArma() {
    if (armas.empty() || static_cast<size_t>(armaSeleccionada) >= armas.size()) {
        cout << nombre << " no tiene un arma válida para usar." << endl;
        return;
    }

    auto arma = armas[armaSeleccionada];
    auto magica = dynamic_pointer_cast<ItemMagicos>(arma);
    if (magica) {
        cout << nombre << " canaliza su poder mágico..." << endl;
        magica->UsoComun();
    } else {
        cout << nombre << " intenta usar un arma sin afinidad mágica..." << endl;
        
        // Calculando la reducción en el efecto de ataque si el arma no es mágica
        size_t ataqueReducido = 0;
        if (auto combate = dynamic_pointer_cast<ItemCombate>(arma)) {
            ataqueReducido = combate->getPowerModificado() / 2;  
            cout << "El ataque de " << nombre << " se ve reducido por falta de afinidad mágica. " 
                 << "El poder de ataque de esta arma es ahora " << ataqueReducido << "." << endl;
        } else {
            cout << "El arma equipada no tiene poder de combate adecuado." << endl;
        }
    }
}


void MAGOS::AgregarArma(shared_ptr<ARMAS> arma) {
    if (armas.size() >= 2) {
        cout << "Este mago ya posee el máximo de armas permitidas (2)." << endl;
        return;
    }

    armas.push_back(arma);
    cout << nombre << " ha agregado un arma al inventario." << endl;
}

void MAGOS::QuitarArma(shared_ptr<ARMAS> arma) {
    auto it = find(armas.begin(), armas.end(), arma);
    if (it != armas.end()) {
        armas.erase(it);
        cout << "Arma removida!" << endl;
    } else {
        cout << "El mago no posee esa arma." << endl;
    }
}

MAGOS::~MAGOS() {}