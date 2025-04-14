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
    virtual void AgregarArma(shared_ptr<ARMAS> arma) =0;
    virtual vector<shared_ptr<ARMAS>> getArmas() = 0;
    virtual void QuitarArma(shared_ptr<ARMAS> arma)=0;
    virtual void UsarArma()=0;
    
    virtual ~Personajes() {};
};