#pragma once
#include "armas.hpp"
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Personajes{
    public:
    virtual string getNombre() =0;
    virtual string getTipo() =0;
    virtual size_t getHP() = 0;
    virtual void setHP(int nuevohp) = 0;
    virtual void Daño(size_t cant) = 0;
    virtual void AgregarArma(unique_ptr<ARMAS> arma) =0;
    virtual const vector<unique_ptr<ARMAS>>& getArmas() = 0;
    virtual void QuitarArma(unique_ptr<ARMAS> arma)=0;
    virtual void UsarArma()=0;
    
    virtual ~Personajes() {};
};