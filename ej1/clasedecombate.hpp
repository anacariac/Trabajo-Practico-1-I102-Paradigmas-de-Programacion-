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
    ItemCombate(string nomb, size_t power, float filo,  Rareza rareza);

    string getNombre() override;
    string getTipo() override;
    Rareza getRareza();
    virtual float getFilo();
    size_t getPowerModificado() override;
    size_t getPower(); // Cuanto power le quita al enemigo, depende del ataque que haga luego visto en los personajes
    virtual void UsoComun() = 0; // imprime que hace el objeto

    ~ItemCombate() override;

};