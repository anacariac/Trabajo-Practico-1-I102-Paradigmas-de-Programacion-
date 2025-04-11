#include "armasmagicas.hpp"
#include <iostream>

Pocion::Pocion(string nomb, size_t power, Rareza rareza, TiposPocion tipo): ItemMagicos(nomb, power, rareza), tipoPocion(tipo){}

TiposPocion Pocion::getTipoPocion() {return tipoPocion;}

void Pocion::UsoComun() {
    cout << "Usaste la poción " << nombre << ". ";
    size_t efecto = getPowerModificado();

    if (tipoPocion == TiposPocion::CURACION) {
        cout << "Recuperas " << efecto << " puntos de vida." << endl;
    } else {
        cout << "Aumentas tu poder mágico con " << efecto << " puntos más." << endl;
    }
}

size_t Pocion::AtaqueCombinado(string TipoDeArma) {
    size_t efecto = getPowerModificado();
    cout << "Intentas un ataque combinado con un arma de tipo: " << TipoDeArma << "." << endl;

    if (TipoDeArma == "Magico") {
        cout << "¡Ataque combinado exitoso!" << endl;
        return efecto + 10;
    } else {
        cout << "No hay afinidad mágica. El ataque combinado falla parcialmente." << endl;
        return efecto / 2;
    }
}

size_t Pocion::Clonacion() {
    size_t efecto = getPowerModificado();
    cout << "La poción genera un clon mágico. Tu ataque será duplicado." << endl;
    return efecto * 2;
}

size_t Pocion::Amortentia() {
    size_t efecto = getPowerModificado();
    cout << "Hechizo de amor lanzado. El enemigo queda inmovilizado por amor mágico." << endl;
    return efecto + 2;
}

Amuleto::Amuleto(string nomb, size_t power, Rareza rareza, MaterialAmuleto elem): ItemMagicos(nomb, power, rareza), elem(elem) {}

void Amuleto::UsoComun() {
    cout << "Usas el amuleto " << nombre << " hecho de ";
    size_t efecto = getPowerModificado();

    switch (elem) {
        case MaterialAmuleto::JADE:
            cout << "jade. Atrae energías espirituales."<<" Poder: "<< efecto <<endl;
            break;
        case MaterialAmuleto::HUESO:
            cout << "hueso. Vibra con una energía oscura."<<" Poder: "<< efecto <<endl;
            break;
        case MaterialAmuleto::RUBI:
            cout << "rubí. Emite un brillo hipnótico."<<" Poder: "<< efecto <<endl;
            break;
    }
}

MaterialAmuleto Amuleto::getMaterial() {return elem;}

size_t Amuleto::TrianguloJade(string personaje) {
    size_t efecto = getPowerModificado();

    if (elem == MaterialAmuleto::JADE) {
        if (personaje == "Nigromante") {
            cout << "El amuleto de jade brilla intensamente. Espíritus aliados te asisten.\n";
            return efecto + 15;
        } else {
            cout << "El jade forma un escudo espiritual. Te protege de entidades del más allá.\n";
            return efecto;
        }
    } else {
        cout << "El amuleto no es de jade. El hechizo falla.\n";
        return efecto / 2;
    }
}

size_t Amuleto::BuenaSuerte() {
    size_t efecto = getPowerModificado();

    if (elem == MaterialAmuleto::HUESO) {
        cout << "El amuleto de hueso te otorga buena suerte. ¡Tu ataque será potenciado!\n";
        return efecto + 10;
    } else {
        cout << "El amuleto reacciona de forma extraña... pierdes vitalidad.\n";
        return efecto / 2;  
    }
}

size_t Amuleto::Hipnotizar() {
    size_t efecto = getPowerModificado();

    if (elem == MaterialAmuleto::RUBI) {
        cout << "El rubí destella hipnóticamente. El enemigo queda aturdido.\n";
        return efecto + 5;
    } else {
        cout << "El amuleto no tiene poder hipnótico.\n";
        return efecto / 2;
    }
}

Baston::Baston(string nomb, size_t power, Rareza rareza, MaterialBaston elem) : ItemMagicos(nomb, power, rareza), elem(elem) {}

void Baston::UsoComun() {
    cout << "Empuñas el bastón " << nombre << " hecho de ";
    size_t efecto = getPowerModificado();

    switch (elem) {
        case MaterialBaston::LUZ:
            cout << "luz. Irradia energía solar."<<" Poder: "<< efecto <<endl;
            break;
        case MaterialBaston::MARFIL:
            cout << "marfil. Es elegante y poderoso."<<" Poder: "<< efecto <<endl;
            break;
        case MaterialBaston::SAUCO:
            cout << "sauco. Emite un aura misteriosa."<<" Poder: "<< efecto <<endl;
            break;
    }
}

MaterialBaston Baston::getMaterial() {
    return elem;
}

size_t Baston::AtaquedeLuz() {
    size_t efecto = getPowerModificado();

    if (elem == MaterialBaston::LUZ) {
        cout << "El bastón emite una bola de fuego radiante hacia el enemigo.\n";
        return efecto + 20;
    } else {
        cout << "Este bastón no puede canalizar el ataque de luz.\n";
        return efecto / 2;
    }
}

size_t Baston::Letargo() {
    size_t efecto = getPowerModificado();

    if (elem == MaterialBaston::SAUCO) {
        cout << "El bastón de sauco induce un profundo letargo al enemigo. ¡Está dormido!\n";
        return efecto + 10;
    } else {
        cout << "Este bastón no tiene poderes hipnóticos.\n";
        return efecto / 2;
    }
}

size_t Baston::RayoLunar() {
    size_t efecto = getPowerModificado();

    if (elem == MaterialBaston::MARFIL) {
        cout << "El bastón de marfil lanza un rayo lunar cegador. El enemigo no puede ver por un turno.\n";
        return efecto + 5;
    } else {
        cout << "Este bastón no puede invocar la luna.\n";
        return efecto / 2;
    }
}

LibroHechizos::LibroHechizos(string nomb, size_t power, Rareza rareza, TiposHechizos tipo): ItemMagicos(nomb, power, rareza), tipoHechizo(tipo) {}

void LibroHechizos::UsoComun() {
    cout << "Has abierto el libro de hechizos: " << nombre << ". ";
    size_t efecto = getPowerModificado();

    switch (tipoHechizo) {
        case TiposHechizos::ENCANTADOR:
            cout << "Sus páginas brillan con encantamientos antiguos."<<" Poder: "<< efecto <<endl;
            break;
        case TiposHechizos::DESEO:
            cout << "Sus palabras susurran deseos poderosos al lector."<<" Poder: "<< efecto <<endl;
            break;
    }
}

TiposHechizos LibroHechizos::getTipoHechizo() {return tipoHechizo;}

size_t LibroHechizos::FlautistaHamelin() {
    size_t efecto = getPowerModificado();

    if (tipoHechizo == TiposHechizos::ENCANTADOR) {
        cout << "Usas 'El Flautista de Hamelín'. El enemigo cae bajo tu control temporalmente.\n";
        return efecto + 15;
    } else {
        cout << "El hechizo falla parcialmente. El enemigo resiste el control mental.\n";
        return efecto / 2;
    }
}

size_t LibroHechizos::MakeAWish() {
    size_t efecto = getPowerModificado();

    if (tipoHechizo == TiposHechizos::DESEO) {
        cout << "Lanzas un hechizo de deseo. Se manifiesta como una ráfaga de poder arcano.\n";
        return efecto + 20;
    } else {
        cout << "Tu deseo no fue escuchado. El hechizo se disipa.\n";
        return efecto / 2;
    }
}
