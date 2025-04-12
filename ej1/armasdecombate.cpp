#include "armasdecombate.hpp"
#include <iostream>

HachaSimple::HachaSimple(string nomb, size_t power, float filoVal, Rareza rareza, MaterialesHacha material): ItemCombate(nomb, power, filoVal, rareza), materialHacha(material) {}

void HachaSimple::UsoComun() {
    cout << "Usas el hacha simple " << nombre << " causando " << getPowerModificado() << " de daño." << endl;
}

float HachaSimple::getFilo() {return filo;}

MaterialesHacha HachaSimple::getMaterialHacha() {return materialHacha;}

size_t HachaSimple::CortePreciso() {
    if (materialHacha == MaterialesHacha::DIAMANTE) {
        cout << "¡Corte preciso con filo de diamante! Ataque crítico." << endl;
        return power + 20;
    } else {
        cout << "Corte preciso con hacha de hierro." << endl;
        return power + 5;
    }
}

HachaDoble::HachaDoble(string nomb, size_t power, float filoVal, Rareza rareza, MaterialesHacha material): ItemCombate(nomb, power, filoVal, rareza), MaterialesHachaDoble(material) {}

void HachaDoble::UsoComun() {
    cout << "Usas el hacha doble " << nombre << " y ejecutas un ataque doble que causa "<< getPowerModificado() * 2 << " de daño." << endl;
}

float HachaDoble::getFilo() {return filo;}

MaterialesHacha HachaDoble::getMaterialHacha() {return MaterialesHachaDoble;}

size_t HachaDoble::GolpeBrutal() {
    if (MaterialesHachaDoble == MaterialesHacha::DIAMANTE) {
        cout << "¡Golpe brutal con hacha doble de diamante! Devastador." << endl;
        return power + 30;
    } else {
        cout << "Golpe brutal con hacha doble de hierro." << endl;
        return power + 10;
    }
}

Espada::Espada(string nomb, size_t power, float filo, Rareza rareza, TiposEspada tipo): ItemCombate(nomb, power, filo, rareza), tipoEspada(tipo) {}

void Espada::UsoComun() {
    cout << "Usas la espada " << nombre << " con un filo de " << filo << " y poder de " << power << "." << endl;
}

float Espada::getFilo() {return filo;}

TiposEspada Espada::getTipoEspada() {return tipoEspada;}

size_t Espada::InvocacionArturica() {
    if (tipoEspada == TiposEspada::EXCALIBUR) {
        cout << "Invocación artúrica activada. Excalibur desata su poder legendario." << endl;
        return power + 30;
    }
    cout << "Tu espada no tiene poder artúrico. El ataque es normal." << endl;
    return power;
}

size_t Espada::FuriaJedi() {
    if (tipoEspada == TiposEspada::SABLE_LASER) {
        cout << "Activando Furia Jedi con sable láser. Ataque con velocidad luminosa." << endl;
        return power + 20;
    }
    cout << "No es un sable láser. El ataque es básico." << endl;
    return power;
}

size_t Espada::AtaquedeLeon() {
    if (tipoEspada == TiposEspada::GRIFFINDOR) {
        cout << "Espada de Griffindor libera la valentía del león. Golpe poderoso." << endl;
        return power + 15;
    }
    cout << "Espada sin el coraje de Griffindor. El ataque es normal." << endl;
    return power;
}

size_t Espada::AtaqueSamurai() {
    cout << "Deslizas tu espada con técnica samurái precisa." << endl;
    return power + static_cast<size_t>(filo * 1.5);  // un bonus según el filo
}

Lanza::Lanza(string nomb, size_t power, float filo, Rareza rareza, TiposLanza tipo): ItemCombate(nomb, power, filo, rareza), tipoLanza(tipo) {}

void Lanza::UsoComun() {
    cout << "Usas la lanza " << nombre << " para atacar desde la distancia." << endl;
}

float Lanza::getFilo() {return filo;}

TiposLanza Lanza::getTipoLanza() {return tipoLanza;}

size_t Lanza::Embestida() {
    if (tipoLanza == TiposLanza::HIERRO) {
        cout << "Embestida con lanza de hierro. Ataque con fuerza contundente." << endl;
        return power + 10;
    }
    cout << "La embestida es estándar." << endl;
    return power;
}

size_t Lanza::PerforacionDivina() {
    if (tipoLanza == TiposLanza::LONGINUS) {
        cout << "¡Perforación Divina! La lanza sagrada atraviesa toda defensa." << endl;
        return power + 35;
    }
    cout << "Tu lanza no es la Longinus, el ataque es normal." << endl;
    return power;
}

size_t Lanza::LanzaEnLlamas() {
    if (tipoLanza == TiposLanza::FUEGO) {
        cout << "Lanza en llamas, lanza una llamarada ardiente." << endl;
        return power + 25;
    }
    cout << "Tu lanza no controla fuego." << endl;
    return power;
}

Garrote::Garrote(string nomb, size_t power, float filo, Rareza rareza, MaterialesGarrote material): ItemCombate(nomb, power, filo, rareza), materialHacha(material) {}

void Garrote::UsoComun() {
    cout << "Usas el garrote " << nombre << " para golpear con fuerza bruta." << endl;
}

float Garrote::getFilo() {return filo;}// El garrote no tiene filo por ende siempre es cero

MaterialesGarrote Garrote::getMaterialGarrote() {return materialHacha;}

size_t Garrote::AplastamientoBrutal() {
    if (materialHacha == MaterialesGarrote::METAL) {
        cout << "¡Aplastamiento brutal! El garrote metálico destruye todo a su paso." << endl;
        return power + 20;
    }
    cout << "Golpe contundente, pero sin la fuerza del metal." << endl;
    return power;
}
