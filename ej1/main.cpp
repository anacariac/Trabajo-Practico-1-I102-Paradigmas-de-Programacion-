#include <iostream>
#include <memory>
#include <vector>
#include "armasmagicas.hpp"
#include "armasdecombate.hpp"
#include "personajesdecombate.hpp"
#include "personajesmagicos.hpp"
/* 
int main(){
       // === CREACIÓN DE ARMAS ===
auto pocion = make_unique<Pocion>("Poción de fuego", 20, Rareza::RARO, TiposPocion::CURACION);
auto baston = make_unique<Baston>("Bastón de trueno", 30, Rareza::COMUN, MaterialBaston::SAUCO);
auto espada = make_unique<Espada>("Espada del destino", 35, 1.2f, Rareza::LEGENDARIO, TiposEspada::KATANA);
auto hacha  = make_unique<HachaSimple>("Hacha de batalla", 40, 2.5f, Rareza::COMUN, MaterialesHacha::HIERRO);

// === CLONAR ARMAS PARA NO COMPARTIR UNIQUE_PTR ===
auto pocion2 = make_unique<Pocion>(*pocion); // para Morgana
auto baston2 = make_unique<Baston>(*baston); // para Necros
auto espada2 = make_unique<Espada>(*espada); // para Seiya

// === CREACIÓN DE PERSONAJES ===
vector<unique_ptr<ARMAS>> armas_hechicero;
armas_hechicero.push_back(move(baston));
armas_hechicero.push_back(move(pocion));
auto hechicero = make_unique<Hechicero>("Merlín", 10, 100, 30, move(armas_hechicero), TipoHechicero::ELITE);

vector<unique_ptr<ARMAS>> armas_brujo;
armas_brujo.push_back(move(pocion2));
auto brujo = make_unique<Brujo>("Morgana", 9, 90, 30, move(armas_brujo), TipoBrujo::MAGIA_NEGRA);

vector<unique_ptr<ARMAS>> armas_nigro;
armas_nigro.push_back(move(baston2));
auto nigro = make_unique<Nigromante>("Necros", 8, 80, 30, move(armas_nigro), 5);

vector<unique_ptr<ARMAS>> armas_paladin;
armas_paladin.push_back(move(espada));
auto paladin = make_unique<Paladin>("Arturo", 20, 15, 30, move(armas_paladin), true);

vector<unique_ptr<ARMAS>> armas_barbaro;
armas_barbaro.push_back(move(hacha));
auto barbaro = make_unique<Barbaro>("Krug", 25, 10, 30, move(armas_barbaro), TipoBarbaro::OGRO);

vector<unique_ptr<ARMAS>> armas_cab;
armas_cab.push_back(move(espada2));
auto cab = make_unique<Caballero>("Seiya", 18, 20, 30, move(armas_cab), TipoCaballero::ZODIACO);

// === VECTOR DE PERSONAJES (MOVER UNICOS) ===
vector<unique_ptr<Personajes>> personajes;
personajes.push_back(move(hechicero));
personajes.push_back(move(brujo));
personajes.push_back(move(nigro));
personajes.push_back(move(paladin));
personajes.push_back(move(barbaro));
personajes.push_back(move(cab));

cout << "\n=== PRUEBAS DE PERSONAJES ===\n" << endl;

for (auto& personaje : personajes) {
    cout << "Nombre: " << personaje->getNombre() << endl;
    cout << "Tipo: " << personaje->getTipo() << endl;
    cout << "HP: " << personaje->getHP() << endl;
    cout << "Armas:\n";
    if ((personaje->getArmas()).empty()) {
        cout << "Ninguna" << endl;
    }
    for (const auto& arma : personaje->getArmas()) {
        cout << arma->getNombre() << " -> " << arma->getTipo() << endl;
    }
    cout << "--------------------------\n";
}

cout << "\n=== FIN DE PRUEBA ===" << endl;
return 0;
}*/