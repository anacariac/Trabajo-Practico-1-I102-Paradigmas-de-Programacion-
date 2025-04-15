#pragma once
#include "claseguerreros.hpp"
enum class TipoBarbaro {OGRO, TITAN, CICLOPE};
enum class TipoCaballero {ZODIACO, DE_ARTURO};

class Barbaro: public GUERREROS{
    private:
        TipoBarbaro tipoBarbaro;
    
    public:
        Barbaro(string nomb, int hp, size_t fuerza, size_t resistencia, vector<unique_ptr<ARMAS>> armas, TipoBarbaro TipoBarbaro);

        void Atacar() override;
        void Descansar() override;
        void UsarArma() override;
        void MostrarEstado() override;

        size_t AplastamientoColosal(); // usa toda su fuerza
};

class Paladin: public GUERREROS{
    private:
        bool bendecido;
    
    public:
        Paladin(string nomb, int hp, size_t fuerza, size_t resistencia, vector<unique_ptr<ARMAS>> armas,bool bendecido);

        void Atacar() override;
        void Descansar() override;
        void UsarArma() override;
        void MostrarEstado() override;

        size_t AyudaDivina(); // Si esta bendecido una ayuda celestial hace que aumente su fuerza
};

class Caballero: public GUERREROS{
    private:
        TipoCaballero tipoCaballero;
    
    public:
        Caballero(string nomb, int hp, size_t fuerza, size_t resistencia, vector<unique_ptr<ARMAS>> armas, TipoCaballero tipoCaballero);

        void Atacar() override;
        void Descansar() override;
        void UsarArma() override;
        void MostrarEstado() override;

        size_t ShakaDeVirgo(); // Ayuda del caballero de oro mas fuerte si es que sos un caballero del zodiaco
        size_t SantoGrial(); // Te encontras con el santo grial si sos un caballero de la mesa redonda y te da mas fuerza

};

class Mercenario: public GUERREROS{
    private:
        int oro;
    
    public:
        Mercenario(string nomb, int hp, size_t fuerza, size_t resistencia, vector<unique_ptr<ARMAS>> armas, int oro);

        void Atacar() override;
        void Descansar() override;
        void UsarArma() override;
        void MostrarEstado() override;

        void RecolectarBotin(); //aumenta el oro
};

class Gladiador: public GUERREROS{
    private:
        bool enArena;
    
    public:
        Gladiador(string nomb, int hp, size_t fuerza, size_t resistencia, vector<unique_ptr<ARMAS>> armas, bool arena);

        void Atacar() override;
        void Descansar() override;
        void UsarArma() override;
        void MostrarEstado() override;

        size_t EnArena(); // Si el gladiador se encuentra en la arena es mejor en el ataque
};
