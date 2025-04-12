#pragma once
#include "clasemagos.hpp"
enum class TipoBrujo {MAGIA_BLANCA, MAGIA_NEGRA};
enum class TipoHechicero {ANIMAGOS, MORTIFAGOS, ELITE};

class Hechicero: public MAGOS{
    private:
        TipoHechicero tipoHechicero;

    public:
        Hechicero(string nomb, string tipo, size_t nivel, size_t mana, vector<shared_ptr<ARMAS>> armas, TipoHechicero tipoHechicero);

        void Atacar();
        void Meditar(); // Recupera maná
    //  void Defender();
        void UsarArma();
        void MostrarEstado();
        size_t Cambiaforma(); // si sos un animago podes transformarte en hombre lobo y atacar con mas fuerza
        size_t MaldicionIlimitada();// Si sos un mortifago o un hechicero de elite 
};

class Brujo: public MAGOS{
    private:
        TipoBrujo tipoBrujo;

    public:
        Brujo(string nomb, string tipo, size_t nivel, size_t mana, vector<shared_ptr<ARMAS>> armas, TipoBrujo tipoBrujo);

        void Atacar();
        void Meditar(); // Recupera maná
    //  void Defender();
        void UsarArma();
        void MostrarEstado();
        size_t LlamadoAquelarre(); // Tu aquelarre te asiste 
};

class Conjurador: public MAGOS{
    private:
        TipoBrujo tipoConjurador;

    public:
        Conjurador(string nomb, string tipo, size_t nivel, size_t mana, vector<shared_ptr<ARMAS>> armas, TipoBrujo tipoConjurador);

        void Atacar();
        void Meditar(); // Recupera maná
    //  void Defender();
        void UsarArma();
        void MostrarEstado();
        size_t InvocacionBestiasProtectoras();
};

class Nigromante: public MAGOS{
    private:
        size_t cantAlmas;

    public:
        Nigromante(string nomb, string tipo, size_t nivel, size_t mana, vector<shared_ptr<ARMAS>> armas, size_t almas);

        void Atacar();
        void Meditar(); // Recupera maná
    //  void Defender();
        void UsarArma();
        void MostrarEstado();
        size_t EjercitodeAlmas();
};

