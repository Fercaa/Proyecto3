#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
#include <iostream>
using namespace std;
class Material
{
    public:
        Material();
        Material(int idM,string title);
        virtual void muestraDatos()=0;
        virtual int cantidadDiasPrestamo()=0;
        void setidMaterial(int idM);
        int getidMaterial();
        void setTitulo(string title);
        string getTitulo();
    protected:
        int idMaterial;
        string titulo;
};

#endif // MATERIAL_H
