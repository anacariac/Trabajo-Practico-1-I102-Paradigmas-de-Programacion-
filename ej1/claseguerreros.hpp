#pragma once
#include "personajes.hpp"
#include "armas.hpp"
#include <vector>
#include <memory>

class GUERREROS: public Personajes{
    protected:
        string nombre;
        string tipo = "Guerrero";
        size_t fuerza;
        size_t resistencia;
        vector<shared_ptr<ARMAS>> armas;
    public:
        GUERREROS(string nomb,string tipo, size_t fuerza, size_t resistencia, vector<shared_ptr<ARMAS>> armas);

        string getNombre() override;
        string getTipo() override;
        void AgregarArma() override;
        void QuitarArma()override;
        virtual void Atacar() = 0;
        virtual void Descansar() = 0;
        //virtual void Defender() = 0;
        virtual void UsarArma() = 0;
        virtual void MostrarEstado() = 0;

        ~GUERREROS();
};