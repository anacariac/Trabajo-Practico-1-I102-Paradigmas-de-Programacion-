#include "personajefactory.hpp"
#include <iostream>

shared_ptr<ARMAS> PersonajeFactory::CrearArmaAleatoria(bool esMagico) {
    if(esMagico){
        int r = rand() % 4;
    switch (r) {
        case 0:
            return make_shared<Baston>("Baton Aleatorio",20 + rand() % 10, RandomRareza(), RandomMaterialBaston());
        case 1:
            return make_shared<Pocion>("Pocion Aleatoria", 25 + rand() % 5, RandomRareza(), RandomTipoPocion() );
        case 2:
            return make_shared<Amuleto>("Amuleto Aleatorio", 10 + rand() % 5, RandomRareza(), RandomMaterialAmuleto());
        case 3:
            return make_shared<LibroHechizos>( "Libro Aleatorio", 15 + rand() % 5, RandomRareza(), RandomTipoHechizo());
        default:
            throw std::runtime_error("Valor fuera de rango en switch");
        }
    }else{
        int r = rand() % 5;
        switch (r) {
            case 0:
                return make_shared<Espada>( "Espada Aleatoria", 20 + rand() % 10, 5.0f + (rand() % 10) / 10.0f, RandomRareza(), RandomTipoEspada());
            case 1:
                return make_shared<HachaSimple>( "Hacha Simple Aleatoria", 25 + rand() % 5, 4.0f + (rand() % 10) / 10.0f, RandomRareza(), RandomMaterialHacha());
            case 2:
                return make_shared<HachaDoble>( "Hacha Doble Aleatoria", 30 + rand() % 5, 6.0f + (rand() % 10) / 10.0f, RandomRareza(), RandomMaterialHacha());
            case 3:
                return make_shared<Lanza>("Lanza Aleatoria", 15 + rand() % 5, 3.0f + (rand() % 4), RandomRareza(), RandomTipoLanza());
            case 4:
                return make_shared<Garrote>("Garrote Aleatorio", 15 + rand() % 5, 0, RandomRareza(), RandomMaterialGarrote()); // El garrote no tiene filo
            default:
                throw std::runtime_error("Valor fuera de rango en switch");
        }
    }
}

shared_ptr<Personajes> PersonajeFactory::CrearPersonajeAleatorio(bool esMago, string i) {
    vector<shared_ptr<ARMAS>> armas; // vacío
    if (esMago) {
        int r = rand() % 4;
    switch (r) {
        case 0:
            return make_shared<Brujo>("Brujo Random" + i, "Brujo", 1 + rand() % 5, 40 + rand() % 30,  armas, RandomTipoBrujo());
        case 1:
            return make_shared<Hechicero>("Hechicero Random" + i, "Hechicero Elemental", 1 + rand() % 5, 40 + rand() % 30,  armas, RandomTipoHechicero());
        case 2:
            return make_shared<Conjurador>("Conjurador Random" + i, "Conjurador", 1 + rand() % 5, 40 + rand() % 30,  armas, RandomTipoBrujo());
        case 3:
            return make_shared<Nigromante>("Nigromante Random" + i, "Nigromante", 1 + rand() % 5, 40 + rand() % 30,  armas, rand() % 5);
        default:
            throw std::runtime_error("Valor fuera de rango en switch");
        }
    } else {
        int r = rand() % 5;
        switch (r) {
            case 0:
                return make_shared<Caballero>("Caballero Random" + i, "Caballero", 20 + rand() % 10, 40 + rand() % 30,  armas, RandomTipoCaballero());
            case 1:
                return make_shared<Paladin>("Paladin Random" + i, "Paladin Bendecido",30 + rand() % 10, 40 + rand() % 30,  armas, true);
            case 2:
                return make_shared<Mercenario>("Mercenario Random" + i, "Mercenario", 25 + rand() % 10, 35 + rand() % 30,  armas, 10 + rand() % 5);
            case 3:
                return make_shared<Barbaro>("Barbaro Random" + i, "Barbaro", 15 + rand() % 10, 20 + rand() % 30,  armas, RandomTipoBarbaro());
            case 4:
                return make_shared<Gladiador>("Gladiador Random" + i, "Gladiador en Arena",30 + rand() % 10, 40 + rand() % 30,  armas, true);
            default:
                throw std::runtime_error("Valor fuera de rango en switch");
            }
    }
}

vector<shared_ptr<Personajes>> PersonajeFactory::CrearPersonajesConArmas() {
    srand(time(nullptr));
    
    int cantMagos = 3 + rand() % 5; // 3 a 7
    int cantGuerreros = 3 + rand() % 5; // 3 a 7

    vector<shared_ptr<Personajes>> personajes;

    for (int i = 0; i < cantMagos; ++i) {
        auto mago = CrearPersonajeAleatorio(true, to_string(i+1));
        int armas = rand() % 3; // 0 a 2
        for (int j = 0; j < armas; ++j) {
            mago->AgregarArma(CrearArmaAleatoria(rand() % 2));
        }
        personajes.push_back(mago);
    }

    for (int i = 0; i < cantGuerreros; ++i) {
        auto guerrero = CrearPersonajeAleatorio(false,to_string(i+1));
        int armas = rand() % 3;
        for (int j = 0; j < armas; ++j) {
            guerrero->AgregarArma(CrearArmaAleatoria(rand() % 2));
        }
        personajes.push_back(guerrero);
    }

    return personajes;
}