#pragma once
#include "armas.hpp"

class ItemFisicos: public ARMAS{
    protected:
        string nombre;
        string tipo = "Combate";
        size_t precision;
        size_t hp;

    public:
        string getNombre() override;
        string getTipo() override;
        virtual size_t getAcurracy() =0; // la precision depende de si el arma esta relacionada con el personaje
        virtual size_t getHP() =0;// Cuanto HP le quita al enemigo
        ~ItemFisicos() override; 
    };