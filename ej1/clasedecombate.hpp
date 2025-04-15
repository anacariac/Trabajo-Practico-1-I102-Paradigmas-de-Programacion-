#pragma once
#include "armas.hpp"

class ItemCombate: public ARMAS{
protected:
    string nombre;
    string tipo = "Combate";
    size_t power;
    float filo;
    Rareza rareza;

public:
    //CONSTRUCTOR
    ItemCombate(string nomb, size_t power, float filo,  Rareza rareza);
    //GETTERS
    string getNombre() override;
    string getTipo() override;
    Rareza getRareza();
    virtual float getFilo();
    size_t getPowerModificado() override;
    size_t getPower(); // Cuanto power le quita al enemigo
    //METODO VIRTUAL PURO
    virtual void UsoComun() = 0; // imprime que hace el objeto
    // DESTRUCTOR
    ~ItemCombate() override;

};