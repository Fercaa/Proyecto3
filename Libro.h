#include "Material.h"
#include <string>
#include <iostream>
using namespace std;
class Libro : public Material
{
    public:
        Libro();
        Libro(int nP, string au, int idM, string titulo);
        void setnumPag(int nP);
        int getnumPag();
        void setAutor(string au);
        string getAutor();
        void muestraDatos();
        int cantidadDiasPrestamo();
    private:
        int numPag;
        string autor;
};

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

int Libro::cantidadDiasPrestamo(){
    return 7;
}

void Libro::muestraDatos(){
    cout<<idMaterial<<" "<<titulo<<endl<<"Autor:"<<autor<<endl<<"Numero de Paginas:"<<numPag<<endl;
}



