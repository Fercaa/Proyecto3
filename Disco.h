#include "Material.h"
#include <string>
#include <iostream>
using namespace std;
class Disco : public Material
{
    public:
        Disco();
        Disco(int dur, string gen, int idM, string titulo);
        void setDuration(int dur);
        int getDuration();
        void setGenero(string gen);
        string getGenero();
        void muestraDatos();
        int cantidadDiasPrestamo();
    protected:

    private:
        int duration;
        string genero;
};

Disco::Disco():Material()
{
    genero="";
    duration=0;
}

Disco::Disco(int dur, string gen, int idM, string titulo): Material(idM,titulo)
{
    genero= gen;
    duration=dur;
}

void Disco::setDuration(int dur){
    duration=dur;
}

void Disco::setGenero(string gen){
    genero=gen;
}

int Disco::getDuration(){
    return duration;
}

string Disco::getGenero(){
    return genero;
}

int Disco::cantidadDiasPrestamo(){
    return 2;
}

void Disco::muestraDatos(){
    cout<<idMaterial<<" "<<titulo<<endl<<"Genero:"<<genero<<endl<<"Duracion:"<<duration<<endl;
}


