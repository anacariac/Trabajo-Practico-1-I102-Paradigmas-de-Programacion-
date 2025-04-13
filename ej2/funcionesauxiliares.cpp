#include <cstdlib>
#include "funcionesauxiliares.hpp"

//RAREZA
Rareza RandomRareza() {
    int r = rand() % 3;
    return static_cast<Rareza>(r);
}

// TIPOS DE PERSONAJES MÁGICOS Y GUERREROS
TipoBrujo RandomTipoBrujo() {
    return static_cast<TipoBrujo>(rand() % 2); // MAGIA_BLANCA, MAGIA_NEGRA
}

TipoHechicero RandomTipoHechicero() {
    return static_cast<TipoHechicero>(rand() % 3); // ANIMAGOS, MORTIFAGOS, ELITE
}

TipoBarbaro RandomTipoBarbaro() {
    return static_cast<TipoBarbaro>(rand() % 3); // OGRO, TITAN, CICLOPE
}

TipoCaballero RandomTipoCaballero() {
    return static_cast<TipoCaballero>(rand() % 2); // ZODIACO, DE_ARTURO
}

// TIPOS DE ARMAS MÁGICAS
TiposPocion RandomTipoPocion() {
    return static_cast<TiposPocion>(rand() % 2); // CURACION, PODER
}

MaterialBaston RandomMaterialBaston() {
    return static_cast<MaterialBaston>(rand() % 3); // LUZ, MARFIL, SAUCO
}

MaterialAmuleto RandomMaterialAmuleto() {
    return static_cast<MaterialAmuleto>(rand() % 3); // RUBI, HUESO, JADE
}

TiposHechizos RandomTipoHechizo() {
    return static_cast<TiposHechizos>(rand() % 2); // ENCANTADOR, DESEO
}

// TIPOS DE ARMAS DE COMBATE
MaterialesHacha RandomMaterialHacha() {
    return static_cast<MaterialesHacha>(rand() % 2); // HIERRO, DIAMANTE
}

TiposLanza RandomTipoLanza() {
    return static_cast<TiposLanza>(rand() % 3); // HIERRO, FUEGO, LONGINUS
}

TiposEspada RandomTipoEspada() {
    return static_cast<TiposEspada>(rand() % 4); // GRIFFINDOR, EXCALIBUR, SABLE_LASER, KATANA
}

MaterialesGarrote RandomMaterialGarrote() {
    return static_cast<MaterialesGarrote>(rand() % 2); // MADERA, METAL
}