#include "personajefactory.hpp"
#include <iostream>

unique_ptr<ARMAS> PersonajeFactory::CrearArmaAleatoria(bool esMagico) {
    if(esMagico){
        int r = rand() % 4;
    switch (r) {
        case 0:
            return make_unique<Baston>("Baton Aleatorio",20 + rand() % 10, RandomRareza(), RandomMaterialBaston());
        case 1:
            return make_unique<Pocion>("Pocion Aleatoria", 25 + rand() % 5, RandomRareza(), RandomTipoPocion() );
        case 2:
            return make_unique<Amuleto>("Amuleto Aleatorio", 10 + rand() % 5, RandomRareza(), RandomMaterialAmuleto());
        case 3:
            return make_unique<LibroHechizos>( "Libro Aleatorio", 15 + rand() % 5, RandomRareza(), RandomTipoHechizo());
        default:
            throw runtime_error("Valor fuera de rango en switch");
        }
    }else{
        int r = rand() % 5;
        switch (r) {
            case 0:
                return make_unique<Espada>( "Espada Aleatoria", 20 + rand() % 10, 5.0f + (rand() % 10) / 10.0f, RandomRareza(), RandomTipoEspada());
            case 1:
                return make_unique<HachaSimple>( "Hacha Simple Aleatoria", 25 + rand() % 5, 4.0f + (rand() % 10) / 10.0f, RandomRareza(), RandomMaterialHacha());
            case 2:
                return make_unique<HachaDoble>( "Hacha Doble Aleatoria", 30 + rand() % 5, 6.0f + (rand() % 10) / 10.0f, RandomRareza(), RandomMaterialHacha());
            case 3:
                return make_unique<Lanza>("Lanza Aleatoria", 15 + rand() % 5, 3.0f + (rand() % 4), RandomRareza(), RandomTipoLanza());
            case 4:
                return make_unique<Garrote>("Garrote Aleatorio", 15 + rand() % 5, 0, RandomRareza(), RandomMaterialGarrote()); // El garrote no tiene filo
            default:
                throw runtime_error("Valor fuera de rango en switch");
        }
    }
}

unique_ptr<Personajes> PersonajeFactory::CrearPersonajeAleatorio(bool esMago, string i) {
    vector<unique_ptr<ARMAS>> armas; // vacío
    if (esMago) {
        int r = rand() % 4;
    switch (r) {
        case 0:
            return make_unique<Brujo>("Brujo Random " + i, 100, 1 + rand() % 5, 40 + rand() % 30,  move(armas), RandomTipoBrujo());
        case 1:
            return make_unique<Hechicero>("Hechicero Random " + i, 100, 1 + rand() % 5, 40 + rand() % 30,  move(armas), RandomTipoHechicero());
        case 2:
            return make_unique<Conjurador>("Conjurador Random " + i, 100, 1 + rand() % 5, 40 + rand() % 30,  move(armas), RandomTipoBrujo());
        case 3:
            return make_unique<Nigromante>("Nigromante Random " + i, 100, 1 + rand() % 5, 40 + rand() % 30,  move(armas), rand() % 5);
        default:
            throw runtime_error("Valor fuera de rango en switch");
        }
    } else {
        int r = rand() % 5;
        switch (r) {
            case 0:
                return make_unique<Caballero>("Caballero Random " + i, 100, 20 + rand() % 10, 40 + rand() % 30,  move(armas), RandomTipoCaballero());
            case 1:
                return make_unique<Paladin>("Paladin Random " + i, 100, 30 + rand() % 10, 40 + rand() % 30,  move(armas), true);
            case 2:
                return make_unique<Mercenario>("Mercenario Random " + i, 100, 25 + rand() % 10, 35 + rand() % 30,  move(armas), 10 + rand() % 5);
            case 3:
                return make_unique<Barbaro>("Barbaro Random " + i, 100, 15 + rand() % 10, 20 + rand() % 30,  move(armas), RandomTipoBarbaro());
            case 4:
                return make_unique<Gladiador>("Gladiador Random " + i, 100, 30 + rand() % 10, 40 + rand() % 30,  move(armas), true);
            default:
                throw runtime_error("Valor fuera de rango en switch");
            }
    }
}

vector<unique_ptr<Personajes>> PersonajeFactory::CrearPersonajesConArmas() {
    
    int cantMagos = 3 + rand() % 5; // 3 a 7
    int cantGuerreros = 3 + rand() % 5; // 3 a 7

    vector<unique_ptr<Personajes>> personajes;

    for (int i = 0; i < cantMagos; ++i) {
        unique_ptr<Personajes> mago = CrearPersonajeAleatorio(true, to_string(i+1));
        int armas = rand() % 3; // 0 a 2
        for (int j = 0; j < armas; ++j) {
            mago->AgregarArma(CrearArmaAleatoria(rand() % 2));
        }
        personajes.push_back(move(mago));
    }

    for (int i = 0; i < cantGuerreros; ++i) {
        unique_ptr<Personajes> guerrero = CrearPersonajeAleatorio(false,to_string(i+1));
        int armas = rand() % 3;
        for (int j = 0; j < armas; ++j) {
            guerrero->AgregarArma(CrearArmaAleatoria(rand() % 2));
        }
        personajes.push_back(move(guerrero));
    }

    return personajes;
}