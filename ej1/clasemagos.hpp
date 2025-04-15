#pragma once
#include "personajes.hpp"
#include "armas.hpp"
#include <memory>
#include <vector>

class MAGOS: public Personajes{
    protected:  
        string nombre;
        string tipo = "Mago";
        int HP;
        size_t nivelMagia;
        size_t puntosMana;
        vector<unique_ptr<ARMAS>> armas;
        int armaSeleccionada = 0; // por defecto usa la primera arma
        MAGOS(string nomb, int hp, size_t nivel, size_t mana, vector<unique_ptr<ARMAS>> armas);

    public:
        //GETTERS
        string getNombre() override;
        string getTipo() override;
        size_t getHP() override;
        size_t getNivel();
        size_t getMana();
        //SETTER
        void setHP( int nuevohp) override;
        //METODOS A IMPLEMENTAR
        void Daño( size_t cant) override;
        void AgregarArma(unique_ptr<ARMAS> arma)override;
        void QuitarArma(unique_ptr<ARMAS> arma) override;
        const vector<unique_ptr<ARMAS>>& getArmas() override;
        void UsarArma() override;
        void CambiarArma(int indice);
        virtual void Atacar() = 0;
        virtual void Meditar() = 0; // Recupera maná
        virtual void MostrarEstado() = 0;
        //DESTRUCTOR 
        ~MAGOS();
};