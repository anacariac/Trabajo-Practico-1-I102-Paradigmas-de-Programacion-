#pragma once
#include "armas.hpp"

class ItemMagicos: public ARMAS{
protected:
    string nombre;
    string tipo = "Magico";
    size_t power;
    Rareza rareza;

public:
    ItemMagicos(string nomb, size_t power, Rareza rareza);

    string getNombre() override;
    string getTipo() override;
    Rareza getRareza();
    size_t getPowerModificado() override;
    size_t getPower(); // Cuanto power le quita al enemigo
    virtual void UsoComun() = 0; // imprime que hace el objeto

    ~ItemMagicos() override;

};