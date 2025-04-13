#include <iostream>
#include <memory>
#include <vector>
#include "armasmagicas.hpp"
#include "armasdecombate.hpp"
#include "personajesdecombate.hpp"
#include "personajesmagicos.hpp"
/* 
int main(){
    // Crear armas mágicas y físicas
    shared_ptr<ARMAS> pocion = make_shared<Pocion>("Poción de fuego", 20, Rareza::RARO, TiposPocion::CURACION);
    shared_ptr<ARMAS> baston = make_shared<Baston>("Bastón de trueno", 30, Rareza::COMUN, MaterialBaston::SAUCO);
    shared_ptr<ARMAS> espada = make_shared<Espada>("Espada del destino", 35, 1.2f, Rareza::LEGENDARIO,TiposEspada::KATANA);
    shared_ptr<ARMAS> hacha = make_shared<HachaSimple>("Hacha de batalla", 40, 2.5f, Rareza::COMUN, MaterialesHacha::HIERRO);

    // === MAGOS ===
    Hechicero hechicero("Merlín", "Hechicero", 10, 100, {baston, pocion}, TipoHechicero::ELITE);
    Brujo brujo("Morgana", "Brujo", 9, 90, {pocion}, TipoBrujo::MAGIA_NEGRA);
    Nigromante nigro("Necros", "Nigromante", 8, 80, {baston}, 5);

    // === GUERREROS ===
    Paladin paladin("Arturo", "Paladin", 20, 15, {espada}, true);
    Barbaro barbaro("Krug", "Barbaro", 25, 10, {hacha}, TipoBarbaro::OGRO);
    Caballero cab("Seiya", "Caballero", 18, 20, {espada}, TipoCaballero::ZODIACO);

    // === PRUEBAS ===
    cout << "\n--- MAGOS ---\n" << endl;

    hechicero.MostrarEstado();
    hechicero.UsarArma();
    hechicero.Atacar();
    hechicero.Meditar();

    cout << endl;

    brujo.MostrarEstado();
    brujo.UsarArma();
    brujo.Atacar();
    brujo.Meditar();

    cout << endl;

    nigro.MostrarEstado();
    nigro.UsarArma();
    nigro.Atacar();
    nigro.Meditar();

    cout << "\n--- GUERREROS ---\n" << endl;

    paladin.MostrarEstado();
    paladin.UsarArma();
    paladin.Atacar();
    paladin.Descansar();

    cout << endl;

    barbaro.MostrarEstado();
    barbaro.UsarArma();
    barbaro.Atacar();
    barbaro.Descansar();

    cout << endl;

    cab.MostrarEstado();
    cab.UsarArma();
    cab.Atacar();
    cab.Descansar();

    cout << "\n--- FIN DE PRUEBA ---" << endl;
    return 0;
}
*/