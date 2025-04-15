#include "clasemagica.hpp"
#include <iostream>

ItemMagicos::ItemMagicos(string nomb, size_t power, Rareza rareza):nombre(nomb),power(power),rareza(rareza){}

string ItemMagicos::getNombre(){return nombre;};

string ItemMagicos::getTipo(){return tipo;};

Rareza ItemMagicos::getRareza(){return rareza;};

size_t ItemMagicos::getPower(){return power;}; 

size_t ItemMagicos::getPowerModificado() {
    if(rareza == Rareza::COMUN){
         return power;
     } 
    else if(rareza == Rareza::RARO){
          return static_cast<size_t>(power * 1.25);
     }
     else{
         return static_cast<size_t>(power * 1.5);
     } 
 }
 
ItemMagicos::~ItemMagicos(){}