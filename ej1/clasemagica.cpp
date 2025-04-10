#include "clasemagica.hpp"
#include <iostream>

ItemMagicos::ItemMagicos(string nomb, size_t power, Rareza rareza):nombre(nomb),power(power),rareza(rareza){}

string ItemMagicos::getNombre(){return nombre;};

string ItemMagicos::getTipo(){return tipo;};

Rareza ItemMagicos::getRareza(){return rareza;};

size_t ItemMagicos::getPower(){return power;}; 

ItemMagicos::~ItemMagicos(){}