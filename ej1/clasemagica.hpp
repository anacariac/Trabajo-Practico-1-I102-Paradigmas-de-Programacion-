#pragma once
#include "armas.hpp"

class ItemMagicos: public ARMAS{
protected:
    string nombre;
    string tipo = "Magico";
    size_t power;
    Rareza rareza;

public:
    //CONSTRUCTOR
    ItemMagicos(string nomb, size_t power, Rareza rareza);
	//GETTERS
    string getNombre() override;
    string getTipo() override;
    Rareza getRareza();
    size_t getPowerModificado() override;
    size_t getPower(); // Cuanto power le quita al enemigo
    //METODO VIRTUAL PURO
    virtual void UsoComun() = 0; // imprime que hace el objeto
	//DESTRUCTOR
    ~ItemMagicos() override;
};