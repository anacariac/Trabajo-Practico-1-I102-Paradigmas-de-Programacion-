#pragma once
#include <string>
using namespace std;

class Personajes{
    public:
    virtual string getNombre() =0;
    virtual string getTipo() =0;
    virtual void AgregarArma() =0;
    virtual void QuitarArma()=0;
    
    virtual ~Personajes();
};