#pragma once
#include <memory>
#include <vector>
#include <ctime>   // time
#include "../ej1/armas.hpp"
#include "../ej1/armasdecombate.hpp"
#include "../ej1/armasmagicas.hpp"
#include "../ej1/personajes.hpp"
#include "../ej1/clasedecombate.hpp"
#include "../ej1/personajesmagicos.hpp"
#include "../ej1/clasemagica.hpp"
#include "../ej1/clasemagos.hpp"
#include "../ej1/personajesdecombate.hpp"
#include "../ej1/claseguerreros.hpp"
#include "funcionesauxiliares.hpp"


class PersonajeFactory {
    public:
        static unique_ptr<ARMAS> CrearArmaAleatoria(bool esMagico);
        static unique_ptr<Personajes> CrearPersonajeAleatorio(bool esMago, string i);
        static vector<unique_ptr<Personajes>> CrearPersonajesConArmas();
};

