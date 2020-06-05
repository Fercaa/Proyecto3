#include "Software.h"

Software::Software() :Material()
{
    version=0;
    so=0;
}

Software::Software(int ver, int sO,int idM, string titulo) : Material(idM,titulo)
{
    version=ver;
    so=sO;
}

int Software::getSO(){
    return so;
}

int Software::getVersion(){
    return version;
}

void Software::setSO(int sO){
    so=sO;
}

void Software::setVersion(int ver){
    version=ver;
}

int Software::cantidadDiasPrestamo(){
    return 1;
}

void Disco::muestraDatos(){
    cout<<idMaterial<<" "<<titulo<<" "<<version<<" "<<so<<endl;
}
