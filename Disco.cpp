#include "Disco.h"
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
    cout<<idMaterial<<" "<<titulo<<" "<<genero<<" "<<duration<<endl;
}
