#include "claseguerreros.hpp"
#include "clasemagica.hpp"
#include "clasedecombate.hpp" 
#include <iostream>
#include <algorithm>

GUERREROS::GUERREROS(string nomb, int hp, size_t fuerza, size_t resistencia, vector<unique_ptr<ARMAS>> armas): nombre(nomb), HP(hp), fuerza(fuerza), resistencia(resistencia), armas(move(armas)) {}

string GUERREROS::getNombre() {return nombre;}

string GUERREROS::getTipo() {return tipo;}

size_t GUERREROS::getHP() {return HP;}

void GUERREROS::setHP(int nuevoHP) { HP = nuevoHP; }

void GUERREROS::Daño(size_t cantidad) {
    HP -= cantidad;
    if (HP < 0) HP = 0;
}

size_t GUERREROS::getFuerza(){return fuerza;}

size_t GUERREROS::getResistencia(){return resistencia;}

const vector<unique_ptr<ARMAS>>& GUERREROS::getArmas(){ return armas;}

void GUERREROS::AgregarArma(unique_ptr<ARMAS> arma) {
    if (armas.size() >= 2) {
        cout << "Este mago ya posee el máximo de armas permitidas (2)." << endl;
        return;
    }
    armas.push_back(move(arma));
    cout << nombre << " ha agregado un arma al inventario." << endl;
}

void GUERREROS::QuitarArma(unique_ptr<ARMAS> arma) {
    auto it = find_if(armas.begin(), armas.end(), [&arma](const unique_ptr<ARMAS>& a) {
        return a.get() == arma.get();
    });
    if (it != armas.end()) {
        armas.erase(it);
        cout << nombre << " ha quitado un arma del inventario." << endl;
    } else {
        cout << "El arma no está en el inventario." << endl;
    }
}

void GUERREROS::UsarArma() {
    if (armas.empty() || static_cast<size_t>(armaSeleccionada) >= armas.size()) {
        cout << nombre << " no tiene armas equipadas." << endl;
        return;
    }

    const unique_ptr<ARMAS>& arma = armas[armaSeleccionada];
    
    if (arma->getTipo()=="Combate") {
        cout << nombre << " canaliza su poder de combate..." << endl;
        arma->getPowerModificado();
    } else {
        cout << nombre << " intenta usar un arma sin afinidad de combate..." << endl;
        
        // Calculando la reducción en el efecto de ataque si el arma no de combate
        size_t ataqueReducido = 0;
        if (arma->getTipo()=="Magico") {
            ataqueReducido = arma->getPowerModificado() / 2;  
            cout << "El ataque de " << nombre << " se ve reducido por falta de afinidad mágica. " 
                 << "El poder de ataque de esta arma es ahora " << ataqueReducido << "." << endl;
        } else {
            cout << "El arma equipada no tiene poder de combate adecuado." << endl;
        }
    }
    //delete combate;
}

void GUERREROS::CambiarArma(int indice) {
    if (indice >= 0 && indice < static_cast<int>(armas.size()))
 {
        armaSeleccionada = indice;
        cout << nombre << " ha cambiado al arma #" << indice + 1 << "." << endl;
    } else {
        cout << "Índice inválido. No se ha cambiado el arma." << endl;
    }
}

GUERREROS::~GUERREROS() {}