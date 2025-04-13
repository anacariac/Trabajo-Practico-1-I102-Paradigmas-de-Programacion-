#include "clasedecombate.hpp"
#include <iostream>

ItemCombate::ItemCombate(string nomb, size_t pow, float filoVal, Rareza rare): nombre(nomb), power(pow), filo(filoVal), rareza(rare) {}

string ItemCombate::getNombre() {return nombre;}

string ItemCombate::getTipo() {return tipo;}

Rareza ItemCombate::getRareza() {return rareza;}

float ItemCombate::getFilo() { return filo; }

size_t ItemCombate::getPower() {return power;}

size_t ItemCombate::getPowerModificado() {
    // Modificador de poder basado en rareza
    switch (rareza) {
        case Rareza::COMUN:
            return power;
        case Rareza::RARO:
            return static_cast<size_t>(power * 1.25);
        case Rareza::LEGENDARIO:
            return static_cast<size_t>(power * 1.5);
        default:
            return power;
    }
}

ItemCombate::~ItemCombate() {}// Destructor virtual por herencia