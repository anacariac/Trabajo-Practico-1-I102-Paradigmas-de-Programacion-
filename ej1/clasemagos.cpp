#include "clasemagos.hpp"
#include "clasemagica.hpp"
#include "clasedecombate.hpp" 
#include <iostream>
#include <algorithm>

MAGOS::MAGOS(string nomb,int hp, size_t nivel, size_t mana, vector<unique_ptr<ARMAS>> armasIniciales): nombre(nomb), HP(hp), nivelMagia(nivel), puntosMana(mana), armas(move(armasIniciales)) {}

string MAGOS::getNombre() {return nombre;}

string MAGOS::getTipo() {return tipo;}

size_t MAGOS::getHP() {return HP;}

void MAGOS::setHP(int nuevoHP) { HP = nuevoHP; }

void MAGOS::Daño(size_t cantidad) {
    HP -= cantidad;
    if (HP < 0) HP = 0;
}

size_t MAGOS::getNivel() {return nivelMagia;}

size_t MAGOS::getMana() {return puntosMana;}

const vector<unique_ptr<ARMAS>>& MAGOS::getArmas(){ return armas;}

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

    const auto& arma = armas[armaSeleccionada]; //no copiams
    auto* magica = dynamic_cast<ItemMagicos*>(arma.get()); //trabajamos con rawpointers de manera general
    if (magica) {
        cout << nombre << " canaliza su poder mágico..." << endl;
        magica->UsoComun();
    } else {
        cout << nombre << " intenta usar un arma sin afinidad mágica..." << endl;
        
        // Calculando la reducción en el efecto de ataque si el arma no es mágica
        size_t ataqueReducido = 0;
        if (auto* combate = dynamic_cast<ItemCombate*>(arma.get())) {
            ataqueReducido = combate->getPowerModificado() / 2;  
            cout << "El ataque de " << nombre << " se ve reducido por falta de afinidad mágica. " 
                 << "El poder de ataque de esta arma es ahora " << ataqueReducido << "." << endl;
        } else {
            cout << "El arma equipada no tiene poder de combate adecuado." << endl;
        }
    }
}


void MAGOS::AgregarArma(unique_ptr<ARMAS> arma) {
    if (armas.size() >= 2) {
        cout << "Este mago ya posee el máximo de armas permitidas (2)." << endl;
        return;
    }

    armas.push_back(move(arma));
    cout << nombre << " ha agregado un arma al inventario." << endl;
}

void MAGOS::QuitarArma(unique_ptr<ARMAS> arma) {
    auto it = find_if(armas.begin(), armas.end(), [&arma](const unique_ptr<ARMAS>& a){
        return a.get() == arma.get();
    });
    if (it != armas.end()) {
        armas.erase(it);
        cout << "Arma removida!" << endl;
    } else {
        cout << "El mago no posee esa arma." << endl;
    }
}

MAGOS::~MAGOS() {}