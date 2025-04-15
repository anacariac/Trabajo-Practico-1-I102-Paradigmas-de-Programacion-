#pragma once
#include "personajes.hpp"
#include "armas.hpp"
#include <vector>
#include <memory>

class GUERREROS: public Personajes{
    protected:
        string nombre;
        string tipo = "Guerrero";
        int HP;
        size_t fuerza;
        size_t resistencia;
        vector<unique_ptr<ARMAS>> armas;
        int armaSeleccionada = 0; // por defecto usa la primera arma
        GUERREROS(string nomb, int hp, size_t fuerza, size_t resistencia, vector<unique_ptr<ARMAS>> armas);

    public:

        string getNombre() override;
        string getTipo() override;
        size_t getHP() override;
        void setHP( int nuevohp) override;
        void Daño( size_t cant) override;
        void AgregarArma(unique_ptr<ARMAS> arma) override;
        void QuitarArma(unique_ptr<ARMAS> arma)override;
        const vector<unique_ptr<ARMAS>>& getArmas() override;
        void UsarArma() override;
        size_t getFuerza();
        size_t getResistencia();
        void CambiarArma(int indice);
        virtual void Atacar() = 0;
        virtual void Descansar() = 0;
        virtual void MostrarEstado() = 0;


        ~GUERREROS();
};