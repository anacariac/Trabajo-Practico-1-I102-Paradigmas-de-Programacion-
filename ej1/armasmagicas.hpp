#pragma once
#include "clasemagica.hpp"
enum class TiposPocion {CURACION, PODER};
enum class MaterialBaston {LUZ, MARFIL, SAUCO};
enum class MaterialAmuleto {RUBI, HUESO, JADE};
enum class TiposHechizos {ENCANTADOR, DESEO};

class Pocion: public ItemMagicos{
    private:
        TiposPocion tipo;
    
    public:
        Pocion(string nomb, size_t power,Rareza rareza, TiposPocion tipo);
    
        void UsoComun() override;
        TiposPocion getTipoPocion();
        size_t getPowerModificado();
    
        //Ataques especiales
        size_t AtaqueCombinado(string TipoDeArma); // si existe otra arma en el juego se fija su afinidad para que un ataque conjunto sea usado
        size_t Clonacion(); // crea un doble que hace que el ataque en esa ronda sea el doble
        size_t Amortentia(); // Enamora al enemigo y lo deja inmovilizado
    
    };

class Amuleto: public ItemMagicos{
    private:
        MaterialAmuleto elem;
    
    public:
        Amuleto(string nomb, size_t power,Rareza rareza, MaterialAmuleto elem);
    
        void UsoComun() override;
        MaterialAmuleto getMaterial();
    
        //Ataques especiales
        size_t TrianguloJade(string personaje); //Si sos un nigromante te permite ver espiritus que te ayudan, caso contrario se usa como collar que te protege de espiritus
        size_t BuenaSuerte(); // Si tu amuleto es de hueso te da buena suerte, caso contrario amuleto maldito perdes HP
        size_t Hipnotizar(); //Si tu amuleto es de rubi podes hipnotizar a tu enemigo
    };

class Baston: public ItemMagicos{
    private:
        MaterialBaston elem;
    
    public:
        Baston(string nomb, size_t power, Rareza rareza, MaterialBaston elem);
    
        void UsoComun() override;
        MaterialBaston getMaterial();
    
        //Ataques especiales
        size_t AtaquedeLuz(); // Si se tiene un baston de luz lanza bola de fuego al enemigo
        size_t Letargo(); // El baston de sauco puede poner a dormir a tus enemigos
        size_t RayoLunar();// El baston de marfil puede lanzar un ataque ciega al enemigo por un turno
    };

class LibroHechizos: public ItemMagicos{
    private:
        TiposHechizos tipo;
    
    public:
        LibroHechizos(string nomb, size_t power,Rareza rareza, TiposPocion tipo);
        
        void UsoComun() override;
        TiposHechizos getTipoHechizo();

        //Ataques especiales
        size_t FlautistaHamelin(); //Si el hechizo es tipo encantador toma el control del enemigo
        size_t MakeAWish(); // Si el hechizo es tipo deseo podes
    };