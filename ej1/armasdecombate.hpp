#pragma once
#include "clasedecombate.hpp"
enum class MaterialesHacha {HIERRO, DIAMANTE };
enum class TiposLanza {HIERRO, FUEGO, LONGINUS};
enum class TiposEspada {GRIFFINDOR, EXCALIBUR, SABLE_LASER, KATANA};
enum class MaterialesGarrote {MADERA, METAL};

class HachaSimple: public ItemCombate{
    private:
        MaterialesHacha materialHacha;
    
    public:
        HachaSimple(string nomb, size_t power, float filo, Rareza rareza, MaterialesHacha material);
    
        void UsoComun() override;
        float getFilo() override;
        MaterialesHacha getMaterialHacha();
    
        //Ataques especiales
        size_t CortePreciso(); //Si es de diamante ataque mas fuerte 
    
};

class HachaDoble: public ItemCombate{
    private:
        MaterialesHacha MaterialesHachaDoble;
    
    public:
        HachaDoble(string nomb, size_t power, float filo, Rareza rareza, MaterialesHacha material);
    
        void UsoComun() override; // doble que el hacha simple
        float getFilo() override;
        MaterialesHacha getMaterialHacha();
    
        //Ataques especiales
        size_t GolpeBrutal(); //Si es de diamante ataque mas fuerte 
    
};

class Espada: public ItemCombate{
    private:
        TiposEspada tipoEspada;
    
    public:
        Espada(string nomb, size_t power, float filo, Rareza rareza, TiposEspada tipo);
        
        void UsoComun() override;
        float getFilo() override;
        TiposEspada getTipoEspada();

        //Ataque Especial
        size_t InvocacionArturica(); // fuerza divina arturica da mayor potencia de ataque si la espada es tipo excalibur
        size_t FuriaJedi(); // sable laser ataca mas fuerte
        size_t AtaquedeLeon(); //espada de griffindor ataca mas fuerte
        size_t AtaqueSamurai(); // Si tiene una katana
};

class Lanza: public ItemCombate{
    private:
        TiposLanza tipoLanza; 
    
    public:
        Lanza(string nomb, size_t power, float filo, Rareza rareza, TiposLanza tipo);
            
        void UsoComun() override;
        float getFilo() override;
        TiposLanza getTipoLanza();

        //Ataques especiales
        size_t Embestida(); //Si es una de  hierro
        size_t PerforacionDivina(); //Si es una Longinus
        size_t LanzaEnLlamas(); // si es tipo fuego lanza una llamarada

};

class Garrote: public ItemCombate{
    private:
        MaterialesGarrote materialHacha;
    
    public:
        Garrote(string nomb, size_t power, float filo, Rareza rareza, MaterialesGarrote material);
    
        void UsoComun() override;
        float getFilo() override;
        MaterialesGarrote getMaterialGarrote();
    
        //Ataques especiales
        size_t AplastamientoBrutal(); // si el garrote es de metal el efecto es mayor
    
};
