#pragma once
#include "personajes.hpp"
#include "armas.hpp"
#include <memory>
#include <vector>

class MAGOS: public Personajes{
    protected:  
        string nombre;
        string tipo = "Mago";
        size_t nivelMagia;
        size_t puntosMana;
        vector<shared_ptr<ARMAS>> armas;

    public:
        MAGOS(string nomb, string tipo, size_t nivel, size_t mana, vector<shared_ptr<ARMAS>> armas);

        string getNombre() override;
        string getTipo() override;
        void AgregarArma() override;
        void QuitarArma() override;
        size_t getNivel();
        size_t getMana();
        virtual void Atacar() = 0;
        virtual void Meditar() = 0; // Recupera maná
        //virtual void Defender() = 0;
        virtual void UsarArma() = 0;
        virtual void MostrarEstado() = 0;

        ~MAGOS();
};