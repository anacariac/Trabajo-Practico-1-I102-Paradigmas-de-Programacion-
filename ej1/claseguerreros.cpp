#include "claseguerreros.hpp"
#include "clasemagica.hpp"
#include "clasedecombate.hpp" 
#include <iostream>
#include <algorithm>

GUERREROS::GUERREROS(string nomb, string tipo, size_t fuerza, size_t resistencia, vector<shared_ptr<ARMAS>> armas): nombre(nomb), tipo(tipo), fuerza(fuerza), resistencia(resistencia), armas(armas) {}

string GUERREROS::getNombre() {return nombre;}

string GUERREROS::getTipo() {return tipo;}

void GUERREROS::AgregarArma(shared_ptr<ARMAS> arma) {
    armas.push_back(arma);
    cout << nombre << " ha agregado un arma al inventario." << endl;
}

void GUERREROS::QuitarArma(shared_ptr<ARMAS> arma) {
    auto it = find(armas.begin(), armas.end(), arma);
    if (it != armas.end()) {
        armas.erase(it);
        cout << nombre << " ha quitado un arma del inventario." << endl;
    } else {
        cout << "El arma no está en el inventario." << endl;
    }
}

void GUERREROS::UsarArma() {
    if (armas.empty()) {
        cout << nombre << " no tiene armas equipadas." << endl;
        return;
    }

    auto arma = armas[armaSeleccionada];
    auto combate = dynamic_pointer_cast<ItemCombate>(arma);
    if (combate) {
        cout << nombre << " canaliza su poder de combate..." << endl;
        combate->UsoComun();
    } else {
        cout << nombre << " intenta usar un arma sin afinidad de combate..." << endl;
        
        // Calculando la reducción en el efecto de ataque si el arma no de combate
        size_t ataqueReducido = 0;
        if (auto magica = dynamic_pointer_cast<ItemMagicos>(arma)) {
            ataqueReducido = magica->getPowerModificado() / 2;  
            cout << "El ataque de " << nombre << " se ve reducido por falta de afinidad mágica. " 
                 << "El poder de ataque de esta arma es ahora " << ataqueReducido << "." << endl;
        } else {
            cout << "El arma equipada no tiene poder de combate adecuado." << endl;
        }
    }
}

void GUERREROS::CambiarArma(int indice) {
    if (indice >= 0 && indice < armas.size()) {
        armaSeleccionada = indice;
        cout << nombre << " ha cambiado al arma #" << indice + 1 << "." << endl;
    } else {
        cout << "Índice inválido. No se ha cambiado el arma." << endl;
    }
}

GUERREROS::~GUERREROS() {}