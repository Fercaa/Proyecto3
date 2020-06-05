#include "Libro.h"

Libro::Libro():Material()
{
    autor="";
    numPag=0;
}

Libro::Libro(int nP,string au,int idM, string titulo) :Material(idM,titulo)
{
    autor=au;
    numPag=nP;
}

string Libro::getAutor(){
    return autor;
}

int Libro::getnumPag(){
    return numPag;
}

void Libro::setAutor(string au){
    autor=au;
}

void Libro::setnumPag(int nP){
    numPag=nP;
}

void Libro::cantidadDiasPrestamo(){
    return 7;
}

void Libro::muestraDatos(){
    cout<<idMaterial<<" "<<titulo<<" "<<autor<<" "<<numPag<<endl;
}
