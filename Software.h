#include "Material.h"
#include <string>
#include <iostream>
using namespace std;
class Software : public Material
{
    public:
        Software();
        Software(int ver, string sO,int idM,string titulo);
        void setVersion(int ver);
        int getVersion();
        void setSO(string sO);
        string getSO();
        void muestraDatos();
        int cantidadDiasPrestamo();
    private:
        int version;
        string  so;
};

Software::Software() :Material()
{
    version=0;
    so="";
}

Software::Software(int ver, string sO,int idM, string titulo) : Material(idM,titulo)
{
    version=ver;
    so=sO;
}

string Software::getSO(){
    return so;
}

int Software::getVersion(){
    return version;
}

void Software::setSO(string sO){
    so=sO;
}

void Software::setVersion(int ver){
    version=ver;
}

int Software::cantidadDiasPrestamo(){
    return 1;
}

void Software::muestraDatos(){
    cout<<idMaterial<<" "<<titulo<<endl<<"SO:"<<so<<endl<<"Version:"<<version<<endl;
}


