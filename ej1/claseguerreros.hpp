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
        int armaSeleccionada = 0; // por defecto usa la primera arma

    public:
        GUERREROS(string nomb,string tipo, size_t fuerza, size_t resistencia, vector<shared_ptr<ARMAS>> armas);

        string getNombre() override;
        string getTipo() override;
        void AgregarArma(shared_ptr<ARMAS> arma) override;
        void QuitarArma(shared_ptr<ARMAS> arma)override;
        vector<shared_ptr<ARMAS>> getArmas() override;
        virtual void Atacar() = 0;
        virtual void Descansar() = 0;
        void UsarArma() override;
        void CambiarArma(int indice);
        virtual void MostrarEstado() = 0;

        ~GUERREROS();
};