#pragma once
#include <string>
enum class Rareza {COMUN, RARO, LEGENDARIO}; 
using namespace std;

class ARMAS{
public:
    virtual string getNombre() = 0; //Nombre del arma
    virtual string getTipo() = 0; // Tipo ["Magico","Combate"]
    virtual size_t getPowerModificado() = 0;
    virtual ~ARMAS() {};
};